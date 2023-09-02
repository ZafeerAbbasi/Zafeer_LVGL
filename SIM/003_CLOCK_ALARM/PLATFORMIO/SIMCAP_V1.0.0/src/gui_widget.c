/*
# ##############################################################################
# File: gui_widget.c                                                           #
# Project: src                                                                 #
# Created Date: Tuesday, August 29th 2023, 7:31:05 pm                          #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Saturday, September 2nd 2023, 6:17:12 am                      #
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
        UI_Event_t event;
        event.sig = E_SETTING; 
        
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
