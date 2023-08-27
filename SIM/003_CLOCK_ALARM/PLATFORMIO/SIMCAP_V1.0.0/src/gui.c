/*
# ##############################################################################
# File: gui.c                                                                  #
# Project: src                                                                 #
# Created Date: Monday, August 21st 2023, 4:46:40 am                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Monday, August 21st 2023, 8:48:28 pm                          #
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
 * @brief Style Init for the 'Save' button with ripple effect
 * 
 * @param gui_element GUI_t member of the main ClockAlarmUI_t object, i.e. gui_inst
 */
void lvglBtnStyleInit(GUI_t *const gui_element)
{
    /*Initialize default style for normal and clicked*/
    lv_style_init(&gui_element->style_button_normal);
    lv_style_init(&gui_element->style_button_clicked);

    /*Normal Button radius*/
    lv_style_set_radius(&gui_element->style_button_normal, 35)
}

/**
 * @brief Initialize default settings for clock style and call button style init
 * 
 * @param gui_element GUI_t member of the main ClockAlarmUI_t object, i.e. gui_inst
 */
void lvglStyleInit(GUI_t *const gui_element)
{
    /*Pass in the address(gui_element->style_clock) because that address points to lv_style_t *style_clock, gui_element->style_clock returns the
    element itself not a pointer to the element. If we pass in the element, since its pass by copy, we cant change the original element, we will
    just end up changing a copy of the element */
    
    /*Initialize default Style for the style_clock element of the GUI_t structure, which is an element of the main object*/
    lv_style_init(&gui_element->style_clock);

    /*Initialize style for 'Save' button object*/
    lvglBtnStyleInit(gui_element);
}

/**
 * @brief Set the screen element of gui_element of main object to current active screen and call LVGL style init func for screen element of gui_element of main object
 * 
 * @param gui_element GUI_t member of the main ClockAlarmUI_t object, i.e. gui_inst
 */
void guiCreator(GUI_t *const gui_element)
{
    /*Set screen member of gui_element = current active screen*/
    gui_element->screen = lv_scr_act();

    /*Initialize LVGL Style*/
    lvglStyleInit(gui_element);
}

