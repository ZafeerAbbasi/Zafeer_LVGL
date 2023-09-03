################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lv_demos/src/lv_demo_widgets/assets/img_clothes.c \
../lv_demos/src/lv_demo_widgets/assets/img_demo_widgets_avatar.c \
../lv_demos/src/lv_demo_widgets/assets/img_lvgl_logo.c 

OBJS += \
./lv_demos/src/lv_demo_widgets/assets/img_clothes.o \
./lv_demos/src/lv_demo_widgets/assets/img_demo_widgets_avatar.o \
./lv_demos/src/lv_demo_widgets/assets/img_lvgl_logo.o 

C_DEPS += \
./lv_demos/src/lv_demo_widgets/assets/img_clothes.d \
./lv_demos/src/lv_demo_widgets/assets/img_demo_widgets_avatar.d \
./lv_demos/src/lv_demo_widgets/assets/img_lvgl_logo.d 


# Each subdirectory must supply rules for building sources it contributes
lv_demos/src/lv_demo_widgets/assets/%.o lv_demos/src/lv_demo_widgets/assets/%.su lv_demos/src/lv_demo_widgets/assets/%.cyclo: ../lv_demos/src/lv_demo_widgets/assets/%.c lv_demos/src/lv_demo_widgets/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lv_demos-2f-src-2f-lv_demo_widgets-2f-assets

clean-lv_demos-2f-src-2f-lv_demo_widgets-2f-assets:
	-$(RM) ./lv_demos/src/lv_demo_widgets/assets/img_clothes.cyclo ./lv_demos/src/lv_demo_widgets/assets/img_clothes.d ./lv_demos/src/lv_demo_widgets/assets/img_clothes.o ./lv_demos/src/lv_demo_widgets/assets/img_clothes.su ./lv_demos/src/lv_demo_widgets/assets/img_demo_widgets_avatar.cyclo ./lv_demos/src/lv_demo_widgets/assets/img_demo_widgets_avatar.d ./lv_demos/src/lv_demo_widgets/assets/img_demo_widgets_avatar.o ./lv_demos/src/lv_demo_widgets/assets/img_demo_widgets_avatar.su ./lv_demos/src/lv_demo_widgets/assets/img_lvgl_logo.cyclo ./lv_demos/src/lv_demo_widgets/assets/img_lvgl_logo.d ./lv_demos/src/lv_demo_widgets/assets/img_lvgl_logo.o ./lv_demos/src/lv_demo_widgets/assets/img_lvgl_logo.su

.PHONY: clean-lv_demos-2f-src-2f-lv_demo_widgets-2f-assets

