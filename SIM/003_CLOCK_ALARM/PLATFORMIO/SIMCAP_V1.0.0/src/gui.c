/*
# ##############################################################################
# File: gui.c                                                                  #
# Project: src                                                                 #
# Created Date: Monday, August 21st 2023, 4:46:40 am                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Tuesday, August 29th 2023, 10:47:38 pm                        #
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
 * @brief Create and assign label objects to each element of gui_inst of main object, assign callback to screen and dropDownBtn
 * 
 * @param gui_element GUI_t member of the main ClockAlarmUI_t object, i.e. gui_inst
 */
void guiLabelAndDropDownCreator(GUI_t *const gui_element)
{
    /*Create label object and assign to clock element of gui_element*/
    gui_element->clock = lv_label_create(gui_element->screen);

    /*Create label objects and assign to date elements of gui_element*/
    gui_element->day = lv_label_create(gui_element->screen);
    gui_element->month = lv_label_create(gui_element->screen);
    gui_element->year = lv_label_create(gui_element->screen);
    gui_element->date = lv_label_create(gui_element->screen);

    /*Create button for drop down button on main screen*/
    gui_element->dropDownBtn = lv_btn_create(gui_element->screen);

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
void lvglBtnStyleInit(GUI_t *const gui_element)
{
    /*Initialize default style for normal and clicked*/
    lv_style_init(&gui_element->styleBtnNormal);
    lv_style_init(&gui_element->styleBtnClicked);

    /*Border vs Outline
    Border - increasing the border width on a rectangle will consume more of its interior space
    Outline - increasing the outline width expands outward without altering the interior content of the object*/

    /*Normal Btn----------------------------------------------------------------------------------------------------------*/
    /*Btn corner radius*/
    lv_style_set_radius(&gui_element->styleBtnNormal, 15);
    
    /*Background Opacity*/
    lv_style_set_bg_opa(&gui_element->styleBtnNormal, LV_OPA_100);
    
    /*Background Color*/
    lv_style_set_bg_color(&gui_element->styleBtnNormal, lv_palette_main(LV_PALETTE_BLUE));

    /*Border Opacity*/
    lv_style_set_bg_opa(&gui_element->styleBtnNormal, LV_OPA_40);

    /*Border width*/
    lv_style_set_border_width(&gui_element->styleBtnNormal, 2);

    /*Border color*/
    lv_style_set_border_color(&gui_element->styleBtnNormal, lv_palette_main(LV_PALETTE_GREY));

    /*Outline Opacity*/
    lv_style_set_outline_opa(&gui_element->styleBtnNormal, LV_OPA_100);
    
    /*Outline color*/
    lv_style_set_outline_color(&gui_element->styleBtnNormal, lv_palette_main(LV_PALETTE_BLUE));
    
    /*Text color*/
    lv_style_set_text_color(&gui_element->styleBtnNormal, lv_color_white());
    
    /*Set padding, increase distance from text to edge of container in all directions by 10 pixels*/
    lv_style_set_pad_all(&gui_element->styleBtnNormal, 10);

    /*Clicked Btn---------------------------------------------------------------------------------------------------------*/
    /*Set outline width when pressed*/
    lv_style_set_outline_width(&gui_element->styleBtnClicked, 30);

    /*Outline opacity when pressed*/
    lv_style_set_outline_opa(&gui_element->styleBtnClicked, LV_OPA_TRANSP);    

    /*Add slight vertical translation after pressing*/
    lv_style_set_translate_y(&gui_element->styleBtnClicked, 5);

    /*Set background color of the ripple (Darker shade of original background color)*/
    lv_style_set_bg_color(&gui_element->styleBtnClicked, lv_palette_darken(LV_PALETTE_BLUE, 2));

    /*Set background gradient color, when pressed, color goes from bg color to bg grad color, giving a depth effect
    making the Btn look more 3-dimensional, top to bottom gradient */
    lv_style_set_bg_grad_color(&gui_element->styleBtnClicked, lv_palette_darken(LV_PALETTE_BLUE, 4));

    /*Set gradient direction*/
    lv_style_set_bg_grad_dir(&gui_element->styleBtnClicked, LV_GRAD_DIR_VER);
    

    /*Transition-------------------------------------------------------------------------------------------------------------*/
    /*Create a transition description object*/
    static lv_style_transition_dsc_t transition;
    
    /*create an arry of Which things(properties) do we want to change during the transition*/
    static lv_style_prop_t properties[] = {LV_STYLE_OUTLINE_WIDTH, LV_STYLE_OUTLINE_OPA};

    /*Initialize transition description object with above properties*/
    lv_style_transition_dsc_init(&transition, properties, lv_anim_path_linear, 300, 0, NULL);

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
    lvglBtnStyleInit(gui_element);
}

/**
 * @brief Set the screen element of gui_element of main object to current active screen and call LVGL style init func for screen element of gui_element of main object
 * 
 * @param gui_element GUI_t member of the main ClockAlarmUI_t object, i.e. gui_inst
 */
void guiStyleCreator(GUI_t *const gui_element)
{
    /*Set screen member of gui_element = current active screen*/
    gui_element->screen = lv_scr_act();

    /*Initialize LVGL Style*/
    lvglStyleInit(gui_element);
}

