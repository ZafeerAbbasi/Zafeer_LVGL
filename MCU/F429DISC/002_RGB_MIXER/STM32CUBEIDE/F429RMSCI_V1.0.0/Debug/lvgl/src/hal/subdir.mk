################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/hal/lv_hal_disp.c \
../lvgl/src/hal/lv_hal_indev.c \
../lvgl/src/hal/lv_hal_tick.c 

OBJS += \
./lvgl/src/hal/lv_hal_disp.o \
./lvgl/src/hal/lv_hal_indev.o \
./lvgl/src/hal/lv_hal_tick.o 

C_DEPS += \
./lvgl/src/hal/lv_hal_disp.d \
./lvgl/src/hal/lv_hal_indev.d \
./lvgl/src/hal/lv_hal_tick.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/hal/%.o lvgl/src/hal/%.su lvgl/src/hal/%.cyclo: ../lvgl/src/hal/%.c lvgl/src/hal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-hal

clean-lvgl-2f-src-2f-hal:
	-$(RM) ./lvgl/src/hal/lv_hal_disp.cyclo ./lvgl/src/hal/lv_hal_disp.d ./lvgl/src/hal/lv_hal_disp.o ./lvgl/src/hal/lv_hal_disp.su ./lvgl/src/hal/lv_hal_indev.cyclo ./lvgl/src/hal/lv_hal_indev.d ./lvgl/src/hal/lv_hal_indev.o ./lvgl/src/hal/lv_hal_indev.su ./lvgl/src/hal/lv_hal_tick.cyclo ./lvgl/src/hal/lv_hal_tick.d ./lvgl/src/hal/lv_hal_tick.o ./lvgl/src/hal/lv_hal_tick.su

.PHONY: clean-lvgl-2f-src-2f-hal

