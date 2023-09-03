################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lv_demos/src/lv_demo_benchmark/lv_demo_benchmark.c 

OBJS += \
./lv_demos/src/lv_demo_benchmark/lv_demo_benchmark.o 

C_DEPS += \
./lv_demos/src/lv_demo_benchmark/lv_demo_benchmark.d 


# Each subdirectory must supply rules for building sources it contributes
lv_demos/src/lv_demo_benchmark/%.o lv_demos/src/lv_demo_benchmark/%.su lv_demos/src/lv_demo_benchmark/%.cyclo: ../lv_demos/src/lv_demo_benchmark/%.c lv_demos/src/lv_demo_benchmark/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lv_demos-2f-src-2f-lv_demo_benchmark

clean-lv_demos-2f-src-2f-lv_demo_benchmark:
	-$(RM) ./lv_demos/src/lv_demo_benchmark/lv_demo_benchmark.cyclo ./lv_demos/src/lv_demo_benchmark/lv_demo_benchmark.d ./lv_demos/src/lv_demo_benchmark/lv_demo_benchmark.o ./lv_demos/src/lv_demo_benchmark/lv_demo_benchmark.su

.PHONY: clean-lv_demos-2f-src-2f-lv_demo_benchmark

