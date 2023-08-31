/*
# ##############################################################################
# File: Clock.h                                                                #
# Project: include                                                             #
# Created Date: Sunday, August 20th 2023, 9:51:28 pm                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Thursday, August 31st 2023, 12:46:24 am                       #
# Modified By: Zafeer Abbasi                                                   #
# ----------------------------------------------                               #
# Copyright (c) 2023 Zafeer.A                                                  #
# ----------------------------------------------                               #
# HISTORY:                                                                     #
*//**/
#ifndef CLOCK_H
#define CLOCK_H



/*##############################################################################################################################################*/
/*INCLUDES______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

#include <stdint.h>
#include <stdbool.h>
#include "project_clock_alarm.h"



/*##############################################################################################################################################*/
/*GLOBALS_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/



/*##############################################################################################################################################*/
/*DEFINES_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

#define THURSDAY 4
#define AUGUST  7
#define MAX_TIME  (864000UL)
#define INITIAL_CURRENT_TIME  FORMAT_TIME(12, 22, 22)
#define INITIAL_alarmTime  FORMAT_TIME(8, 0, 0)
#define INITIAL_DAY THURSDAY
#define INITIAL_MONTH  AUGUST
#define INITIAL_YEAR  2023ul
#define INITIAL_DATE  12
#define INITIAL_alarmStatus ALARM_ON
#define BASE_YEAR 2000

/*##############################################################################################################################################*/
/*TYPEDEFS/STRUCTS/ENUMS________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

/*Date structure*/
typedef struct{
    uint32_t day;
    uint32_t date;
    uint32_t month;
    uint32_t year;
}date_t;

/*Clock Structure*/
typedef struct{
    uint32_t    timeNow;
    uint32_t    alarmTime;
    uint32_t    timeFormat;
    uint8_t     alarmTimeFormat;
    uint32_t    alarmStatus;
    uint32_t    timeMode;
    date_t      dateNow;
}Clock_t;

/*Time Mode (24HR/12HR)*/
typedef enum{
    MODE_24H,
    MODE_12H
}timeMode_t;

/*Time Format (24HR/AM/PM)*/
typedef enum{
    FORMAT_24HR,
    FORMAT_AM,
    FORMAT_PM
}timeFormat_t;

/*##############################################################################################################################################*/
/*FUNCTIONS_____________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

void createClock(Clock_t *const clock_element);


#endif