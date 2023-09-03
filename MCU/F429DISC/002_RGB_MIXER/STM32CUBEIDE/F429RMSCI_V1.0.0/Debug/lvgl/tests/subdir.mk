################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/tests/lv_test_assert.c \
../lvgl/tests/lv_test_main.c 

OBJS += \
./lvgl/tests/lv_test_assert.o \
./lvgl/tests/lv_test_main.o 

C_DEPS += \
./lvgl/tests/lv_test_assert.d \
./lvgl/tests/lv_test_main.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/tests/%.o lvgl/tests/%.su lvgl/tests/%.cyclo: ../lvgl/tests/%.c lvgl/tests/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-tests

clean-lvgl-2f-tests:
	-$(RM) ./lvgl/tests/lv_test_assert.cyclo ./lvgl/tests/lv_test_assert.d ./lvgl/tests/lv_test_assert.o ./lvgl/tests/lv_test_assert.su ./lvgl/tests/lv_test_main.cyclo ./lvgl/tests/lv_test_main.d ./lvgl/tests/lv_test_main.o ./lvgl/tests/lv_test_main.su

.PHONY: clean-lvgl-2f-tests

