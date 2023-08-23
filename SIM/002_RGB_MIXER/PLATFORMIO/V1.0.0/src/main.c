/*
# ##############################################################################
# File: main.c                                                                 #
# Project: src                                                                 #
# Created Date: Friday, August 18th 2023, 4:51:03 pm                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Wednesday, August 23rd 2023, 1:55:31 am                       #
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

int main(void)
{
	lv_init();
  
  hal_setup();

  rgb_mixer_create_ui();

	hal_loop();
}
