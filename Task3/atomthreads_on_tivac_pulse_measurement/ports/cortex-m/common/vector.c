/*
 * vector.c
 *
 *  Created on: 31-May-2020
 *      Author: J. Shankarappa
 *
 *  Adapted from libopencm3 project
 *
 */
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "nvic.h"
#include "vector.h"

#ifndef HWREG
#define HWREG(x) (*((volatile uint32_t *)(x)))
#endif

/* Less common symbols exported by the linker script(s): */
typedef void (*funcp_t) (void);
extern funcp_t __preinit_array_start, __preinit_array_end;
extern funcp_t __init_array_start, __init_array_end;
extern funcp_t __fini_array_start, __fini_array_end;

int main(void);
void blocking_handler(void);
void null_handler(void);

__attribute__ ((section(".vectors")))
vector_table_t vector_table = {
    .initial_sp_value = &_stack,
    .reset = reset_handler,
    .nmi = nmi_handler,
    .hard_fault = hard_fault_handler,

/* Those are defined only on CM3 or CM4 */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
    .memory_manage_fault = mem_manage_handler,
    .bus_fault = bus_fault_handler,
    .usage_fault = usage_fault_handler,
    .debug_monitor = debug_monitor_handler,
#endif

    .sv_call = sv_call_handler,
    .pend_sv = pend_sv_handler,
    .systick = sys_tick_handler,
    .irq = {
        IRQ_HANDLERS
    }
};

void __attribute__ ((weak)) reset_handler(void)
{
    volatile unsigned *src, *dest;
    funcp_t *fp;

    for (src = &_data_loadaddr, dest = &_data;
        dest < &_edata;
        src++, dest++) {
        *dest = *src;
    }

    while (dest < &_ebss) {
        *dest++ = 0;
    }

    /* Ensure 8-byte alignment of stack pointer on interrupts */
    /* Enabled by default on most Cortex-M parts, but not M3 r1 */
    NVIC_CFG_CTRL_R |= SCB_CCR_STKALIGN;

    /* Enable the floating-point unit.  This must be done here to handle the
       case where main() uses floating-point */
    HWREG(0xE000ED88) = ((HWREG(0xE000ED88) & ~0x00F00000) | 0x00F00000);

    /* Constructors. */
    for (fp = &__preinit_array_start; fp < &__preinit_array_end; fp++) {
        (*fp)();
    }
    for (fp = &__init_array_start; fp < &__init_array_end; fp++) {
        (*fp)();
    }

    /* Call the application's entry point. */
    (void)main();

    /* Destructors. */
    for (fp = &__fini_array_start; fp < &__fini_array_end; fp++) {
        (*fp)();
    }

}

void blocking_handler(void)
{
    while (1);
}

void null_handler(void)
{
    /* Do nothing. */
}

void gpioa_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiob_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioc_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiod_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioe_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart0_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart1_isr(void) __attribute__((weak, alias("blocking_handler")));
void ssi0_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c0_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm0_fault_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm0_0_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm0_1_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm0_2_isr(void) __attribute__((weak, alias("blocking_handler")));
void qei0_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc0ss0_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc0ss1_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc0ss2_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc0ss3_isr(void) __attribute__((weak, alias("blocking_handler")));
void watchdog_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer0a_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer0b_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer1a_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer1b_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer2a_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer2b_isr(void) __attribute__((weak, alias("blocking_handler")));
void comp0_isr(void) __attribute__((weak, alias("blocking_handler")));
void comp1_isr(void) __attribute__((weak, alias("blocking_handler")));
void comp2_isr(void) __attribute__((weak, alias("blocking_handler")));
void sysctl_isr(void) __attribute__((weak, alias("blocking_handler")));
void flash_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiof_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiog_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioh_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart2_isr(void) __attribute__((weak, alias("blocking_handler")));
void ssi1_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer3a_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer3b_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c1_isr(void) __attribute__((weak, alias("blocking_handler")));
void qei1_isr(void) __attribute__((weak, alias("blocking_handler")));
void can0_isr(void) __attribute__((weak, alias("blocking_handler")));
void can1_isr(void) __attribute__((weak, alias("blocking_handler")));
void can2_isr(void) __attribute__((weak, alias("blocking_handler")));
void eth_isr(void) __attribute__((weak, alias("blocking_handler")));
void hibernate_isr(void) __attribute__((weak, alias("blocking_handler")));
void usb0_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm0_3_isr(void) __attribute__((weak, alias("blocking_handler")));
void udma_isr(void) __attribute__((weak, alias("blocking_handler")));
void udmaerr_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc1ss0_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc1ss1_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc1ss2_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc1ss3_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2s0_isr(void) __attribute__((weak, alias("blocking_handler")));
void epi0_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioj_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiok_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiol_isr(void) __attribute__((weak, alias("blocking_handler")));
void ssi2_isr(void) __attribute__((weak, alias("blocking_handler")));
void ssi3_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart3_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart4_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart5_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart6_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart7_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c2_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c3_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer4a_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer4b_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer5a_isr(void) __attribute__((weak, alias("blocking_handler")));
void timer5b_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer0a_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer0b_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer1a_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer1b_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer2a_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer2b_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer3a_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer3b_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer4a_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer4b_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer5a_isr(void) __attribute__((weak, alias("blocking_handler")));
void wtimer5b_isr(void) __attribute__((weak, alias("blocking_handler")));
void sysexc_isr(void) __attribute__((weak, alias("blocking_handler")));
void peci0_isr(void) __attribute__((weak, alias("blocking_handler")));
void lpc0_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c4_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c5_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiom_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpion_isr(void) __attribute__((weak, alias("blocking_handler")));
void fan0_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop0_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop1_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop2_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop3_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop4_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop5_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop6_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpiop7_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq0_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq1_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq2_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq3_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq4_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq5_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq6_isr(void) __attribute__((weak, alias("blocking_handler")));
void gpioq7_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm1_0_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm1_1_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm1_2_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm1_3_isr(void) __attribute__((weak, alias("blocking_handler")));
void pwm1_fault_isr(void) __attribute__((weak, alias("blocking_handler")));

#pragma weak nmi_handler = null_handler
#pragma weak hard_fault_handler = blocking_handler
#pragma weak sv_call_handler = null_handler
#pragma weak pend_sv_handler = null_handler
#pragma weak sys_tick_handler = null_handler

/* Those are defined only on CM3 or CM4 */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#pragma weak mem_manage_handler = blocking_handler
#pragma weak bus_fault_handler = blocking_handler
#pragma weak usage_fault_handler = blocking_handler
#pragma weak debug_monitor_handler = null_handler
#endif
