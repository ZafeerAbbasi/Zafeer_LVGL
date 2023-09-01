/*
# ##############################################################################
# File: Project_ClockAlarm.c                                                   #
# Project: src                                                                 #
# Created Date: Monday, August 21st 2023, 2:09:43 am                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Friday, September 1st 2023, 8:12:03 am                        #
# Modified By: Zafeer Abbasi                                                   #
# ----------------------------------------------                               #
# Copyright (c) 2023 Zafeer.A                                                  #
# ----------------------------------------------                               #
# HISTORY:                                                                     #
*//**/



/*##############################################################################################################################################*/
/*INCLUDES______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

#include <stdio.h>
#include "project_clock_alarm.h"



/*##############################################################################################################################################*/
/*GLOBALS_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

const  char *g_days[] = { "Sunday", "Monday", "Tuesday", "Wednseday", "Thursday", "Firday", "Saturday" };

const char *g_months[] = { "January" , "February", "March","April","May", "June", "July", "August","September",\
                          "October","November","December" };



/*##############################################################################################################################################*/
/*DEFINES_______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/



/*##############################################################################################################################################*/
/*TYPEDEFS/STRUCTS/ENUMS________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/



/*##############################################################################################################################################*/
/*FUNCTIONS______________________________________________________________________________________________________________________________________*/
/*##############################################################################################################################################*/

/**
 * @brief Main function to process all events 
 * 
 * @param clk_object Main Clock Alarm UI Object
 * @param event Pointer to the event which occurred
 */
void clockAlarmUIProcessEvent(ClockAlarmUI_t *const clk_object, UI_Event_t *event)
{
    /*Extract event signal from event*/
    event_t currEvent = event->sig;

    /*Main Event Process switch statement*/
    switch (currEvent)
    {
    case E_SETTING:
        
        /*CLOCK USER SETTINGS---------------------------------------------------------------------------------------------------*/
        /*Create a variable of type settingPageData_t to hold setting page data*/
        settingPageData_t settingPageData;

        /*Clear the settingPageData variable*/
        memset(&settingPageData, 0, sizeof(settingPageData_t));

        /*Set user_setting->current time in 12 Hour format*/
        clk_object->usr_setting.timeNow = convert24HourFormatTo12Hour(clk_object->clock_inst.timeNow);

        /*Set Time format*/
        clk_object->usr_setting.alarmTimeFormat = clockGetAMorPM(clk_object->clock_inst.timeFormat);

        /*Set Alarm time*/
        clk_object->usr_setting.alarmTime = convert24HourFormatTo12Hour(clk_object->clock_inst.alarmTime);

        /*Set Alarm time format*/
        clk_object->usr_setting.alarmTimeFormat = clockGetAMorPM(clk_object->clock_inst.alarmTime);

        /*CLOCK SETTING SAVE----------------------------------------------------------------------------------------------------*/
        /*Set Current time*/
        clk_object->setting_save.timeNow = clk_object->usr_setting.timeNow;

        /*Set time format*/
        clk_object->setting_save.timeFormat = clk_object->usr_setting.timeFormat;

        /*Set Alarm time*/
        clk_object->setting_save.alarmTime = clk_object->usr_setting.timeFormat;

        /*Set Alarm time format*/
        clk_object->setting_save.alarmTimeFormat = clk_object->usr_setting.alarmTimeFormat;

        /*SETTING PAGE DATA - CLOCK---------------------------------------------------------------------------------------------*/
        /*Store current time in a temp variable*/
        uint32_t currentTime = clk_object->usr_setting.timeNow;

        /*Set Clock Hour*/
        settingPageData.clockHour = GET_HOUR(currentTime);

        /*Set Clock Min*/
        settingPageData.clockMin = GET_MIN(currentTime);

        /*Set Clock Second*/
        settingPageData.clockSecond = GET_SEC(currentTime);

        /*Set Clock format*/
        settingPageData.clockFormat = clockGetAMorPM(clk_object->clock_inst.timeNow);

        /*Set Clock Mode*/
        settingPageData.clockMode = clk_object->clock_inst.timeMode;

        /*SETTING PAGE DATA - ALARM---------------------------------------------------------------------------------------------*/
        /*Store current Alarm time in temp variable*/
        currentTime = clk_object->usr_setting.alarmTime;

        /*Set Alarm Hour*/
        settingPageData.alarmHour = GET_HOUR(currentTime);

        /*Set Alarm Minute*/
        settingPageData.alarmMinute = GET_MIN(currentTime);

        /*Set Alarm Second*/
        settingPageData.alarmSecond = GET_SEC(currentTime);

        /*Set Alarm Format*/
        settingPageData.alarmFormat = clockGetAMorPM(clk_object->clock_inst.alarmTime);

        /*Set Alarm Status*/
        settingPageData.alarmStatus = clk_object->clock_inst.alarmStatus;
        
        /*DATE - SETTING PAGE DATA, USER SETTING, SETTING SAVE------------------------------------------------------------------*/
        /*Create a temporary variable to store current date*/
        date_t currentDate;
        
        /*Get current date and store into temp var currentDate*/
        clockGetDate(&clk_object->clock_inst, &currentDate);

        /*Set Date in User settings*/
        clk_object->usr_setting.dateNow = currentDate;
        
        













        
        break;
    
    default:
        break;
    }
}

/**
 * @brief Main Clock Alarm UI Object Constructor
 * 
 * @param clk_object Main Clock Alarm UI Object
 */
void clockAlarmUI_Constructor(ClockAlarmUI_t *const clk_object)
{
    /*Update State to STATE_TICKING*/
    UI_STATE_CHANGE(clk_object, STATE_TICKING);

    /*Create a Clock (i.e. Initalize clock_t element of main clock object)*/
    createClock(&clk_object->clock_inst);

    /*Create a GUI (i.e. Initialize the GUI button styles)*/
    guiStyleCreator(&clk_object->gui_inst);

    /*Assign label objects to each element of gui_inst of main clock object and callbacks to screen and main dropDownBtn*/
    guiLabelAndDropDownCreator(&clk_object->gui_inst);

    /*Initialize style for main page*/
    guiMainPageStyleInit(&clk_object->gui_inst);
}

/**
 * @brief Convert 24 Hour time format to 12 Hour time format
 * 
 * @param time24h 
 * @return uint32_t 
 */
static uint32_t convert24HourFormatTo12Hour(uint32_t time24h) 
{
    
    /*Place holder variables*/
    uint8_t hour;
    uint32_t time12h;

    /*Get the hour*/
    hour = GET_HOUR(time24h);

    /*If hour == 0, then 0(24 Hour) = 12AM(12 Hour), so just place 12, in the hours section*/
    if (hour == 0)
        time12h = time24h + (12UL * 3600UL);
    else {

        /*If hour(24 hour) less than or equal to 12, then time(24 hour) == time(12 Hour)*/
        if ((hour < 12UL) || (hour == 12UL))
            return time24h;
        
        /*To convert 24 Hour time to 12 Hour, subtract 12 from hours*/
        else
            time12h = time24h - (12UL * 3600UL);
    }
    return time12h;
}