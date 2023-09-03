################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/examples/scroll/lv_example_scroll_1.c \
../lvgl/examples/scroll/lv_example_scroll_2.c \
../lvgl/examples/scroll/lv_example_scroll_3.c \
../lvgl/examples/scroll/lv_example_scroll_4.c \
../lvgl/examples/scroll/lv_example_scroll_5.c \
../lvgl/examples/scroll/lv_example_scroll_6.c 

OBJS += \
./lvgl/examples/scroll/lv_example_scroll_1.o \
./lvgl/examples/scroll/lv_example_scroll_2.o \
./lvgl/examples/scroll/lv_example_scroll_3.o \
./lvgl/examples/scroll/lv_example_scroll_4.o \
./lvgl/examples/scroll/lv_example_scroll_5.o \
./lvgl/examples/scroll/lv_example_scroll_6.o 

C_DEPS += \
./lvgl/examples/scroll/lv_example_scroll_1.d \
./lvgl/examples/scroll/lv_example_scroll_2.d \
./lvgl/examples/scroll/lv_example_scroll_3.d \
./lvgl/examples/scroll/lv_example_scroll_4.d \
./lvgl/examples/scroll/lv_example_scroll_5.d \
./lvgl/examples/scroll/lv_example_scroll_6.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/examples/scroll/%.o lvgl/examples/scroll/%.su lvgl/examples/scroll/%.cyclo: ../lvgl/examples/scroll/%.c lvgl/examples/scroll/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-examples-2f-scroll

clean-lvgl-2f-examples-2f-scroll:
	-$(RM) ./lvgl/examples/scroll/lv_example_scroll_1.cyclo ./lvgl/examples/scroll/lv_example_scroll_1.d ./lvgl/examples/scroll/lv_example_scroll_1.o ./lvgl/examples/scroll/lv_example_scroll_1.su ./lvgl/examples/scroll/lv_example_scroll_2.cyclo ./lvgl/examples/scroll/lv_example_scroll_2.d ./lvgl/examples/scroll/lv_example_scroll_2.o ./lvgl/examples/scroll/lv_example_scroll_2.su ./lvgl/examples/scroll/lv_example_scroll_3.cyclo ./lvgl/examples/scroll/lv_example_scroll_3.d ./lvgl/examples/scroll/lv_example_scroll_3.o ./lvgl/examples/scroll/lv_example_scroll_3.su ./lvgl/examples/scroll/lv_example_scroll_4.cyclo ./lvgl/examples/scroll/lv_example_scroll_4.d ./lvgl/examples/scroll/lv_example_scroll_4.o ./lvgl/examples/scroll/lv_example_scroll_4.su ./lvgl/examples/scroll/lv_example_scroll_5.cyclo ./lvgl/examples/scroll/lv_example_scroll_5.d ./lvgl/examples/scroll/lv_example_scroll_5.o ./lvgl/examples/scroll/lv_example_scroll_5.su ./lvgl/examples/scroll/lv_example_scroll_6.cyclo ./lvgl/examples/scroll/lv_example_scroll_6.d ./lvgl/examples/scroll/lv_example_scroll_6.o ./lvgl/examples/scroll/lv_example_scroll_6.su

.PHONY: clean-lvgl-2f-examples-2f-scroll

