################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lvgl/src/gpu/lv_gpu_nxp_pxp.c \
../lvgl/src/gpu/lv_gpu_nxp_pxp_osa.c \
../lvgl/src/gpu/lv_gpu_nxp_vglite.c \
../lvgl/src/gpu/lv_gpu_stm32_dma2d.c 

OBJS += \
./lvgl/src/gpu/lv_gpu_nxp_pxp.o \
./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.o \
./lvgl/src/gpu/lv_gpu_nxp_vglite.o \
./lvgl/src/gpu/lv_gpu_stm32_dma2d.o 

C_DEPS += \
./lvgl/src/gpu/lv_gpu_nxp_pxp.d \
./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.d \
./lvgl/src/gpu/lv_gpu_nxp_vglite.d \
./lvgl/src/gpu/lv_gpu_stm32_dma2d.d 


# Each subdirectory must supply rules for building sources it contributes
lvgl/src/gpu/%.o lvgl/src/gpu/%.su lvgl/src/gpu/%.cyclo: ../lvgl/src/gpu/%.c lvgl/src/gpu/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F429ZITx -DSTM32F429I_DISCO -DSTM32F4 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/core" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/CMSIS/device" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc" -I"C:/Users/zafee/Documents/GitHub/Zafeer_LVGL/MCU/F429DISC/002_RGB_MIXER/STM32CUBEIDE/F429RMSCI_V1.0.0/HAL_Driver/Inc/Legacy" -O3 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-lvgl-2f-src-2f-gpu

clean-lvgl-2f-src-2f-gpu:
	-$(RM) ./lvgl/src/gpu/lv_gpu_nxp_pxp.cyclo ./lvgl/src/gpu/lv_gpu_nxp_pxp.d ./lvgl/src/gpu/lv_gpu_nxp_pxp.o ./lvgl/src/gpu/lv_gpu_nxp_pxp.su ./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.cyclo ./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.d ./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.o ./lvgl/src/gpu/lv_gpu_nxp_pxp_osa.su ./lvgl/src/gpu/lv_gpu_nxp_vglite.cyclo ./lvgl/src/gpu/lv_gpu_nxp_vglite.d ./lvgl/src/gpu/lv_gpu_nxp_vglite.o ./lvgl/src/gpu/lv_gpu_nxp_vglite.su ./lvgl/src/gpu/lv_gpu_stm32_dma2d.cyclo ./lvgl/src/gpu/lv_gpu_stm32_dma2d.d ./lvgl/src/gpu/lv_gpu_stm32_dma2d.o ./lvgl/src/gpu/lv_gpu_stm32_dma2d.su

.PHONY: clean-lvgl-2f-src-2f-gpu

