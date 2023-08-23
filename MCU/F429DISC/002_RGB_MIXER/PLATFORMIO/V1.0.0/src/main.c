/*
# ##############################################################################
# File: main.c                                                                 #
# Project: src                                                                 #
# Created Date: Friday, August 18th 2023, 3:59:11 am                           #
# Author: Zafeer Abbasi                                                        #
# ----------------------------------------------                               #
# Last Modified: Wednesday, August 23rd 2023, 2:55:29 am                       #
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
# Last Modified: Wednesday, August 23rd 2023, 2:55:29 am                       #
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
#include "rgb_mixer.h"

int main(void)
{
  lv_init();
  
  hal_setup();

  /**
   * @brief Set the rotation to 270 degrees
   * 
   * @return lv_disp_set_rotation(,) rgb_mixer_create_ui() 
   */
  lv_disp_set_rotation(lv_disp_get_default(),LV_DISP_ROT_90);
  
  rgb_mixer_create_ui();

	hal_loop();
}
