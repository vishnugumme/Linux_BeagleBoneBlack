################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
boards/ek-tm4c123gxl/%.o: ../boards/ek-tm4c123gxl/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"/home/saish/Desktop/ccs1011/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/bin/arm-none-eabi-gcc-7.2.1" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -DATOM_STACK_CHECKING -DTESTS_LOG_STACK_USAGE -D__NEWLIB__ -DMST_SIZE=0x400 -DSTD_CON=UART0 -I"/home/saish/workspace_v10/atomthreads_on_tivac_interrupt_latency" -I"/home/saish/Desktop/ccs1011/ccs/tools/compiler/gcc-arm-none-eabi-7-2017-q4-major/arm-none-eabi/include" -I"/home/saish/ti/TivaWare_C_Series-2.1.4.178" -I"/home/saish/workspace_v10/atomthreads_on_tivac_interrupt_latency/kernel" -I"/home/saish/workspace_v10/atomthreads_on_tivac_interrupt_latency/ports/cortex-m" -I"/home/saish/workspace_v10/atomthreads_on_tivac_interrupt_latency/ports/cortex-m/common" -I"/home/saish/workspace_v10/atomthreads_on_tivac_interrupt_latency/boards/ek-tm4c123gxl" -Os -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -std=c99 $(GEN_OPTS__FLAG) -o"$@" "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


