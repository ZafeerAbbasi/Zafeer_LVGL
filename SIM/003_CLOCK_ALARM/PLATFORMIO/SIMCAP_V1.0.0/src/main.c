/*
# ##############################################################################
# File: main.c                                                                 #
# Project: src                                                                 #
# Created Date: Friday, August 18th 2023, 4:51:03 pm                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Monday, September 4th 2023, 1:18:55 pm                        #
# Modified By: Zafeer Abbasi                                                   #
# ----------------------------------------------                               #
# Copyright (c) 2023 Zafeer.A                                                  #
# ----------------------------------------------                               #
# HISTORY:                                                                     #
*/

/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "lvgl.h"
#include "app_hal.h"
#include "rgb_mixer.h"
#include "demos/lv_demos.h"
#include <stdio.h>
#include <stdlib.h>
#include "examples/lv_examples.h"
#include "project_clock_alarm.h"
#include "gui.h"
#include "clock.h"

/*Main Clock Alarm UI Application object*/
ClockAlarmUI_t clockAlarmUI_inst;

int main(void)
{
	lv_init();
  
  hal_setup();

  /*Main Clock Alarm UI Object Constructor*/
  clockAlarmUI_Constructor(&clockAlarmUI_inst);

	hal_loop();
}
