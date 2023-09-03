################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal_stm_lvgl/tft/ili9341.c \
../hal_stm_lvgl/tft/tft.c 

OBJS += \
./hal_stm_lvgl/tft/ili9341.o \
./hal_stm_lvgl/tft/tft.o 

C_DEPS += \
./hal_stm_lvgl/tft/ili9341.d \
./hal_stm_lvgl/tft/tft.d 


# Each subdirectory must supply rules for building sources it contributes
hal_stm_lvgl/tft/%.o hal_stm_lvgl/tft/%.su hal_stm_lvgl/tft/%.cyclo: ../hal_stm_lvgl/tft/%.c hal_stm_lvgl/tft/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-hal_stm_lvgl-2f-tft

clean-hal_stm_lvgl-2f-tft:
	-$(RM) ./hal_stm_lvgl/tft/ili9341.cyclo ./hal_stm_lvgl/tft/ili9341.d ./hal_stm_lvgl/tft/ili9341.o ./hal_stm_lvgl/tft/ili9341.su ./hal_stm_lvgl/tft/tft.cyclo ./hal_stm_lvgl/tft/tft.d ./hal_stm_lvgl/tft/tft.o ./hal_stm_lvgl/tft/tft.su

.PHONY: clean-hal_stm_lvgl-2f-tft

