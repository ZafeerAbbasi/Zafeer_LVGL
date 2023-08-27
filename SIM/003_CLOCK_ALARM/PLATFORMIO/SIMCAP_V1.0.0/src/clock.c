/*
# ##############################################################################
# File: clock.c                                                                #
# Project: src                                                                 #
# Created Date: Monday, August 21st 2023, 3:03:30 am                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Monday, August 21st 2023, 4:27:04 am                          #
# Modified By: Zafeer Abbasi                                                   #
# ----------------------------------------------                               #
# Copyright (c) 2023 Zafeer.A                                                  #
# ----------------------------------------------                               #
# HISTORY:                                                                     #
*//**/
/*This file is about manipulating data regarding the Clock_t element of the Main Clock object*/


/*##############################################################################################################################################*/
/*INCLUDES______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

#include "clock.h"
#include "project_clock_alarm.h"



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
 * @brief Take in a clock instance of type Clock_t and set initial date/time
 * 
 * @param clock_element Clock_t member of the main ClockAlarmUI_t object, i.e. clock_inst 
 */
void createClock(Clock_t *const clock_element)
{
    clock_element->time_now         = INITIAL_CURRENT_TIME;
    clock_element->time_mode        =  MODE_24H;
    clock_element->alarm_time       = INITIAL_ALARM_TIME;
    clock_element->date_now.day     = INITIAL_DAY;
    clock_element->date_now.date    = INITIAL_DATE;
    clock_element->date_now.month   = INITIAL_MONTH;
    clock_element->date_now.year    = INITIAL_YEAR;
}