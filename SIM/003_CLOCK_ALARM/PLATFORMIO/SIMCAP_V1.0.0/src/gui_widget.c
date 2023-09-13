/*
# ##############################################################################
# File: gui_widget.c                                                           #
# Project: src                                                                 #
# Created Date: Tuesday, August 29th 2023, 7:31:05 pm                          #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Monday, September 4th 2023, 8:24:09 pm                        #
# Modified By: Zafeer Abbasi                                                   #
# ----------------------------------------------                               #
# Copyright (c) 2023 Zafeer.A                                                  #
# ----------------------------------------------                               #
# HISTORY:                                                                     #
*//**/



/*##############################################################################################################################################*/
/*INCLUDES______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

#include "lvgl.h"
#include "project_clock_alarm.h"
#include "gui_widget.h"
#include "stdlib.h"
#include "examples/lv_examples.h"
#include "stdio.h"

/*##############################################################################################################################################*/
/*GLOBALS_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/



/*##############################################################################################################################################*/
/*DEFINES_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/



/*##############################################################################################################################################*/
/*TYPEDEFS/STRUCTS/ENUMS________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/



/*##############################################################################################################################################*/
/*FUNCTIONS_____________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

/**
 * @brief Create a Roller object
 * 
 * @param parent Parent to place child roller object on
 * @param opts String containing possible options for roller selections
 * @param currVal Default value selection for roller
 * @return lv_obj_t* Pointer to Roller object
 */
lv_obj_t *createRoller(lv_obj_t *parent, const char *opts, int currVal)
{
    /*Create a plain object*/
    lv_obj_t *roller;

    /*Create a style for the main selected option of the roller, i.e. the middle option*/
    static lv_style_t rollerStyle;

    /*Initialize the style, (set to default values)*/
    lv_style_init(&rollerStyle);

    /*Set style text*/
    lv_style_set_text_font(&rollerStyle, &lv_font_montserrat_22);

    /*Create a roller object and assign it to the previous plain object that was created*/
    roller = lv_roller_create(parent);

    /*Set roller options and mode, normal = normal, infinite = infinite scroll*/
    lv_roller_set_options(roller, opts, LV_ROLLER_MODE_NORMAL);

    /*Set visible rows, if chaning this then make sure to adjust line below: lv_obj_set_height(roller, LV_PCT(100))
    lv_roller_set_visible_row_count(roller, 2);

    /*Set the current selected option on the roller*/
    lv_roller_set_selected(roller, currVal, LV_ANIM_ON);

    /*Set height and width of roller*/
    lv_obj_set_height(roller, LV_PCT(100)); //Set hieght of the roller to the height of the container object*/
    lv_obj_set_width(roller, 80);

    /*Add style to the current middle selected option of the roller*/
    lv_obj_add_style(roller, &rollerStyle, LV_PART_SELECTED);

    /*Align roller option text to the left*/
    lv_style_set_text_align(&rollerStyle, LV_TEXT_ALIGN_LEFT);

    return roller;
}

/**
 * @brief Create a Save Btn object
 * 
 * @param parent Parent to place child Save Button on 
 * @param txt Text on the Button
 * @param normal Style of the button Normally
 * @param clicked Style of the Button when clicked
 * @param eventCallBack Callback when the button is pressed
 * @return lv_obj_t* Pointer to 'Save' Button object
 */
lv_obj_t *createSaveBtn(lv_obj_t *parent, const char* txt, lv_style_t *normal, lv_style_t *clicked, lv_event_cb_t eventCallBack)
{
    /*Create Button*/
    lv_obj_t *btnObj = lv_btn_create(parent);

    /*Clear all previous styles*/
    lv_obj_remove_style_all(btnObj);

    /*Add normal style to button when normal*/
    lv_obj_add_style(btnObj, normal, LV_STATE_DEFAULT);

    /*Add clicked style to button when clicked*/
    lv_obj_add_style(btnObj, clicked, LV_STATE_PRESSED);

    /*Create label object on top of button, set text and align*/
    lv_obj_t *label = lv_label_create(btnObj);
    lv_label_set_text(label, txt);
    lv_obj_center(label);

    /*Add callback on the button*/
    lv_obj_add_event_cb(btnObj, eventCallBack, LV_EVENT_CLICKED, NULL);
}

/**
 * @brief Create a Calendar object
 * 
 * @param parent Parent of which to place the Calendar Child on 
 * @param data Calendar Data used to initialize the Calendar
 * @return lv_obj_t* Pointer to Calendar object
 */
lv_obj_t *createCalendar(lv_obj_t *parent, calendarData_t *data)
{
    /*Create Calendar*/
    lv_obj_t *calendar = lv_calendar_create(parent);

    /*Set size and align*/
    lv_obj_set_size(calendar, 220, 220);
    lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 27);
    
    /*Set Calendar year and month preset*/
    lv_calendar_set_showed_date(calendar, data->year, data->month);

    /*Set Calendar date preset*/
    lv_calendar_set_today_date(calendar, data->year, data->month, data->day);

    /*Use drop down for Year/Month header*/
    lv_calendar_header_dropdown_create(calendar);

    /*Add Callback event*/
    lv_obj_add_event_cb(calendar, eventHandlerDateChange, LV_EVENT_VALUE_CHANGED, NULL);

    return calendar;
}

/**
 * @brief Create a Menu object
 * 
 * @param parent Parent of which to place the Menu Child on
 * @param enableRootBtn True, or False, Enable Root Button
 * @param eventCallBack Callback for when Root Button is pressed
 * @return lv_obj_t* Pointer to menu object
 */
lv_obj_t *createMenu(lv_obj_t *parent, bool enableRootBtn, lv_event_cb_t eventCallBack)
{
    /*Create menu object*/
    lv_obj_t *menu = lv_menu_create(parent);

    if(enableRootBtn)
    {
        /*Enable Root Button*/
        lv_menu_set_mode_root_back_btn(menu, LV_MENU_ROOT_BACK_BTN_ENABLED);
    }

    /*Add callback*/
    lv_obj_add_event_cb(menu, eventCallBack, LV_EVENT_CLICKED, (void *)menu);

    return menu;
}

/**
 * @brief Collapse the Drop Down List whenever the screen is tapped
 * 
 * @param gui_element GUI_t member of the main ClockAlarmUI_t object, i.e. gui_inst
 */
void collapseDropDownList(GUI_t *gui_element)
{
    /*Check if theres an active drop down list, if so then delete it*/
    if( gui_element->dropDownList != NULL)
    {
        /*Delte the list object*/
        lv_obj_del(gui_element->dropDownList);

        /*Set the element to NULL*/
        gui_element->dropDownList = NULL;
    }
}

/*EVENT HANDLERS--------------------------------------------------------------------------------------------------------------------------------*/

/**
 * @brief Event Handler for when any of the Time rollers value is changed
 * 
 * @param event lv_event_t event
 */
void eventHandlerTimeRollers(lv_event_t *event)
{
    event_t sig;
    uint8_t rollerVal;
    guiTimeChangeEvent_t timeChangeEvent;

    /*Get event code*/
    lv_event_code_t code = lv_event_get_code(event);

    /*Get Target*/
    lv_obj_t *target = lv_event_get_target(event);

    /*Get User data, in this case its the roller (hour or minute or second)*/
    rollerData_t *rollerData = (rollerData_t *)lv_event_get_user_data(event);

    if( code == LV_EVENT_VALUE_CHANGED )
    {
        char str[3];

        /*Get the current value*/
        lv_roller_get_selected_str(target, str, sizeof(str));

        /*Convert string to value*/
        rollerVal = atoi(str);

        /*Check which roller caused the event (hour or min or sec)*/
        if( rollerData->rollerType == ROLLER_HOUR )
        {
            /*Set the appropriate signal*/
            sig = E_SETTING_CLOCK_HOUR;
        }
        else if( rollerData->rollerType == ROLLER_MIN )
        {
            /*Set appropriate signal*/
            sig = E_SETTING_CLOCK_MIN;
        }
        else if( rollerData->rollerType == ROLLER_SEC )
        {
            /*Set appropriate signal*/
            sig = E_SETTING_CLOCK_SEC;
        }
        else
        {
            sig = E_NONE;
        }

        /*Add signal to the time change event*/
        timeChangeEvent.mainEvent.signal = sig;

        /*Add current roller value as a param to the time change event*/
        timeChangeEvent.param = rollerVal;

        /*Process the event*/
        clockAlarmUIProcessEvent(&clockAlarmUI_inst, &timeChangeEvent.mainEvent);
    }
}

/**
 * @brief Event Handler for when the 'Save Button' is clicked on the Date Page
 * 
 * @param event lv_event_t event
 */
void eventHandlerDateSave(lv_event_t *event)
{
    /*Create Event*/
    guiEvent_t dateSaveEvent;

    /*Get Code*/
    lv_event_code_t code = lv_event_get_code(event);

    if( code == LV_EVENT_CLICKED )
    {
        /*If button was clicked*/

        /*Set event signal*/
        dateSaveEvent.signal = E_DATE_SAVE;

        /*Process event*/
        clockAlarmUIProcessEvent(&clockAlarmUI_inst, &dateSaveEvent);
    }
}

/**
 * @brief Event Handler for whenever the Date Changes
 * 
 * @param event lv_event_t event
 */
void eventHandlerDateChange(lv_event_t *event)
{
    /*Get event code*/
    lv_event_code_t eventCode = lv_event_get_code(event);

    /*Get target, in form of lv_obj_t * and lv_calendar_t * */
    lv_obj_t *calendarObject = lv_event_get_target(event);
    lv_obj_t *btnMatrix = lv_calendar_get_btnmatrix(calendarObject);

    /*Place holders for date and Date Change Event*/
    lv_calendar_date_t date;
    guiDateChangeEvent_t dateChangeEvent;

    if( eventCode == LV_EVENT_VALUE_CHANGED )
    {
        /*If the event was caused by a value being changed*/

        if( lv_calendar_get_pressed_date(calendarObject, &date) )
        {
            /*If the pressed date is valid*/

            /*Get selected button*/
            int currBtn = lv_btnmatrix_get_selected_btn(btnMatrix);
            
            /*Clear the previous selection highlight*/
            lv_btnmatrix_clear_btn_ctrl_all(btnMatrix, LV_BTNMATRIX_CTRL_CUSTOM_2);

            /*Highlight current selected Day*/
            lv_btnmatrix_set_btn_ctrl_all(btnMatrix, LV_BTNMATRIX_CTRL_CUSTOM_2);

            /*Set event signal to send to main event processing function*/
            dateChangeEvent.mainEvent.signal = E_SETTING_DATE_CHANGE;

            /*Set event data*/
            dateChangeEvent.date = date.day;
            dateChangeEvent.month = date.month;
            dateChangeEvent.year = date.year;

            /*Send event to main event processing function*/
            clockAlarmUIProcessEvent(&clockAlarmUI_inst, &dateChangeEvent.mainEvent);
        }
    }
}

/**
 * @brief Event Handler when Root Back Button on Settings Page has been pressed
 * 
 * @param event lv_event_t event
 */
void eventHandlerRootBackBtn(lv_event_t *event)
{
    /*Get Target*/
    lv_obj_t *target = lv_event_get_target(event);

    /*Get User data, in this case the pointer to menu object*/
    lv_obj_t *menu = lv_event_get_user_data(event);

    /*Check if target object is rootback button of menu*/
    if( lv_menu_back_btn_is_root(menu, target))
    {
        /*Create an Event and Process it*/
        guiEvent_t event;
        event.signal = E_ROOT_BACK;
        clockAlarmUIProcessEvent(&clockAlarmUI_inst, &event);
    }
}

/**
 * @brief Event Handler for when the screen has been pressed
 * 
 * @param e lv_event_t event
 */
void eventHandlerScreen( lv_event_t * e )
{
    /*Get the event code, for ex, LV_EVENT_CLICKED*/
    lv_event_code_t code = lv_event_get_code(e);
    
    /*Get user data*/
    GUI_t *const gui_element = ( GUI_t *const )lv_event_get_user_data(e);

    /*If the screen is pressed then collapse the dropdown list*/
    if( code == LV_EVENT_PRESSED )
    {
        collapseDropDownList(gui_element);
    }
    else
    {
        LV_LOG_USER("Nothing to collapse\n");
    }
}

/**
 * @brief Event Handler for when the 'Settings' option is selected in the list
 * 
 * @param e lv_event_t event
 */
void eventHandlerDropDownBtnOptionSettings(lv_event_t *e)
{
    /*Get event code*/
    lv_event_code_t code = lv_event_get_code(e);

    /*If code is LV_EVENT_CLICKED then call clockAlarmUIProcessEvent*/
    if( code == LV_EVENT_CLICKED )
    {
        /*Create an event and set its signal to E_SETTING*/
        guiEvent_t event;
        event.signal = E_SETTING; 
        
        /*Process the event of opening the menu after clicking the 'Settings' option from list*/
        clockAlarmUIProcessEvent(&clockAlarmUI_inst, &event);
    }
}

/**
 * @brief Event Handler for when the 'About' option is selected in the list
 * 
 * @param e lv_event_t event
 */
void eventHandlerDropDownBtnOptionAbout(lv_event_t* e)
{
    /*Get event code*/
    lv_event_code_t code = lv_event_get_code(e);
    
    /*Get user data*/
    GUI_t *const gui_element = (GUI_t *const)lv_event_get_user_data(e);
    
    /*Delete dropdown list*/
    collapseDropDownList(gui_element);
    
    if (code == LV_EVENT_CLICKED) 
    {
        /*Create a msgbox with the 'about' info on it*/
        lv_obj_t* mbox1 = lv_msgbox_create(NULL, "About", "Clock version: 1.0\nBy Zafeer Abbasi\nPowered by LVGL v8.3", NULL, true);
        
        /*Center the msgbox*/
        lv_obj_center(mbox1);
    }
}

/**
 * @brief Create a new list everytime the drop down btn is pressed
 * 
 * @param e lv_event_t event
 */
void eventHandlerDropDownBtn(lv_event_t *e)
{
    /*Get event code*/
    lv_event_code_t code = lv_event_get_code(e);

    /*Get user data*/
    GUI_t *const gui_element = (GUI_t *const)lv_event_get_user_data(e);

    /*Create a btn place holder*/
    lv_obj_t *btn;

    /*If the drop down button is pressed, then create a drop down button*/
    if( code == LV_EVENT_CLICKED )
    {
        /*Create List, dropdown doesnt work since its too hard to implement a callback per list option*/
        gui_element->dropDownList = lv_list_create(gui_element->screen);

        /*Create a list button and store the lv_obj_t pointer in the btn var so we can add a cb to it's address*/
        btn = lv_list_add_btn(gui_element->dropDownList, LV_SYMBOL_SETTINGS, "Settings");

        /*Add a cb to the btn pointer which contains the address of the 'Settings' button*/
        lv_obj_add_event_cb(btn, eventHandlerDropDownBtnOptionSettings, LV_EVENT_CLICKED, (void *)gui_element);

        /*Create a list button - 'About' and store the address in the temp btn var*/
        btn = lv_list_add_btn(gui_element->dropDownList, LV_SYMBOL_FILE, "About");
        
        /*Add a cb to the btn pointer which contains address of the 'About' button*/
        lv_obj_add_event_cb(btn, eventHandlerDropDownBtnOptionAbout, LV_EVENT_CLICKED, (void *)gui_element);

        /*Set drop down list height*/
        lv_obj_set_height(gui_element->dropDownList, LV_SIZE_CONTENT);

        /*Align drop down list*/
        lv_obj_align(gui_element->dropDownList, LV_ALIGN_TOP_RIGHT, 0, 0);
    }
    
}
