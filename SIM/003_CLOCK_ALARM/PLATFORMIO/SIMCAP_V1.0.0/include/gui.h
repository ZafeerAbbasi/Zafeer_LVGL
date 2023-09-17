/*
# ##############################################################################
# File: GUI.h                                                                  #
# Project: include                                                             #
# Created Date: Sunday, August 20th 2023, 10:45:20 pm                          #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Saturday, September 2nd 2023, 6:16:39 am                      #
# Modified By: Zafeer Abbasi                                                   #
# ----------------------------------------------                               #
# Copyright (c) 2023 Zafeer.A                                                  #
# ----------------------------------------------                               #
# HISTORY:                                                                     #
*//**/
#ifndef GUI_H
#define GUI_H



/*##############################################################################################################################################*/
/*INCLUDES______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

#include "lvgl.h"


/*##############################################################################################################################################*/
/*GLOBALS_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/



/*##############################################################################################################################################*/
/*DEFINES_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/



/*##############################################################################################################################################*/
/*TYPEDEFS/STRUCTS/ENUMS________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

/*Menu Item Builder Variant*/
typedef enum {
    LV_MENU_ITEM_BUILDER_VARIANT_1,
    LV_MENU_ITEM_BUILDER_VARIANT_2
}menuItemBuilderVariant_t;

/*GUI Structure*/
typedef struct{
    /*private*/
    lv_obj_t *screen;
    
    /*public*/
    lv_obj_t *clock;

    /*private*/
    lv_obj_t *day;
    lv_obj_t *month;
    lv_obj_t *date;
    lv_obj_t *year;
    lv_obj_t *menu;
    lv_obj_t *cont;
    lv_obj_t *dropDownList;
    lv_obj_t *dropDownBtn;
    lv_style_t styleClock;
    lv_style_t styleBtnNormal;
    lv_style_t styleBtnClicked;
}GUI_t;

/**
 * @brief Setting Page Data struct
 * 
 */
typedef struct{
    
    uint8_t clockHour;
    uint8_t clockMin;
    uint8_t clockSecond;
    uint8_t clockFormat;
    uint8_t clockMode;
    uint8_t alarmStatus;
    uint8_t alarmHour;
    uint8_t alarmMinute;
    uint8_t alarmSecond;
    uint8_t alarmFormat;
    uint8_t soundStatus;
    uint8_t brightness;
    uint8_t day;
    uint8_t date;
    uint8_t month;
    uint8_t year;
}settingPageData_t;


/*##############################################################################################################################################*/
/*FUNCTIONS_____________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

void GUIDisplayCurrentTime( GUI_t *const guiElement, char *const stringTime );
void screenCleanup(GUI_t *gui_element);
void guiStyleCreator(GUI_t *const gui_element);
void lvglStyleInit(GUI_t *const gui_element);
void guiBtnStyleInit(GUI_t *const gui_element);
void guiMainLabelsAndDropDownCreator(GUI_t *const gui_element);
void guiMainPageStyleInit(GUI_t *const gui_element);
void guiCreateSettingsPage(GUI_t *const gui_element, settingPageData_t *settingpagedata);

#endif