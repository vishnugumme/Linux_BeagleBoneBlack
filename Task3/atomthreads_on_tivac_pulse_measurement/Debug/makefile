################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /home/saish/Desktop/ccs1011/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.o" \
"./boards/ek-tm4c123gxl/board_setup.o" \
"./boards/ek-tm4c123gxl/gpio.o" \
"./boards/ek-tm4c123gxl/pll.o" \
"./boards/ek-tm4c123gxl/systick.o" \
"./boards/ek-tm4c123gxl/uart0.o" \
"./kernel/atomkernel.o" \
"./kernel/atommutex.o" \
"./kernel/atomqueue.o" \
"./kernel/atomsem.o" \
"./kernel/atomtimer.o" \
"./ports/cortex-m/atomport-asm.o" \
"./ports/cortex-m/atomport.o" \
"./ports/cortex-m/common/stubs.o" \
"./ports/cortex-m/common/tivac_con.o" \
"./ports/cortex-m/common/vector.o" \
-Wl,-T"../ek-tm4c123gxl.ld" \
$(GEN_CMDS__FLAG) \
-Wl,--start-group \
-lc \
-Wl,--end-group \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include boards/ek-tm4c123gxl/subdir_vars.mk
-include kernel/subdir_vars.mk
-include ports/cortex-m/subdir_vars.mk
-include ports/cortex-m/common/subdir_vars.mk
-include subdir_rules.mk
-include boards/ek-tm4c123gxl/subdir_rules.mk
-include kernel/subdir_rules.mk
-include ports/cortex-m/subdir_rules.mk
-include ports/cortex-m/common/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
atomthreads_on_tivac_pulse_measurement.out \

EXE_OUTPUTS__QUOTED += \
"atomthreads_on_tivac_pulse_measurement.out" \

BIN_OUTPUTS += \
atomthreads_on_tivac_pulse_measurement.hex \

BIN_OUTPUTS__QUOTED += \
"atomthreads_on_tivac_pulse_measurement.hex" \


# All Target
all: $(OBJS) $(LD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "atomthreads_on_tivac_pulse_measurement.out"

# Tool invocations
atomthreads_on_tivac_pulse_measurement.out: $(OBJS) $(LD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: GNU Linker'
	"/home/saish/Desktop/ccs1011/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc-7.2.1" -DPART_TM4C123GH6PM -DATOM_STACK_CHECKING -DTESTS_LOG_STACK_USAGE -D__NEWLIB__ -DMST_SIZE=0x400 -DSTD_CON=UART0 -Os -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wl,-Map,"atomthreads_on_tivac_pulse_measurement.map" -mfloat-abi=hard -o"atomthreads_on_tivac_pulse_measurement.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

atomthreads_on_tivac_pulse_measurement.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: GNU Objcopy Utility'
	"/home/saish/Desktop/ccs1011/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-objcopy"  $(EXE_OUTPUTS__QUOTED) "atomthreads_on_tivac_pulse_measurement.hex"
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "ports/cortex-m/atomport-asm.d" 
	-$(RM) "main.o" "boards/ek-tm4c123gxl/board_setup.o" "boards/ek-tm4c123gxl/gpio.o" "boards/ek-tm4c123gxl/pll.o" "boards/ek-tm4c123gxl/systick.o" "boards/ek-tm4c123gxl/uart0.o" "kernel/atomkernel.o" "kernel/atommutex.o" "kernel/atomqueue.o" "kernel/atomsem.o" "kernel/atomtimer.o" "ports/cortex-m/atomport-asm.o" "ports/cortex-m/atomport.o" "ports/cortex-m/common/stubs.o" "ports/cortex-m/common/tivac_con.o" "ports/cortex-m/common/vector.o" 
	-$(RM) "main.d" "boards/ek-tm4c123gxl/board_setup.d" "boards/ek-tm4c123gxl/gpio.d" "boards/ek-tm4c123gxl/pll.d" "boards/ek-tm4c123gxl/systick.d" "boards/ek-tm4c123gxl/uart0.d" "kernel/atomkernel.d" "kernel/atommutex.d" "kernel/atomqueue.d" "kernel/atomsem.d" "kernel/atomtimer.d" "ports/cortex-m/atomport.d" "ports/cortex-m/common/stubs.d" "ports/cortex-m/common/tivac_con.d" "ports/cortex-m/common/vector.d" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-arm-none-eabi-size atomthreads_on_tivac_pulse_measurement.out
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

