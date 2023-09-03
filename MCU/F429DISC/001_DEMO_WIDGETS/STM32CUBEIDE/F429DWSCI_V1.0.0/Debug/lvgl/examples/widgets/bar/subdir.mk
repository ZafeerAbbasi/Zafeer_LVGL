################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/widgets/bar/lv_example_bar_1.c \
../lvgl/examples/widgets/bar/lv_example_bar_2.c \
../lvgl/examples/widgets/bar/lv_example_bar_3.c \
../lvgl/examples/widgets/bar/lv_example_bar_4.c \
../lvgl/examples/widgets/bar/lv_example_bar_5.c \
../lvgl/examples/widgets/bar/lv_example_bar_6.c 

OBJS += \
./lvgl/examples/widgets/bar/lv_example_bar_1.o \
./lvgl/examples/widgets/bar/lv_example_bar_2.o \
./lvgl/examples/widgets/bar/lv_example_bar_3.o \
./lvgl/examples/widgets/bar/lv_example_bar_4.o \
./lvgl/examples/widgets/bar/lv_example_bar_5.o \
./lvgl/examples/widgets/bar/lv_example_bar_6.o 

C_DEPS += \
./lvgl/examples/widgets/bar/lv_example_bar_1.d \
./lvgl/examples/widgets/bar/lv_example_bar_2.d \
./lvgl/examples/widgets/bar/lv_example_bar_3.d \
./lvgl/examples/widgets/bar/lv_example_bar_4.d \
./lvgl/examples/widgets/bar/lv_example_bar_5.d \
./lvgl/examples/widgets/bar/lv_example_bar_6.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/widgets/bar/%.o lvgl/examples/widgets/bar/%.su lvgl/examples/widgets/bar/%.cyclo: ../lvgl/examples/widgets/bar/%.c lvgl/examples/widgets/bar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-widgets-2f-bar

clean-lvgl-2f-examples-2f-widgets-2f-bar:
	-$(RM) ./lvgl/examples/widgets/bar/lv_example_bar_1.cyclo ./lvgl/examples/widgets/bar/lv_example_bar_1.d ./lvgl/examples/widgets/bar/lv_example_bar_1.o ./lvgl/examples/widgets/bar/lv_example_bar_1.su ./lvgl/examples/widgets/bar/lv_example_bar_2.cyclo ./lvgl/examples/widgets/bar/lv_example_bar_2.d ./lvgl/examples/widgets/bar/lv_example_bar_2.o ./lvgl/examples/widgets/bar/lv_example_bar_2.su ./lvgl/examples/widgets/bar/lv_example_bar_3.cyclo ./lvgl/examples/widgets/bar/lv_example_bar_3.d ./lvgl/examples/widgets/bar/lv_example_bar_3.o ./lvgl/examples/widgets/bar/lv_example_bar_3.su ./lvgl/examples/widgets/bar/lv_example_bar_4.cyclo ./lvgl/examples/widgets/bar/lv_example_bar_4.d ./lvgl/examples/widgets/bar/lv_example_bar_4.o ./lvgl/examples/widgets/bar/lv_example_bar_4.su ./lvgl/examples/widgets/bar/lv_example_bar_5.cyclo ./lvgl/examples/widgets/bar/lv_example_bar_5.d ./lvgl/examples/widgets/bar/lv_example_bar_5.o ./lvgl/examples/widgets/bar/lv_example_bar_5.su ./lvgl/examples/widgets/bar/lv_example_bar_6.cyclo ./lvgl/examples/widgets/bar/lv_example_bar_6.d ./lvgl/examples/widgets/bar/lv_example_bar_6.o ./lvgl/examples/widgets/bar/lv_example_bar_6.su

.PHONY: clean-lvgl-2f-examples-2f-widgets-2f-bar

