################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/colorwheel/lv_example_colorwheel_1.c 

OBJS += \
./lvgl/examples/widgets/colorwheel/lv_example_colorwheel_1.o 

C_DEPS += \
./lvgl/examples/widgets/colorwheel/lv_example_colorwheel_1.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/colorwheel/%.o lvgl/examples/widgets/colorwheel/%.su lvgl/examples/widgets/colorwheel/%.cyclo: ../lvgl/examples/widgets/colorwheel/%.c lvgl/examples/widgets/colorwheel/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-colorwheel

clean-lvgl-2f-examples-2f-widgets-2f-colorwheel:
	-$(RM) ./lvgl/examples/widgets/colorwheel/lv_example_colorwheel_1.cyclo ./lvgl/examples/widgets/colorwheel/lv_example_colorwheel_1.d ./lvgl/examples/widgets/colorwheel/lv_example_colorwheel_1.o ./lvgl/examples/widgets/colorwheel/lv_example_colorwheel_1.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-colorwheel

