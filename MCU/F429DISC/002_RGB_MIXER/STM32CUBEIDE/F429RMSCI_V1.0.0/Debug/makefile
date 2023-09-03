################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include lvgl/tests/lv_test_widgets/subdir.mk
-include lvgl/tests/lv_test_fonts/subdir.mk
-include lvgl/tests/lv_test_core/subdir.mk
-include lvgl/tests/subdir.mk
-include lvgl/src/widgets/subdir.mk
-include lvgl/src/misc/subdir.mk
-include lvgl/src/hal/subdir.mk
-include lvgl/src/gpu/subdir.mk
-include lvgl/src/font/subdir.mk
-include lvgl/src/extra/widgets/win/subdir.mk
-include lvgl/src/extra/widgets/tileview/subdir.mk
-include lvgl/src/extra/widgets/tabview/subdir.mk
-include lvgl/src/extra/widgets/spinner/subdir.mk
-include lvgl/src/extra/widgets/spinbox/subdir.mk
-include lvgl/src/extra/widgets/span/subdir.mk
-include lvgl/src/extra/widgets/msgbox/subdir.mk
-include lvgl/src/extra/widgets/meter/subdir.mk
-include lvgl/src/extra/widgets/list/subdir.mk
-include lvgl/src/extra/widgets/led/subdir.mk
-include lvgl/src/extra/widgets/keyboard/subdir.mk
-include lvgl/src/extra/widgets/imgbtn/subdir.mk
-include lvgl/src/extra/widgets/colorwheel/subdir.mk
-include lvgl/src/extra/widgets/chart/subdir.mk
-include lvgl/src/extra/widgets/calendar/subdir.mk
-include lvgl/src/extra/widgets/animimg/subdir.mk
-include lvgl/src/extra/themes/mono/subdir.mk
-include lvgl/src/extra/themes/default/subdir.mk
-include lvgl/src/extra/themes/basic/subdir.mk
-include lvgl/src/extra/layouts/grid/subdir.mk
-include lvgl/src/extra/layouts/flex/subdir.mk
-include lvgl/src/extra/subdir.mk
-include lvgl/src/draw/subdir.mk
-include lvgl/src/core/subdir.mk
-include lvgl/examples/widgets/win/subdir.mk
-include lvgl/examples/widgets/tileview/subdir.mk
-include lvgl/examples/widgets/textarea/subdir.mk
-include lvgl/examples/widgets/tabview/subdir.mk
-include lvgl/examples/widgets/table/subdir.mk
-include lvgl/examples/widgets/switch/subdir.mk
-include lvgl/examples/widgets/spinner/subdir.mk
-include lvgl/examples/widgets/spinbox/subdir.mk
-include lvgl/examples/widgets/span/subdir.mk
-include lvgl/examples/widgets/slider/subdir.mk
-include lvgl/examples/widgets/roller/subdir.mk
-include lvgl/examples/widgets/obj/subdir.mk
-include lvgl/examples/widgets/msgbox/subdir.mk
-include lvgl/examples/widgets/meter/subdir.mk
-include lvgl/examples/widgets/list/subdir.mk
-include lvgl/examples/widgets/line/subdir.mk
-include lvgl/examples/widgets/led/subdir.mk
-include lvgl/examples/widgets/label/subdir.mk
-include lvgl/examples/widgets/keyboard/subdir.mk
-include lvgl/examples/widgets/imgbtn/subdir.mk
-include lvgl/examples/widgets/img/subdir.mk
-include lvgl/examples/widgets/dropdown/subdir.mk
-include lvgl/examples/widgets/colorwheel/subdir.mk
-include lvgl/examples/widgets/checkbox/subdir.mk
-include lvgl/examples/widgets/chart/subdir.mk
-include lvgl/examples/widgets/canvas/subdir.mk
-include lvgl/examples/widgets/calendar/subdir.mk
-include lvgl/examples/widgets/btnmatrix/subdir.mk
-include lvgl/examples/widgets/btn/subdir.mk
-include lvgl/examples/widgets/bar/subdir.mk
-include lvgl/examples/widgets/arc/subdir.mk
-include lvgl/examples/widgets/animimg/subdir.mk
-include lvgl/examples/styles/subdir.mk
-include lvgl/examples/scroll/subdir.mk
-include lvgl/examples/porting/subdir.mk
-include lvgl/examples/layouts/grid/subdir.mk
-include lvgl/examples/layouts/flex/subdir.mk
-include lvgl/examples/get_started/subdir.mk
-include lvgl/examples/event/subdir.mk
-include lvgl/examples/assets/subdir.mk
-include lvgl/examples/anim/subdir.mk
-include lv_demos/src/lv_demo_widgets/assets/subdir.mk
-include lv_demos/src/lv_demo_widgets/subdir.mk
-include lv_demos/src/lv_demo_stress/assets/subdir.mk
-include lv_demos/src/lv_demo_stress/subdir.mk
-include lv_demos/src/lv_demo_music/assets/subdir.mk
-include lv_demos/src/lv_demo_music/subdir.mk
-include lv_demos/src/lv_demo_keypad_encoder/subdir.mk
-include lv_demos/src/lv_demo_benchmark/subdir.mk
-include hal_stm_lvgl/touchpad/subdir.mk
-include hal_stm_lvgl/tft/subdir.mk
-include hal_stm_lvgl/subdir.mk
-include HAL_Driver/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := F429RMSCI_V1.0.0
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
F429RMSCI_V1.0.0.elf \

MAP_FILES += \
F429RMSCI_V1.0.0.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
F429RMSCI_V1.0.0.list \


# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: F429RMSCI_V1.0.0.elf secondary-outputs

# Tool invocations
F429RMSCI_V1.0.0.elf F429RMSCI_V1.0.0.map: $(OBJS) $(USER_OBJS) C:\Users\zafee\Documents\GitHub\Zafeer_LVGL\MCU\F429DISC\002_RGB_MIXER\STM32CUBEIDE\F429RMSCI_V1.0.0\LinkerScript.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "F429RMSCI_V1.0.0.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\zafee\Documents\GitHub\Zafeer_LVGL\MCU\F429DISC\002_RGB_MIXER\STM32CUBEIDE\F429RMSCI_V1.0.0\LinkerScript.ld" --specs=nosys.specs -Wl,-Map="F429RMSCI_V1.0.0.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

F429RMSCI_V1.0.0.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "F429RMSCI_V1.0.0.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) F429RMSCI_V1.0.0.elf F429RMSCI_V1.0.0.list F429RMSCI_V1.0.0.map default.size.stdout
	-@echo ' '

post-build:
	arm-none-eabi-size "F429RMSCI_V1.0.0.elf"
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified post-build

-include ../makefile.targets
