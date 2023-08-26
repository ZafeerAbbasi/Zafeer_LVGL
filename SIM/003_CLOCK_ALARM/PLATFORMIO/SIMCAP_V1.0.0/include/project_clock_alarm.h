/*
# ##############################################################################
# File: ClockAlarmUI.h                                                         #
# Project: include                                                             #
# Created Date: Sunday, August 20th 2023, 9:49:53 pm                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Monday, August 21st 2023, 4:52:29 am                          #
# Modified By: Zafeer Abbasi                                                   #
# ----------------------------------------------                               #
# Copyright (c) 2023 Zafeer.A                                                  #
# ----------------------------------------------                               #
# HISTORY:                                                                     #
*//**/
#ifndef PROJECT_CLOCK_ALARM_H
#define PROJECT CLOCK_ALARM_H



/*##############################################################################################################################################*/
/*INCLUDES______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

#include "clock.h"
#include "gui.h"




/*##############################################################################################################################################*/
/*GLOBALS_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/



/*##############################################################################################################################################*/
/*DEFINES_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

#define GET_HOUR(seconds)                       ((uint8_t)(seconds/3600UL))         /*Get hours from seconds*/
#define GET_MIN(seconds)                        ((uint8_t)((seconds/60UL)%60UL))    /*Get minutes from seconds*/
#define GET_SEC(seconds)                        ((uint8_t)(seconds % 60UL))         /*Get remaining seconds after subtracting minutes*/
#define DIGIT1(d)                               ((uint8_t)(d/10U))                  /*Get 1st Digit of a two digit number*/
#define DIGIT2(d)                               ((uint8_t)(d%10U))                  /*Get 2nd Digit of a two digit number*/
#define UI_STATE_CHANGE(object, new_state)      (object->state = new_state)         /*Change the State*/
#define FORMAT_TIME(hour, min, sec)             ( ( (unsigned long)(hour)*\
(unsigned long)(3600) ) + ( (unsigned long)(min)*(unsigned long)(60) ) +  ( (unsigned long)(sec) ) ) /*Given hour, min and sec, convert to Timeformat*/



/*##############################################################################################################################################*/
/*TYPEDEFS/STRUCTS/ENUMS________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

/*UI_state_t structure*/
typedef enum{
    STATE_TICKING,
    STATE_SETTING,
    STATE_ALARM
}GUI_state_t;

/*Main Clock Object*/
typedef struct{
    Clock_t         clock_inst;     /*Clock element*/
    GUI_t           gui_inst;       /*GUI element*/
    GUI_state_t     state;          /*GUI state */
    GUI_state_t     history;        /*GUI history*/
    Clock_t         usr_setting;    /*User Clock settings*/
    Clock_t         setting_save;   /*Clock settings save*/
}ClockAlarmUI_t;

/*Events that are generated in the application*/
typedef enum{
    E_SETTING,                      /*Event generated when user clicks the 'Settings' option from the drop down list*/
    E_ROOT_BACK,                    /*Event generated when user clicks the '<' (Back) button on the settings screen*/
    E_SETTING_CLOCK_HOUR,           /*Event generated when user rolls the roller to set a new value on the Time hour roller*/
    E_SETTING_CLOCK_MIN,            /*Event generated when user rolls the roller to set a new value on the Minute hour roller*/
    E_SETTING_CLOCK_SEC,            /*Event generated when user rolls the roller to set a new value on the Second hour roller*/
    E_SETTING_CLOCK_FORMAT,         /*Event generated when user changes the Clock 'AM' or 'PM' checkbox*/
    E_SETTING_CLOCK_MODE,           /*Event generated when user changes the Clock from '24 hour' to '12 hour' or vice versa*/
    E_SETTING_DATE_CHANGE,          /*Event generated when the user*/
    E_SETTING_ALARM_HOUR,           /*Event generated when user rolls the roller to set a new value on the alarm hour roller*/
    E_SETTING_ALARM_MIN,            /*Event generated when user rolls the roller to set a new value on the alarm minute roller*/
    E_SETTING_ALARM_FORMAT,         /*Event generated when user changes Alarm format from 'AM' to 'PM' or vice versa*/
    E_ALARM_ON_OFF,                 /*Event generated when user switches Alarm ON or OFF*/
    E_SETTING_SAVE_YES_NO,          /*Event generated when user selects either 'YES' or 'NO' at the 'Save Settings?' screen*/
    E_DATE_SAVE,                    /*Event generated when user saves date on the calendar in settings*/
    E_CLOCK_SAVE,                   /*Event generated when user saves Clock Time in the settings*/
    E_ALARM_SAVE,                   /*Event generated when user saves the Alarm Time in the setttings*/
    E_ALARM_NOTIF_ON,               /*Event generated when the time hits the Alarm Time and the Alarm GIF Notif pops up*/
    E_ALARM_NOTIF_CLOSE,            /*Event generated when the Alarm GIF notif closes*/
    E_NONE
}event_t;



/*##############################################################################################################################################*/
/*FUNCTIONS_____________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

void clockAlarmUI_Constructor(ClockAlarmUI_t *const clk_object);



#endif