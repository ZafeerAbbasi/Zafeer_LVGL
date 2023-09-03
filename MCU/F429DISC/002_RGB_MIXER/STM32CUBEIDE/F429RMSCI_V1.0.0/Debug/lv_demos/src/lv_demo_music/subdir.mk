################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lv_demos/src/lv_demo_music/lv_demo_music.c \
../lv_demos/src/lv_demo_music/lv_demo_music_list.c \
../lv_demos/src/lv_demo_music/lv_demo_music_main.c 

OBJS += \
./lv_demos/src/lv_demo_music/lv_demo_music.o \
./lv_demos/src/lv_demo_music/lv_demo_music_list.o \
./lv_demos/src/lv_demo_music/lv_demo_music_main.o 

C_DEPS += \
./lv_demos/src/lv_demo_music/lv_demo_music.d \
./lv_demos/src/lv_demo_music/lv_demo_music_list.d \
./lv_demos/src/lv_demo_music/lv_demo_music_main.d 


# Each subdirectory must supply rules for building sources it contributes
lv_demos/src/lv_demo_music/%.o lv_demos/src/lv_demo_music/%.su lv_demos/src/lv_demo_music/%.cyclo: ../lv_demos/src/lv_demo_music/%.c lv_demos/src/lv_demo_music/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lv_demos-2f-src-2f-lv_demo_music

clean-lv_demos-2f-src-2f-lv_demo_music:
	-$(RM) ./lv_demos/src/lv_demo_music/lv_demo_music.cyclo ./lv_demos/src/lv_demo_music/lv_demo_music.d ./lv_demos/src/lv_demo_music/lv_demo_music.o ./lv_demos/src/lv_demo_music/lv_demo_music.su ./lv_demos/src/lv_demo_music/lv_demo_music_list.cyclo ./lv_demos/src/lv_demo_music/lv_demo_music_list.d ./lv_demos/src/lv_demo_music/lv_demo_music_list.o ./lv_demos/src/lv_demo_music/lv_demo_music_list.su ./lv_demos/src/lv_demo_music/lv_demo_music_main.cyclo ./lv_demos/src/lv_demo_music/lv_demo_music_main.d ./lv_demos/src/lv_demo_music/lv_demo_music_main.o ./lv_demos/src/lv_demo_music/lv_demo_music_main.su

.PHONY: clean-lv_demos-2f-src-2f-lv_demo_music

