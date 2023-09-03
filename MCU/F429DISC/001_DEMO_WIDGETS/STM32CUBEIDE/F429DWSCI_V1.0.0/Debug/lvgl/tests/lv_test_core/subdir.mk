################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/tests/lv_test_core/lv_test_core.c \
../lvgl/tests/lv_test_core/lv_test_font_loader.c \
../lvgl/tests/lv_test_core/lv_test_obj.c \
../lvgl/tests/lv_test_core/lv_test_style.c 

OBJS += \
./lvgl/tests/lv_test_core/lv_test_core.o \
./lvgl/tests/lv_test_core/lv_test_font_loader.o \
./lvgl/tests/lv_test_core/lv_test_obj.o \
./lvgl/tests/lv_test_core/lv_test_style.o 

C_DEPS += \
./lvgl/tests/lv_test_core/lv_test_core.d \
./lvgl/tests/lv_test_core/lv_test_font_loader.d \
./lvgl/tests/lv_test_core/lv_test_obj.d \
./lvgl/tests/lv_test_core/lv_test_style.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/tests/lv_test_core/%.o lvgl/tests/lv_test_core/%.su lvgl/tests/lv_test_core/%.cyclo: ../lvgl/tests/lv_test_core/%.c lvgl/tests/lv_test_core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-tests-2f-lv_test_core

clean-lvgl-2f-tests-2f-lv_test_core:
	-$(RM) ./lvgl/tests/lv_test_core/lv_test_core.cyclo ./lvgl/tests/lv_test_core/lv_test_core.d ./lvgl/tests/lv_test_core/lv_test_core.o ./lvgl/tests/lv_test_core/lv_test_core.su ./lvgl/tests/lv_test_core/lv_test_font_loader.cyclo ./lvgl/tests/lv_test_core/lv_test_font_loader.d ./lvgl/tests/lv_test_core/lv_test_font_loader.o ./lvgl/tests/lv_test_core/lv_test_font_loader.su ./lvgl/tests/lv_test_core/lv_test_obj.cyclo ./lvgl/tests/lv_test_core/lv_test_obj.d ./lvgl/tests/lv_test_core/lv_test_obj.o ./lvgl/tests/lv_test_core/lv_test_obj.su ./lvgl/tests/lv_test_core/lv_test_style.cyclo ./lvgl/tests/lv_test_core/lv_test_style.d ./lvgl/tests/lv_test_core/lv_test_style.o ./lvgl/tests/lv_test_core/lv_test_style.su

.PHONY: clean-lvgl-2f-tests-2f-lv_test_core

