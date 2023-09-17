/*
# ##############################################################################
# File: gui.c                                                                  #
# Project: src                                                                 #
# Created Date: Monday, August 21st 2023, 4:46:40 am                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Monday, September 4th 2023, 8:10:48 pm                        #
# Modified By: Zafeer Abbasi                                                   #
# ----------------------------------------------                               #
# Copyright (c) 2023 Zafeer.A                                                  #
# ----------------------------------------------                               #
# HISTORY:                                                                     #
*//**/
/*This File is about all the GUI Implemnetation excluding widgets*/



/*##############################################################################################################################################*/
/*INCLUDES______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

#include "gui.h"
#include "lvgl.h"
#include "project_clock_alarm.h"
#include "gui_widget.h"
#include <stdio.h>
#include "examples/lv_examples.h"

/*##############################################################################################################################################*/
/*GLOBALS_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

static void guiCreateTimeDateHeader(GUI_t *const gui_element);
static lv_obj_t *createSettingsTimeAlarmRollersRow(lv_obj_t *parent, rollerData_t *rollerHour, rollerData_t *rollerMin, rollerData_t *rollerSec, lv_event_cb_t eventCallBack);
static void createTimeFormatCheckBoxes(lv_obj_t *parent, CheckBoxData_t *CheckBoxData);

/*##############################################################################################################################################*/
/*DEFINES_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

#define CHECK_BOX_INDEX_AM 0
#define CHECK_BOX_INDEX_PM 1

/*##############################################################################################################################################*/
/*TYPEDEFS/STRUCTS/ENUMS________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/



/*##############################################################################################################################################*/
/*FUNCTIONS_____________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

void GUIDisplayCurrentTime( GUI_t *const guiElement, char *const stringTime )
{
    /*Update Clock Time Label*/
    lv_label_set_text( guiElement->clock, stringTime );
}

/**
 * @brief Create a Time Format Check Boxes object
 * 
 * @param parent 
 * @param CheckBoxData 
 */
static void createTimeFormatCheckBoxes(lv_obj_t *parent, CheckBoxData_t *CheckBoxData)
{
    /*Create container on parent param passed into this function*/
    lv_obj_t *container = lv_obj_create(parent);

    /*Set Flex Flow of container to coloumn to add buttons in vertical order*/
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_COLUMN);

    /*Set height and width of container*/
    lv_obj_set_width(container, LV_SIZE_CONTENT);
    lv_obj_set_height(container, LV_SIZE_CONTENT);

    /*Add event callback*/
    lv_obj_add_event_cb(container, eventHandlerSettingsTimeFormatCheckBoxs, LV_EVENT_CLICKED, CheckBoxData);

    /*Create CheckBoxes*/
    createCheckBox(container, "AM", NULL, NULL); /*Created first, thus ID for this Btn = 0*/
    createCheckBox(container, "PM", NULL, NULL); /*Created second, thus ID for this Btn = 1*/

    /*Set Checked State for the Button depending on Time format */
    lv_obj_add_state(lv_obj_get_child(container, CheckBoxData->CheckBoxBoxIndex), LV_STATE_CHECKED);

}

/**
 * @brief Create a Row of Rollers for Settings Page Time and Alarm
 * 
 * @param parent Parent to which to place the Roller objects on
 * @param rollerHour Pointer to Hour rollerData_t struct
 * @param rollerMin Pointer to Minute rollerData_t struct
 * @param rollerSec Pointer to Second rollerData_t struct
 * @param eventCallBack eventCallBack Roller Event Callback
 * @return lv_obj_t* Pointer to Parent Row object
 */
static lv_obj_t *createSettingsTimeAlarmRollersRow(lv_obj_t *parent, rollerData_t *rollerHour, rollerData_t *rollerMin, rollerData_t *rollerSec, lv_event_cb_t eventCallBack)
{
    /*Set texts containing roller selections*/
    const char* optsHour = "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12";

    const char* optsMinSec = "0\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12 \
                          \n13\n14\n15\n16\n17\n18\n19\n20\n21\n22      \
                          \n23\n24\n25\n26\n27\n28\n29\n30\n31\n32      \
                          \n33\n34\n35\n36\n37\n38\n39\n40\n41\n42      \
                          \n43\n44\n45\n46\n47\n48\n49\n50\n51\n52      \
                          \n53\n54\n55\n56\n57\n58\n59";

    
    /*Create roller objects for Hour, Minute, and Second*/
    lv_obj_t *rollerHourObject;
    lv_obj_t *rollerMinObject;
    lv_obj_t *rollerSecObject;

    /*Create a Parent object to place the roller containers on*/
    lv_obj_t *containerRow = lv_obj_create(parent);

    /*Set size, set width to LV_SIZE_CONTENT so that LVGL will dynamically adjust the width of the
    containerRow object when we add child objects to it, and set height to 100*/
    lv_obj_set_size(containerRow, LV_SIZE_CONTENT, 100);

    /*Set Flex Flow, the flex flow function is used to set the flow direction of children inside a
    container. So now child items will be laid horizontally instead of vertically*/
    lv_obj_set_flex_flow(containerRow, LV_FLEX_FLOW_ROW);

    /*Create label for hour roller*/
    lv_obj_t *labelHour = lv_label_create(containerRow);
    lv_label_set_text(labelHour, "hh");

    /*Create Hour roller*/
    rollerHourObject = createRoller(containerRow, optsHour, rollerHour->rollerActiveVal);

    /*Set Roller type for the Roller Hour Struct passed into the function*/
    rollerHour->rollerType = ROLLER_HOUR;

    /*Add Callback for the rollerHourObject that we created in this function*/
    lv_obj_add_event_cb(rollerHourObject, eventCallBack, LV_EVENT_VALUE_CHANGED, rollerHour);

    /*Create Label for Minute Roller*/
    lv_obj_t *labelMin = lv_label_create(containerRow);
    lv_label_set_text(labelMin, "mm");

    /*Create Minute Roller*/
    rollerMinObject = createRoller(containerRow, optsMinSec, rollerMin->rollerActiveVal);

    /*Set Roller type for the Roller Min struct passed into this function*/
    rollerMin->rollerType = ROLLER_MIN;

    /*Add Callback for the RollerMin object created in this function*/
    lv_obj_add_event_cb(rollerMinObject, eventCallBack, LV_EVENT_VALUE_CHANGED, rollerMin);

    if ( rollerSec != NULL )
    {
        /*If rollerSec exits*/
        /*Create Lable for Second Roller*/
        lv_obj_t *labelSec = lv_label_create(containerRow);
        lv_label_set_text(labelSec, "ss");

        /*Create Second roller*/
        rollerSecObject = createRoller(containerRow, optsMinSec, rollerSec->rollerActiveVal);

        /*Set Roller type for the roller sec struct passed into this function*/
        rollerSec->rollerType = ROLLER_SEC;

        /*Add callback for the RolleSec object created in this function*/
        lv_obj_add_event_cb(rollerSecObject, eventCallBack, LV_EVENT_VALUE_CHANGED, rollerSec);
    }
    return containerRow;
}

/**
 * @brief Create Time and Date Header for settings page
 * 
 * @param gui_element 
 */
static void guiCreateTimeDateHeader(GUI_t *const gui_element)
{
    /*Since gui_inst is cleaned we can assign the headers to the clock and date*/
    /*CLOCK-------------------------------------------------------------------------------------------------------------------------------------*/
    gui_element->clock = lv_label_create(gui_element->screen);
    
    /*Assign blank text at first, will update later*/
    lv_label_set_text(gui_element->clock, "");
    lv_obj_set_style_text_color(gui_element->clock, lv_color_white(), LV_PART_MAIN);
    
    /*Set Font*/
    lv_obj_set_style_text_font(gui_element->clock, &lv_font_montserrat_14, 0);
    
    /*Align Clock to Top right*/
    lv_obj_align(gui_element->clock, LV_ALIGN_TOP_RIGHT, -5, 0);

    /*DATE--------------------------------------------------------------------------------------------------------------------------------------*/
    gui_element->date = lv_label_create(gui_element->screen);
    
    /*Assign blank text at first, will update later*/
    lv_label_set_text(gui_element->date, "");
    lv_obj_set_style_text_color(gui_element->date, lv_color_white(), LV_PART_MAIN);

    /*Set font*/
    lv_obj_set_style_text_font(gui_element->date, &lv_font_montserrat_14, 0);

    /*Align date to top left*/
    lv_obj_align(gui_element->date, LV_ALIGN_TOP_LEFT, 5, 0);
}

/**
 * @brief Create Settings Page
 * 
 * @param gui_element Gui Instance
 * @param settingpagedata Setting Page data
 */
void guiCreateSettingsPage(GUI_t *const gui_element, settingPageData_t *settingpagedata)
{
    /*Placeholder variables*/
    lv_obj_t* rootPage;
    lv_obj_t* container;
    lv_obj_t* defaultcontainerToShow;
    lv_obj_t* section;
    lv_obj_t* parentRow;
    lv_obj_t* menu;

    /*Create Time and Date Header*/
    guiCreateTimeDateHeader(gui_element);

    /*Create main settings menu*/
    menu = createMenu(gui_element->screen, true, eventHandlerRootBackBtn);

    /*Store Background color of menu in a variable*/
    lv_color_t bgColor = lv_obj_get_style_bg_color(menu, LV_PART_MAIN);

    /*Adjust color based on brightness of color*/
    if(lv_color_brightness(bgColor) > 127)
    {
        lv_obj_set_style_bg_color(menu, lv_color_darken(bgColor, 10), LV_PART_MAIN);
    }
    else
    {
        lv_obj_set_style_bg_color(menu, lv_color_darken(bgColor, 50), LV_PART_MAIN);
    }

    /*Set size and align menu*/
    lv_obj_set_size(menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL) - 20);

    /*Align to bottom mid, so timedate header is at top*/
    lv_obj_align(menu, LV_ALIGN_BOTTOM_MID, 0, 0);

    /*SUB PAGE CREATION-------------------------------------------------------------------------------------------------------------------------*/



    /*DATE PAGE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
    /*Create Date Page on the Menu*/
    lv_obj_t *datePage = lv_menu_page_create(menu, NULL);

    /*Set Horizontal Padding equal to Header of the page*/
    lv_obj_set_style_pad_hor(datePage, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), LV_PART_MAIN), LV_PART_MAIN);

    /*Create a separator, separates sections, in this case separates calendar from page header*/
    lv_menu_separator_create(datePage);

    /*Create and load Calendar Data variable*/
    calendarData_t calendarData;
    calendarData.date = settingpagedata->date;
    calendarData.day = settingpagedata->day;
    calendarData.month = settingpagedata->month;
    calendarData.year = settingpagedata->year;
    
    /*Create Calendar Widget*/
    createCalendar(datePage, &calendarData);

    /*Create a separator, separates sections, in this case separates save button from calendar*/
    lv_menu_separator_create(datePage);

    /*Create 'Save' Button*/
    createSaveBtn(datePage,"Save",&gui_element->styleBtnNormal,&gui_element->styleBtnClicked,eventHandlerDateSave);
    /*END DATE PAGE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
    


    /*TIME PAGE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
    /*Create Time Page*/
    lv_obj_t *timePage = lv_menu_page_create(menu, NULL);

    /*Set Horizontal padding of page equal to header of page*/
    lv_obj_set_style_pad_hor(timePage, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), LV_PART_MAIN), LV_PART_MAIN);

    /*Seperate from header*/
    lv_menu_separator_create(timePage);

    /*Create section*/
    section = lv_menu_section_create(timePage);

    /*Create Roller data placeholders, since there will be 3 rollers, one for hour, minute and second
    Make the roller static since we want the roller to retain values between calls to this function*/
    static rollerData_t rollerTimeHour, rollerTimeMinute, rollerTimeSecond;

    /*Set active ID's for rollers*/
    rollerTimeHour.rollerActiveVal = settingpagedata->clockHour - 1; //Subtract one since roller hour starts at 1, when clock data starts from 0
    rollerTimeMinute.rollerActiveVal = settingpagedata->clockMin;
    rollerTimeSecond.rollerActiveVal = settingpagedata->clockSecond;

    /*Create Parent row*/
    parentRow = createSettingsTimeAlarmRollersRow(section, &rollerTimeHour, &rollerTimeMinute, &rollerTimeSecond, eventHandlerTimeRollers);

    /*Create CheckBox Data type, make them static so they retain values between calls to this function*/
    static CheckBoxData_t timeFormat;

    /*Set CheckBox Data Setting Type*/
    timeFormat.CheckBoxSettingType = SETTING_TIME;

    /*Adjust Initial CheckBox Data based on Clock Format*/
    if( settingpagedata->clockFormat == FORMAT_AM )
    {
        /*Set CheckBox Active Value*/
        timeFormat.CheckBoxBoxIndex = CHECK_BOX_INDEX_AM;
    }
    else if( settingpagedata->clockFormat == FORMAT_PM )
    {
        /*Set CheckBox active value*/
        timeFormat.CheckBoxBoxIndex = CHECK_BOX_INDEX_PM;
    }

    /*Create Time Format CheckBoxes*/
    createTimeFormatCheckBoxes(parentRow, &timeFormat);

    /*Create a seperator, separates the parentRow from the 24 Hour Switch*/
    lv_menu_separator_create(timePage);

    /*Create New section for 24 Hour switch*/
    section = lv_menu_section_create(timePage);

    /*Create meridiem Switch */
    lv_obj_t *meridiemSwitch = createONOFFSwitch(section, LV_SYMBOL_SETTINGS, "24H", false, eventHandlerMeridiemSwitch);
    
    /*Set the state of the meridiem switch based on current mode*/
    if( settingpagedata->clockMode == MODE_12H )
    {
        /*Set the switch off*/
        lv_obj_add_state( meridiemSwitch, LV_STATE_DEFAULT );
    }
    else if( settingpagedata->clockMode == MODE_24H )
    {
        /*Turn on the switch*/
        lv_obj_add_state( meridiemSwitch, LV_STATE_CHECKED );
    }

    /*Create separator, separates 24hour switch from 'Save' button*/
    lv_menu_separator_create( timePage );

    /*Create Save Button with Time Change Handler*/
    createSaveBtn(timePage, "Save", &gui_element->styleBtnNormal, &gui_element->styleBtnClicked, eventHandlerTimeSave );  
    /*END TIME PAGE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/



    /*ALARM PAGE////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
    /*Create Alarm Page*/
    lv_obj_t *alarmPage = lv_menu_page_create(menu, NULL);

    /*Set Horizontal padding of page equal to header of page*/
    lv_obj_set_style_pad_hor(alarmPage, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), LV_PART_MAIN), LV_PART_MAIN);

    /*Seperate from header*/
    lv_menu_separator_create(alarmPage);

    /*Create section*/
    section = lv_menu_section_create(alarmPage);

    /*Create Roller data placeholders, since there will be 2 rollers, one for hour and minute
    Make the roller static since we want the roller to retain values between calls to this function*/
    static rollerData_t rollerAlarmHour, rollerAlarmMinute;

    /*Set active ID's for Alarm Rollers*/
    rollerAlarmHour.rollerActiveVal = settingpagedata->alarmHour - 1; //Subtract 1 since the roller hour starts at 1, when the alarm data starts at 0
    rollerAlarmMinute.rollerActiveVal = settingpagedata->alarmMinute;

    /*Create Parent row*/
    parentRow = createSettingsTimeAlarmRollersRow( section, &rollerAlarmHour, &rollerAlarmMinute, NULL, eventHandlerAlarmRollers );

    /*Create checkbox data type for Alarm, make it static so it retains values between calls to this function*/
    static CheckBoxData_t alarmFormat;

    /*Set checkbox data type*/
    alarmFormat.CheckBoxSettingType = SETTING_ALARM;

    /*Adjust initial value of checkbox based on Alarm Format*/
    if( settingpagedata->clockFormat == FORMAT_AM )
    {
        /*Set Checkbox Acive value*/
        alarmFormat.CheckBoxBoxIndex = CHECK_BOX_INDEX_AM;
    }
    else if( settingpagedata->clockFormat == FORMAT_PM )
    {
        /*Set CheckBox active value*/
        alarmFormat.CheckBoxBoxIndex = CHECK_BOX_INDEX_PM;
    }

    /*Create Alarm Check Boxes*/
    createTimeFormatCheckBoxes( parentRow, &alarmFormat );

    /*Create Variables to store Alarm ON/OFF status and text of the Alarm lable*/
    char *alarmTxt;
    bool alarmCurrVal;

    /*Set Alarm Text and Current val based on current data*/
    if( settingpagedata->alarmStatus == ALARM_ON )
    {
        alarmTxt = "Alarm : ON";
        alarmCurrVal = true;
    }
    else if( settingpagedata->alarmStatus == ALARM_OFF )
    {
        alarmTxt = "Alarm : OFF";
        alarmCurrVal = false;
    }

    /*Create separator, separates the parent row from the Alarm ON/OFF switch label*/
    lv_menu_separator_create(alarmPage);

    /*Create a section for the Alarm ON/OFF lable*/
    section = lv_menu_section_create( alarmPage );

    /*Create the ON/OFF Switch on the section*/
    createONOFFSwitch( section, LV_SYMBOL_BELL, alarmTxt, alarmCurrVal, eventHandlerAlarmONOFFSwitch );
    /*END ALARM PAGE////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/



    /*DISPLAY PAGE//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
    /*Create Display page*/
    lv_obj_t *displayPage = lv_menu_page_create( menu, NULL );

    /*Set Horizontal padding of the page equal to the header of the page*/
    lv_obj_set_style_pad_hor( displayPage, lv_obj_get_style_pad_left( lv_menu_get_main_header( menu ), LV_PART_MAIN ), LV_PART_MAIN );

    /*Create separator to separate content from header*/
    lv_menu_separator_create( displayPage );

    /*Create Section*/
    section = lv_menu_section_create( displayPage );

    /*Create Display slider*/
    createDisplaySlider( section, LV_SYMBOL_SETTINGS, "Brightness", 0, 150, 100, eventHandlerDisplaySlider );
    /*END DISPLAY PAGE//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/



    /*ROOT PAGE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
    /*Create Root page*/
    rootPage = lv_menu_page_create(menu, "Settings");

    /*Create section on Root Page for the all the menu options*/
    section = lv_menu_section_create(rootPage);

    /*Date Settings*/
    container = createLabelContainer( rootPage, LV_SYMBOL_SETTINGS, "Date      Date", LV_MENU_ITEM_BUILDER_VARIANT_1 );
    lv_menu_set_load_page_event( menu, container, datePage );
    defaultcontainerToShow = container;

    /*Time Settings*/
    container = createLabelContainer( rootPage, LV_SYMBOL_SETTINGS, "Time      Time ", LV_MENU_ITEM_BUILDER_VARIANT_1 );
    lv_menu_set_load_page_event( menu, container, timePage );

    /*Alarm Settings*/
    container = createLabelContainer( rootPage, LV_SYMBOL_SETTINGS, "Alarm     Alarm", LV_MENU_ITEM_BUILDER_VARIANT_1 );
    lv_menu_set_load_page_event( menu, container, alarmPage );

    /*Display settings*/
    container = createLabelContainer( rootPage, LV_SYMBOL_SETTINGS, "Display", LV_MENU_ITEM_BUILDER_VARIANT_1 );
    lv_menu_set_load_page_event( menu, container, displayPage );

    /*Set the Root page as sidebar page for menu*/
    lv_menu_set_sidebar_page(menu, rootPage);

    /*Manually send event for Default Container to show*/
    lv_event_send( defaultcontainerToShow, LV_EVENT_CLICKED, NULL);
}

/**
 * @brief Clear Screen(All child objects) and remove Drop Down List
 * 
 * @param gui_element 
 */
void screenCleanup(GUI_t *gui_element)
{
    lv_obj_clean(gui_element->screen);
    gui_element->dropDownList = NULL;
}

/**
 * @brief Initialize style for main page of GUI
 * 
 * @param gui_element GUI_t member of the main ClockAlarmUI_t object, i.e. gui_inst
 */
void guiMainPageStyleInit(GUI_t *const gui_element)
{
    /*Set background color of main page*/
    lv_obj_set_style_bg_color(gui_element->screen, lv_color_make(11, 11, 69), LV_PART_MAIN);
    lv_obj_set_style_bg_grad_color(gui_element->screen, lv_color_make(138, 138, 162), LV_PART_MAIN);
    lv_obj_set_style_bg_grad_dir(gui_element->screen, LV_GRAD_DIR_VER, LV_PART_MAIN);
    
    /*Set clock text font*/
    lv_obj_set_style_text_font(gui_element->clock, &lv_font_montserrat_40, LV_PART_MAIN);

    /*Set Various Date elements fonts*/
    lv_obj_set_style_text_font(gui_element->day, &lv_font_montserrat_16, LV_PART_MAIN);
    lv_obj_set_style_text_font(gui_element->month, &lv_font_montserrat_12, LV_PART_MAIN);
    lv_obj_set_style_text_font(gui_element->date, &lv_font_montserrat_40, LV_PART_MAIN);
    lv_obj_set_style_text_font(gui_element->year, &lv_font_montserrat_12, LV_PART_MAIN);

    /*Clock Alignment using percentanges*/
    lv_obj_align(gui_element->clock, LV_ALIGN_TOP_RIGHT, lv_pct(-5), lv_pct(40));

    /*Set various date elements alignment*/
    lv_obj_align(gui_element->clock, LV_ALIGN_TOP_RIGHT, LV_PCT(-5), LV_PCT(40));
    lv_obj_align(gui_element->date, LV_ALIGN_TOP_LEFT, LV_PCT(5), LV_PCT(40));
    lv_obj_align(gui_element->day, LV_ALIGN_TOP_LEFT, LV_PCT(5), LV_PCT(35));
    lv_obj_align(gui_element->month, LV_ALIGN_TOP_LEFT, LV_PCT(5), LV_PCT(30));
    lv_obj_align(gui_element->year, LV_ALIGN_TOP_LEFT, LV_PCT(5), LV_PCT(55));  

    /*Dropdown Button Setup-----------------------------------------------------------------------------------------------------*/

    /*Set Btn size and alignment*/
    lv_obj_set_size(gui_element->dropDownBtn, 30, 30);
    lv_obj_align(gui_element->dropDownBtn, LV_ALIGN_TOP_RIGHT, 0, 0);

    /*Set background opacity to 90% ONLY when pressed*/
    lv_obj_set_style_bg_opa(gui_element->dropDownBtn, LV_OPA_90, LV_STATE_PRESSED);
    
    /*Set corner radius to 5 pixels ONLY when pressed*/
    lv_obj_set_style_radius(gui_element->dropDownBtn, 5, LV_STATE_PRESSED);

    /*Set background color to Deep purple(2 shades darker) ONLY when pressed*/
    lv_obj_set_style_bg_color(gui_element->dropDownBtn, lv_palette_darken(LV_PALETTE_DEEP_PURPLE, 2), LV_STATE_PRESSED);
    
    /*Create a label, using Drop Down btn as Parent*/
    lv_obj_t* label = lv_label_create(gui_element->dropDownBtn);

    /*Set the icon and icon color for dropdown label*/
    lv_label_set_text(label, LV_SYMBOL_LIST);
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_30, LV_PART_MAIN);

    /*Center the label to center of its parent(droppdwnbtn)*/
    lv_obj_center(label);        
}

/**
 * @brief Create and assign label objects to each element of gui_inst of main object, assign callback to screen and dropDownBtn
 * 
 * @param gui_element GUI_t member of the main ClockAlarmUI_t object, i.e. gui_inst
 */
void guiMainLabelsAndDropDownCreator(GUI_t *const gui_element)
{
    /*Create label object and assign to clock element of gui_element*/
    gui_element->clock = lv_label_create(gui_element->screen);
    lv_obj_set_style_text_color(gui_element->clock, lv_color_white(), LV_PART_MAIN);

    /*Create label objects and assign to date elements of gui_element*/
    gui_element->day = lv_label_create(gui_element->screen);
    lv_obj_set_style_text_color(gui_element->day, lv_color_white(), LV_PART_MAIN);
    gui_element->month = lv_label_create(gui_element->screen);
    lv_obj_set_style_text_color(gui_element->month, lv_color_white(), LV_PART_MAIN);
    gui_element->year = lv_label_create(gui_element->screen);
    lv_obj_set_style_text_color(gui_element->year, lv_color_white(), LV_PART_MAIN);
    gui_element->date = lv_label_create(gui_element->screen);
    lv_obj_set_style_text_color(gui_element->date, lv_color_white(), LV_PART_MAIN);

    /*Create button for drop down button on main screen*/
    gui_element->dropDownBtn = lv_btn_create(gui_element->screen);

    /*Remove all the syle properties, so button exits, but cannot be seen and has no style elements, style init @fn guiMainPageStyleInit*/
    lv_obj_remove_style_all(gui_element->dropDownBtn);

    /*Add callback for screen*/
    lv_obj_add_event_cb(gui_element->screen, eventHandlerScreen, LV_EVENT_PRESSED, (void *)gui_element);
    
    /*Add callback for drop down button*/
    lv_obj_add_event_cb(gui_element->dropDownBtn, eventHandlerDropDownBtn, LV_EVENT_CLICKED, (void *)gui_element);
    
}

/**
 * @brief Style Init for the 'Save' Btn with ripple effect
 * 
 * @param gui_element GUI_t member of the main ClockAlarmUI_t object, i.e. gui_inst
 */
void guiBtnStyleInit(GUI_t *const gui_element)
{
    /*Initialize default style for normal and clicked*/
    lv_style_init(&gui_element->styleBtnNormal);
    lv_style_init(&gui_element->styleBtnClicked);

    /*Border vs Outline
    Border - increasing the border width on a rectangle will consume more of its interior space
    Outline - increasing the outline width expands outward without altering the interior container of the object*/

    /*Normal Btn----------------------------------------------------------------------------------------------------------*/
    /*Btn corner radius*/
    lv_style_set_radius(&gui_element->styleBtnNormal, 15);
    
    /*Background Opacity*/
    lv_style_set_bg_opa(&gui_element->styleBtnNormal, LV_OPA_100);
    
    /*Background Color*/
    lv_style_set_bg_color(&gui_element->styleBtnNormal, lv_color_make(11, 11, 69));

    /*Border Opacity*/
    lv_style_set_bg_opa(&gui_element->styleBtnNormal, LV_OPA_40);

    /*Border width*/
    lv_style_set_border_width(&gui_element->styleBtnNormal, 2);

    /*Border color*/
    lv_style_set_border_color(&gui_element->styleBtnNormal, lv_palette_main(LV_PALETTE_GREY));

    /*Outline Opacity*/
    lv_style_set_outline_opa(&gui_element->styleBtnNormal, LV_OPA_100);
    
    /*Outline color*/
    lv_style_set_outline_color(&gui_element->styleBtnNormal, lv_color_black());
    
    /*Text color*/
    lv_style_set_text_color(&gui_element->styleBtnNormal, lv_color_white());
    
    /*Set padding, increase distance from text to edge of container in all directions by 10 pixels*/
    lv_style_set_pad_all(&gui_element->styleBtnNormal, 10);

    /*Add shadow*/
    lv_style_set_shadow_color(&gui_element->styleBtnNormal, lv_palette_main(LV_PALETTE_GREY));
    // lv_style_set_shadow_spread(&gui_element->styleBtnNormal, )

    /*Clicked Btn---------------------------------------------------------------------------------------------------------*/
    /*Set outline width when pressed*/
    lv_style_set_outline_width(&gui_element->styleBtnClicked, 30);

    /*Outline opacity when pressed*/
    lv_style_set_outline_opa(&gui_element->styleBtnClicked, LV_OPA_TRANSP);    

    /*Add slight vertical translation after pressing*/
    lv_style_set_translate_y(&gui_element->styleBtnClicked, 5);

    /*Set background color of the button when clicked (Darker shade of original background color)*/
    lv_style_set_bg_color(&gui_element->styleBtnClicked, lv_color_make(11, 11, 69));

    /*Set background gradient color, when pressed, color goes from bg color to bg grad color, giving a depth effect
    making the Btn look more 3-dimensional, top to bottom gradient */
    lv_style_set_bg_grad_color(&gui_element->styleBtnClicked, lv_color_make(138, 138, 162));

    /*Set gradient direction*/
    lv_style_set_bg_grad_dir(&gui_element->styleBtnClicked, LV_GRAD_DIR_VER);
    

    /*Transition-------------------------------------------------------------------------------------------------------------*/
    /*Create a transition description object*/
    static lv_style_transition_dsc_t transition;
    
    /*create an arry of Which things(properties) do we want to change during the transition*/
    static lv_style_prop_t properties[] = {LV_STYLE_OUTLINE_WIDTH, LV_STYLE_OUTLINE_OPA};

    /*Initialize transition description object with above properties*/
    lv_style_transition_dsc_init(&transition, properties, lv_anim_path_linear, 325, 0, NULL);

    /*Set the transition to the style: lv_Btn_style_clicked*/
    lv_style_set_transition(&gui_element->styleBtnClicked, &transition);
}

/**
 * @brief Initialize default settings for clock style and call Btn style init
 * 
 * @param gui_element GUI_t member of the main ClockAlarmUI_t object, i.e. gui_inst
 */
void lvglStyleInit(GUI_t *const gui_element)
{
    /*Pass in the address(gui_element->styleClock) because that address points to lv_style_t *styleClock, gui_element->styleClock returns the
    element itself not a pointer to the element. If we pass in the element, since its pass by copy, we cant change the original element, we will
    just end up changing a copy of the element */
    
    /*Initialize default Style for the styleClock element of the GUI_t structure, which is an element of the main object*/
    lv_style_init(&gui_element->styleClock);

    /*Initialize style for 'Save' Btn object*/
    guiBtnStyleInit(gui_element);
}

/**
 * @brief Set the screen element of gui_element of main object to current active screen and call LVGL style init func for button
 * 
 *  @param gui_element GUI_t member of the main ClockAlarmUI_t object, i.e. gui_inst
 */
void guiStyleCreator(GUI_t *const gui_element)
{
    /*Set screen member of gui_element = current active screen*/
    gui_element->screen = lv_scr_act();

    /*Initialize LVGL Style*/
    lvglStyleInit(gui_element);
}

