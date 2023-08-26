/*
# ##############################################################################
# File: main.c                                                                 #
# Project: src                                                                 #
# Created Date: Friday, August 18th 2023, 3:59:11 am                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Tuesday, August 22nd 2023, 8:24:34 pm                         #
# Modified By: Zafeer Abbasi                                                   #
# ----------------------------------------------                               #
# Copyright (c) 2023 Zafeer.A                                                  #
# ----------------------------------------------                               #
# HISTORY:                                                                     #
 */

/*
# ##############################################################################
# File: main.c                                                                 #
# Project: src                                                                 #
# Created Date: Friday, August 18th 2023, 3:59:11 am                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Tuesday, August 22nd 2023, 8:24:34 pm                         #
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
#include "lv_conf.h"
#include "examples/lv_examples.h"
#include "demos/lv_demos.h"

int main(void)
{
  lv_init();
  
  hal_setup();
  
  lv_demo_widgets();

	hal_loop();
}
