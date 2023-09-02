/*
# ##############################################################################
# File: gui_widget.h                                                           #
# Project: include                                                             #
# Created Date: Monday, August 21st 2023, 4:49:16 am                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Saturday, September 2nd 2023, 7:41:01 am                      #
# Modified By: Zafeer Abbasi                                                   #
# ----------------------------------------------                               #
# Copyright (c) 2023 Zafeer.A                                                  #
# ----------------------------------------------                               #
# HISTORY:                                                                     #
*//**/
#ifndef GUI_WIDGET_H
#define GUI_WIDGET_H


/*##############################################################################################################################################*/
/*INCLUDES______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

#include "gui.h"

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

void eventHandlerDropDownBtn(lv_event_t *e);
void collapseDropDownList(GUI_t *gui_element);
void eventHandlerScreen( lv_event_t * e );
void eventHandlerDropDownBtnOptionSettings(lv_event_t *e);
void eventHandlerDropDownBtnOptionAbout(lv_event_t* e);


#endif