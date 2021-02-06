/*
 * nvic.h
 *
 *  Created on: 31-May-2020
 *      Author: J.Shankarappa
 *
 *  Adapted from libopencm3 project
 *
 */

#ifndef __NVIC_H_
#define __NVIC_H_

#define NVIC_GPIOA_IRQ      0       /* GPIO Port A */
#define NVIC_GPIOB_IRQ      1       /* GPIO Port B */
#define NVIC_GPIOC_IRQ      2       /* GPIO Port C */
#define NVIC_GPIOD_IRQ      3       /* GPIO Port D */
#define NVIC_GPIOE_IRQ      4       /* GPIO Port E */
#define NVIC_UART0_IRQ      5       /* UART0 Rx and Tx */
#define NVIC_UART1_IRQ      6       /* UART1 Rx and Tx */
#define NVIC_SSI0_IRQ       7       /* SSI0 Rx and Tx */
#define NVIC_I2C0_IRQ       8       /* I2C0 Master and Slave */
#define NVIC_PWM0_FAULT_IRQ 9       /* PWM0 Fault */
#define NVIC_PWM0_0_IRQ     10      /* PWM Generator 0 */
#define NVIC_PWM0_1_IRQ     11      /* PWM Generator 1 */
#define NVIC_PWM0_2_IRQ     12      /* PWM Generator 2 */
#define NVIC_QEI0_IRQ       13      /* Quadrature Encoder 0 */
#define NVIC_ADC0SS0_IRQ    14      /* ADC Sequence 0 */
#define NVIC_ADC0SS1_IRQ    15      /* ADC Sequence 1 */
#define NVIC_ADC0SS2_IRQ    16      /* ADC Sequence 2 */
#define NVIC_ADC0SS3_IRQ    17      /* ADC Sequence 3 */
#define NVIC_WATCHDOG_IRQ   18      /* Watchdog timer */
#define NVIC_TIMER0A_IRQ    19      /* Timer 0 subtimer A */
#define NVIC_TIMER0B_IRQ    20      /* Timer 0 subtimer B */
#define NVIC_TIMER1A_IRQ    21      /* Timer 1 subtimer A */
#define NVIC_TIMER1B_IRQ    22      /* Timer 1 subtimer B */
#define NVIC_TIMER2A_IRQ    23      /* Timer 2 subtimer A */
#define NVIC_TIMER2B_IRQ    24      /* Timer 2 subtimer B */
#define NVIC_COMP0_IRQ      25      /* Analog Comparator 0 */
#define NVIC_COMP1_IRQ      26      /* Analog Comparator 1 */
#define NVIC_COMP2_IRQ      27      /* Analog Comparator 2 */
#define NVIC_SYSCTL_IRQ     28      /* System Control (PLL, OSC, BO) */
#define NVIC_FLASH_IRQ      29      /* FLASH Control */
#define NVIC_GPIOF_IRQ      30      /* GPIO Port F */
#define NVIC_GPIOG_IRQ      31      /* GPIO Port G */
#define NVIC_GPIOH_IRQ      32      /* GPIO Port H */
#define NVIC_UART2_IRQ      33      /* UART2 Rx and Tx */
#define NVIC_SSI1_IRQ       34      /* SSI1 Rx and Tx */
#define NVIC_TIMER3A_IRQ    35      /* Timer 3 subtimer A */
#define NVIC_TIMER3B_IRQ    36      /* Timer 3 subtimer B */
#define NVIC_I2C1_IRQ       37      /* I2C1 Master and Slave */
#define NVIC_QEI1_IRQ       38      /* Quadrature Encoder 1 */
#define NVIC_CAN0_IRQ       39      /* CAN0 */
#define NVIC_CAN1_IRQ       40      /* CAN1 */
#define NVIC_CAN2_IRQ       41      /* Reserved */
#define NVIC_ETH_IRQ        42      /* Reserved */
#define NVIC_HIBERNATE_IRQ  43      /* Hibernate */
#define NVIC_USB0_IRQ       44      /* USB0 */
#define NVIC_PWM0_3_IRQ     45      /* PWM Generator 3 */
#define NVIC_UDMA_IRQ       46      /* uDMA Software Transfer */
#define NVIC_UDMAERR_IRQ    47      /* uDMA Error */
#define NVIC_ADC1SS0_IRQ    48      /* ADC1 Sequence 0 */
#define NVIC_ADC1SS1_IRQ    49      /* ADC1 Sequence 1 */
#define NVIC_ADC1SS2_IRQ    50      /* ADC1 Sequence 2 */
#define NVIC_ADC1SS3_IRQ    51      /* ADC1 Sequence 3 */
#define NVIC_I2S0_IRQ       52      /* Reserved */
#define NVIC_EPI0_IRQ       53      /* Reserved */
#define NVIC_GPIOJ_IRQ      54      /* GPIO Port J */
#define NVIC_GPIOK_IRQ      55      /* GPIO Port K */
#define NVIC_GPIOL_IRQ      56      /* GPIO Port L */
#define NVIC_SSI2_IRQ       57      /* SSI2 Rx and Tx */
#define NVIC_SSI3_IRQ       58      /* SSI3 Rx and Tx */
#define NVIC_UART3_IRQ      59      /* UART3 Rx and Tx */
#define NVIC_UART4_IRQ      60      /* UART4 Rx and Tx */
#define NVIC_UART5_IRQ      61      /* UART5 Rx and Tx */
#define NVIC_UART6_IRQ      62      /* UART6 Rx and Tx */
#define NVIC_UART7_IRQ      63      /* UART7 Rx and Tx */
/*      64 to 67 Reserved    */
#define NVIC_I2C2_IRQ       68      /* I2C2 Master and Slave */
#define NVIC_I2C3_IRQ       69      /* I2C3 Master and Slave */
#define NVIC_TIMER4A_IRQ    70      /* Timer 4 subtimer A */
#define NVIC_TIMER4B_IRQ    71      /* Timer 4 subtimer B */
/*      72 to 91 Reserved    */
#define NVIC_TIMER5A_IRQ    92      /* Timer 5 subtimer A */
#define NVIC_TIMER5B_IRQ    93      /* Timer 5 subtimer B */
#define NVIC_WTIMER0A_IRQ   94      /* Wide Timer 0 subtimer A */
#define NVIC_WTIMER0B_IRQ   95      /* Wide Timer 0 subtimer B */
#define NVIC_WTIMER1A_IRQ   96      /* Wide Timer 1 subtimer A */
#define NVIC_WTIMER1B_IRQ   97      /* Wide Timer 1 subtimer B */
#define NVIC_WTIMER2A_IRQ   98      /* Wide Timer 2 subtimer A */
#define NVIC_WTIMER2B_IRQ   99      /* Wide Timer 2 subtimer B */
#define NVIC_WTIMER3A_IRQ   100     /* Wide Timer 3 subtimer A */
#define NVIC_WTIMER3B_IRQ   101     /* Wide Timer 3 subtimer B */
#define NVIC_WTIMER4A_IRQ   102     /* Wide Timer 4 subtimer A */
#define NVIC_WTIMER4B_IRQ   103     /* Wide Timer 4 subtimer B */
#define NVIC_WTIMER5A_IRQ   104     /* Wide Timer 5 subtimer A */
#define NVIC_WTIMER5B_IRQ   105     /* Wide Timer 5 subtimer A */
#define NVIC_SYSEXC_IRQ     106     /* FPU */
#define NVIC_PECI0_IRQ      107     /* Reserved */
#define NVIC_LPC0_IRQ       108     /* Reserved */
#define NVIC_I2C4_IRQ       109     /* I2C4 Master and Slave */
#define NVIC_I2C5_IRQ       110     /* I2C5 Master and Slave */
#define NVIC_GPIOM_IRQ      111     /* GPIO Port M */
#define NVIC_GPION_IRQ      112     /* GPIO Port N */
#define NVIC_QEI2_IRQ       113     /* Quadrature Encoder 2 */
#define NVIC_FAN0_IRQ       114     /* Reserved */
/*      115 Reserved   */
#define NVIC_GPIOP0_IRQ     116     /* GPIO Port P (Summary or P0) */
#define NVIC_GPIOP1_IRQ     117     /* GPIO Port P1 */
#define NVIC_GPIOP2_IRQ     118     /* GPIO Port P2 */
#define NVIC_GPIOP3_IRQ     119     /* GPIO Port P3 */
#define NVIC_GPIOP4_IRQ     120     /* GPIO Port P4 */
#define NVIC_GPIOP5_IRQ     121     /* GPIO Port P5 */
#define NVIC_GPIOP6_IRQ     122     /* GPIO Port P6 */
#define NVIC_GPIOP7_IRQ     123     /* GPIO Port P7 */
#define NVIC_GPIOQ0_IRQ     124     /* GPIO Port Q (Summary or Q0) */
#define NVIC_GPIOQ1_IRQ     125     /* GPIO Port Q1 */
#define NVIC_GPIOQ2_IRQ     126     /* GPIO Port Q2 */
#define NVIC_GPIOQ3_IRQ     127     /* GPIO Port Q3 */
#define NVIC_GPIOQ4_IRQ     128     /* GPIO Port Q4 */
#define NVIC_GPIOQ5_IRQ     129     /* GPIO Port Q5 */
#define NVIC_GPIOQ6_IRQ     130     /* GPIO Port Q6 */
#define NVIC_GPIOQ7_IRQ     131     /* GPIO Port Q7 */
#define NVIC_GPIOR_IRQ      132     /* GPIO Port R */
#define NVIC_GPIOS_IRQ      133     /* GPIO Port S */
#define NVIC_PWM1_0_IRQ     134     /* PWM 1 Generator 0 */
#define NVIC_PWM1_1_IRQ     135     /* PWM 1 Generator 1 */
#define NVIC_PWM1_2_IRQ     136     /* PWM 1 Generator 2 */
#define NVIC_PWM1_3_IRQ     137     /* PWM 1 Generator 3 */
#define NVIC_PWM1_FAULT_IRQ 138     /* PWM 1 Fault */

#define NVIC_IRQ_COUNT      139

/* --- NVIC functions ------------------------------------------------------ */
void gpioa_isr(void);
void gpiob_isr(void);
void gpioc_isr(void);
void gpiod_isr(void);
void gpioe_isr(void);
void uart0_isr(void);
void uart1_isr(void);
void ssi0_isr(void);
void i2c0_isr(void);
void pwm0_fault_isr(void);
void pwm0_0_isr(void);
void pwm0_1_isr(void);
void pwm0_2_isr(void);
void qei0_isr(void);
void adc0ss0_isr(void);
void adc0ss1_isr(void);
void adc0ss2_isr(void);
void adc0ss3_isr(void);
void watchdog_isr(void);
void timer0a_isr(void);
void timer0b_isr(void);
void timer1a_isr(void);
void timer1b_isr(void);
void timer2a_isr(void);
void timer2b_isr(void);
void comp0_isr(void);
void comp1_isr(void);
void comp2_isr(void);
void sysctl_isr(void);
void flash_isr(void);
void gpiof_isr(void);
void gpiog_isr(void);
void gpioh_isr(void);
void uart2_isr(void);
void ssi1_isr(void);
void timer3a_isr(void);
void timer3b_isr(void);
void i2c1_isr(void);
void qei1_isr(void);
void can0_isr(void);
void can1_isr(void);
void can2_isr(void);
void eth_isr(void);
void hibernate_isr(void);
void usb0_isr(void);
void pwm0_3_isr(void);
void udma_isr(void);
void udmaerr_isr(void);
void adc1ss0_isr(void);
void adc1ss1_isr(void);
void adc1ss2_isr(void);
void adc1ss3_isr(void);
void i2s0_isr(void);        /* Reserved */
void epi0_isr(void);        /* Reserved */
void gpioj_isr(void);
void gpiok_isr(void);
void gpiol_isr(void);
void ssi2_isr(void);
void ssi3_isr(void);
void uart3_isr(void);
void uart4_isr(void);
void uart5_isr(void);
void uart6_isr(void);
void uart7_isr(void);
void i2c2_isr(void);
void i2c3_isr(void);
void timer4a_isr(void);
void timer4b_isr(void);
void timer5a_isr(void);
void timer5b_isr(void);
void wtimer0a_isr(void);
void wtimer0b_isr(void);
void wtimer1b_isr(void);
void wtimer1a_isr(void);
void wtimer2a_isr(void);
void wtimer2b_isr(void);
void wtimer3a_isr(void);
void wtimer3b_isr(void);
void wtimer4a_isr(void);
void wtimer4b_isr(void);
void wtimer5a_isr(void);
void wtimer5b_isr(void);
void sysexc_isr(void);          /* FPU */
void peci0_isr(void);           /* Reserved */
void lpc0_isr(void);            /* Reserved */
void i2c4_isr(void);
void i2c5_isr(void);
void gpiom_isr(void);
void gpion_isr(void);
/* Quadrature Encoder 2 ISR ?*/
void fan0_isr(void);
void gpiop0_isr(void);
void gpiop1_isr(void);
void gpiop2_isr(void);
void gpiop3_isr(void);
void gpiop4_isr(void);
void gpiop5_isr(void);
void gpiop6_isr(void);
void gpiop7_isr(void);
void gpioq0_isr(void);
void gpioq1_isr(void);
void gpioq2_isr(void);
void gpioq3_isr(void);
void gpioq4_isr(void);
void gpioq5_isr(void);
void gpioq6_isr(void);
void gpioq7_isr(void);
/* GPIOQ6 GPIOQ7 ISR ? */
void pwm1_0_isr(void);
void pwm1_1_isr(void);
void pwm1_2_isr(void);
void pwm1_3_isr(void);
void pwm1_fault_isr(void);

/* Initialization template for the interrupt vector table. This definition is
 * used by the startup code generator (vector.c) to set the initial values for
 * the interrupt handling routines to the chip family specific _isr weak
 * symbols.
*/

#define IRQ_HANDLERS \
    [NVIC_GPIOA_IRQ] = gpioa_isr, \
    [NVIC_GPIOB_IRQ] = gpiob_isr, \
    [NVIC_GPIOC_IRQ] = gpioc_isr, \
    [NVIC_GPIOD_IRQ] = gpiod_isr, \
    [NVIC_GPIOE_IRQ] = gpioe_isr, \
    [NVIC_UART0_IRQ] = uart0_isr, \
    [NVIC_UART1_IRQ] = uart1_isr, \
    [NVIC_SSI0_IRQ] = ssi0_isr, \
    [NVIC_I2C0_IRQ] = i2c0_isr, \
    [NVIC_PWM0_FAULT_IRQ] = pwm0_fault_isr, \
    [NVIC_PWM0_0_IRQ] = pwm0_0_isr, \
    [NVIC_PWM0_1_IRQ] = pwm0_1_isr, \
    [NVIC_PWM0_2_IRQ] = pwm0_2_isr, \
    [NVIC_QEI0_IRQ] = qei0_isr, \
    [NVIC_ADC0SS0_IRQ] = adc0ss0_isr, \
    [NVIC_ADC0SS1_IRQ] = adc0ss1_isr, \
    [NVIC_ADC0SS2_IRQ] = adc0ss2_isr, \
    [NVIC_ADC0SS3_IRQ] = adc0ss3_isr, \
    [NVIC_WATCHDOG_IRQ] = watchdog_isr, \
    [NVIC_TIMER0A_IRQ] = timer0a_isr, \
    [NVIC_TIMER0B_IRQ] = timer0b_isr, \
    [NVIC_TIMER1A_IRQ] = timer1a_isr, \
    [NVIC_TIMER1B_IRQ] = timer1b_isr, \
    [NVIC_TIMER2A_IRQ] = timer2a_isr, \
    [NVIC_TIMER2B_IRQ] = timer2b_isr, \
    [NVIC_COMP0_IRQ] = comp0_isr, \
    [NVIC_COMP1_IRQ] = comp1_isr, \
    [NVIC_COMP2_IRQ] = comp2_isr, \
    [NVIC_SYSCTL_IRQ] = sysctl_isr, \
    [NVIC_FLASH_IRQ] = flash_isr, \
    [NVIC_GPIOF_IRQ] = gpiof_isr, \
    [NVIC_GPIOG_IRQ] = gpiog_isr, \
    [NVIC_GPIOH_IRQ] = gpioh_isr, \
    [NVIC_UART2_IRQ] = uart2_isr, \
    [NVIC_SSI1_IRQ] = ssi1_isr, \
    [NVIC_TIMER3A_IRQ] = timer3a_isr, \
    [NVIC_TIMER3B_IRQ] = timer3b_isr, \
    [NVIC_I2C1_IRQ] = i2c1_isr, \
    [NVIC_QEI1_IRQ] = qei1_isr, \
    [NVIC_CAN0_IRQ] = can0_isr, \
    [NVIC_CAN1_IRQ] = can1_isr, \
    [NVIC_CAN2_IRQ] = can2_isr, \
    [NVIC_ETH_IRQ] = eth_isr, \
    [NVIC_HIBERNATE_IRQ] = hibernate_isr, \
    [NVIC_USB0_IRQ] = usb0_isr, \
    [NVIC_PWM0_3_IRQ] = pwm0_3_isr, \
    [NVIC_UDMA_IRQ] = udma_isr, \
    [NVIC_UDMAERR_IRQ] = udmaerr_isr, \
    [NVIC_ADC1SS0_IRQ] = adc1ss0_isr, \
    [NVIC_ADC1SS1_IRQ] = adc1ss1_isr, \
    [NVIC_ADC1SS2_IRQ] = adc1ss2_isr, \
    [NVIC_ADC1SS3_IRQ] = adc1ss3_isr, \
    [NVIC_I2S0_IRQ] = i2s0_isr, \
    [NVIC_EPI0_IRQ] = epi0_isr, \
    [NVIC_GPIOJ_IRQ] = gpioj_isr, \
    [NVIC_GPIOK_IRQ] = gpiok_isr, \
    [NVIC_GPIOL_IRQ] = gpiol_isr, \
    [NVIC_SSI2_IRQ] = ssi2_isr, \
    [NVIC_SSI3_IRQ] = ssi3_isr, \
    [NVIC_UART3_IRQ] = uart3_isr, \
    [NVIC_UART4_IRQ] = uart4_isr, \
    [NVIC_UART5_IRQ] = uart5_isr, \
    [NVIC_UART6_IRQ] = uart6_isr, \
    [NVIC_UART7_IRQ] = uart7_isr, \
    [NVIC_I2C2_IRQ] = i2c2_isr, \
    [NVIC_I2C3_IRQ] = i2c3_isr, \
    [NVIC_TIMER4A_IRQ] = timer4a_isr, \
    [NVIC_TIMER4B_IRQ] = timer4b_isr, \
    [NVIC_TIMER5A_IRQ] = timer5a_isr, \
    [NVIC_TIMER5B_IRQ] = timer5b_isr, \
    [NVIC_WTIMER0A_IRQ] = wtimer0a_isr, \
    [NVIC_WTIMER0B_IRQ] = wtimer0b_isr, \
    [NVIC_WTIMER1A_IRQ] = wtimer1a_isr, \
    [NVIC_WTIMER1B_IRQ] = wtimer1b_isr, \
    [NVIC_WTIMER2A_IRQ] = wtimer2a_isr, \
    [NVIC_WTIMER2B_IRQ] = wtimer2b_isr, \
    [NVIC_WTIMER3A_IRQ] = wtimer3a_isr, \
    [NVIC_WTIMER3B_IRQ] = wtimer3b_isr, \
    [NVIC_WTIMER4A_IRQ] = wtimer4a_isr, \
    [NVIC_WTIMER4B_IRQ] = wtimer4b_isr, \
    [NVIC_WTIMER5A_IRQ] = wtimer5a_isr, \
    [NVIC_WTIMER5B_IRQ] = wtimer5b_isr, \
    [NVIC_SYSEXC_IRQ] = sysexc_isr, \
    [NVIC_PECI0_IRQ] = peci0_isr, \
    [NVIC_LPC0_IRQ] = lpc0_isr, \
    [NVIC_I2C4_IRQ] = i2c4_isr, \
    [NVIC_I2C5_IRQ] = i2c5_isr, \
    [NVIC_GPIOM_IRQ] = gpiom_isr, \
    [NVIC_GPION_IRQ] = gpion_isr, \
    [NVIC_FAN0_IRQ] = fan0_isr, \
    [NVIC_GPIOP0_IRQ] = gpiop0_isr, \
    [NVIC_GPIOP1_IRQ] = gpiop1_isr, \
    [NVIC_GPIOP2_IRQ] = gpiop2_isr, \
    [NVIC_GPIOP3_IRQ] = gpiop3_isr, \
    [NVIC_GPIOP4_IRQ] = gpiop4_isr, \
    [NVIC_GPIOP5_IRQ] = gpiop5_isr, \
    [NVIC_GPIOP6_IRQ] = gpiop6_isr, \
    [NVIC_GPIOP7_IRQ] = gpiop7_isr, \
    [NVIC_GPIOQ0_IRQ] = gpioq0_isr, \
    [NVIC_GPIOQ1_IRQ] = gpioq1_isr, \
    [NVIC_GPIOQ2_IRQ] = gpioq2_isr, \
    [NVIC_GPIOQ3_IRQ] = gpioq3_isr, \
    [NVIC_GPIOQ4_IRQ] = gpioq4_isr, \
    [NVIC_GPIOQ5_IRQ] = gpioq5_isr, \
    [NVIC_GPIOQ6_IRQ] = gpioq6_isr, \
    [NVIC_GPIOQ7_IRQ] = gpioq7_isr, \
    [NVIC_PWM1_0_IRQ] = pwm1_0_isr, \
    [NVIC_PWM1_1_IRQ] = pwm1_1_isr, \
    [NVIC_PWM1_2_IRQ] = pwm1_2_isr, \
    [NVIC_PWM1_3_IRQ] = pwm1_3_isr, \
    [NVIC_PWM1_FAULT_IRQ] = pwm1_fault_isr, \


/* --- NVIC functions ------------------------------------------------------ */

void reset_handler(void);
void nmi_handler(void);
void hard_fault_handler(void);
void sv_call_handler(void);
void pend_sv_handler(void);
void sys_tick_handler(void);

/* Those defined only on ARMv7 and above */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
void mem_manage_handler(void);
void bus_fault_handler(void);
void usage_fault_handler(void);
void debug_monitor_handler(void);
#endif

#endif /* PORTS_CORTEX_M_COMMON_NVIC_H_ */
