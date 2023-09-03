/*
# ##############################################################################
# File: gui.c                                                                  #
# Project: src                                                                 #
# Created Date: Monday, August 21st 2023, 4:46:40 am                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Sunday, September 3rd 2023, 3:59:00 pm                        #
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
 * @brief Create Time and Date Header for settings page
 * 
 * @param gui_element 
 */
void guiCreateTimeDateHeader(GUI_t *const gui_element)
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
    
    /*Create Time and Date Header*/
    guiCreateTimeDateHeader(gui_element);

    /*Create main settings menu*/
    lv_obj_t *menu = createMenu(gui_element->screen, true, eventHandlerRootBackBtn);

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
    lv_obj_align(menu, LV_ALIGN_BOTTOM_MID, 0, 0);

    /*SUB PAGE CREATION-------------------------------------------------------------------------------------------------------------------------*/
    
    /*DATE PAGE---------------------------------------------------------------------------------------------------------------------------------*/
    /*ROOT PAGE---------------------------------------------------------------------------------------------------------------------------------*/


    
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
void guiLabelAndDropDownCreator(GUI_t *const gui_element)
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
    lv_style_set_outline_color(&gui_element->styleBtnNormal, lv_color_white());
    
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

