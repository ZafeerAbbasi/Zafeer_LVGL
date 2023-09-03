################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.c \
../lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.c \
../lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.c 

OBJS += \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.o \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.o \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.o 

C_DEPS += \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.d \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.d \
./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/btnmatrix/%.o lvgl/examples/widgets/btnmatrix/%.su lvgl/examples/widgets/btnmatrix/%.cyclo: ../lvgl/examples/widgets/btnmatrix/%.c lvgl/examples/widgets/btnmatrix/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-btnmatrix

clean-lvgl-2f-examples-2f-widgets-2f-btnmatrix:
	-$(RM) ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.cyclo ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.d ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.o ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_1.su ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.cyclo ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.d ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.o ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_2.su ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.cyclo ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.d ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.o ./lvgl/examples/widgets/btnmatrix/lv_example_btnmatrix_3.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-btnmatrix

