################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/extra/widgets/calendar/lv_calendar.c \
../lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.c \
../lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.c 

OBJS += \
./lvgl/src/extra/widgets/calendar/lv_calendar.o \
./lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.o \
./lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.o 

C_DEPS += \
./lvgl/src/extra/widgets/calendar/lv_calendar.d \
./lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.d \
./lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/extra/widgets/calendar/%.o lvgl/src/extra/widgets/calendar/%.su lvgl/src/extra/widgets/calendar/%.cyclo: ../lvgl/src/extra/widgets/calendar/%.c lvgl/src/extra/widgets/calendar/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-extra-2f-widgets-2f-calendar

clean-lvgl-2f-src-2f-extra-2f-widgets-2f-calendar:
	-$(RM) ./lvgl/src/extra/widgets/calendar/lv_calendar.cyclo ./lvgl/src/extra/widgets/calendar/lv_calendar.d ./lvgl/src/extra/widgets/calendar/lv_calendar.o ./lvgl/src/extra/widgets/calendar/lv_calendar.su ./lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.cyclo ./lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.d ./lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.o ./lvgl/src/extra/widgets/calendar/lv_calendar_header_arrow.su ./lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.cyclo ./lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.d ./lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.o ./lvgl/src/extra/widgets/calendar/lv_calendar_header_dropdown.su

.PHONY: clean-lvgl-2f-src-2f-extra-2f-widgets-2f-calendar

