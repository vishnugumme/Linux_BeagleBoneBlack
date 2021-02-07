/*
 * gpio.c
 *
 *  Created on: 31-May-2020
 *      Author: J. Shankarappa
 */

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "board.h"

/**
 * Set up user LED and provide function for toggling it. This is for
 * use by the test programs
 */
void setup_led(void)
{
    volatile unsigned long delay;

    /* Initialize the GPIOs and Timers that drive the three LEDs. */
    SYSCTL_RCGC2_R |= 0x0000002A;     /* activate clock for Port B,D & F */
    delay = SYSCTL_RCGC2_R;           /* allow time for clock to start */
    delay = delay;

    /* enable the GPIO pins for the LED (PF3, 2, 1) as output */
    GPIO_PORTF_DIR_R |= 0x0E;
    /* enable the GPIO pins for digital function */
    GPIO_PORTF_DEN_R |= 0x0E;


    /* configuring portD pin 1 PD0 as interrupt */

    /* enable the GPIO pins for digital function */
        GPIO_PORTD_DEN_R |= 0x01;

    /* enable pull up enable for pin0 (PD0) */
        GPIO_PORTD_PUR_R = 0x01;



    /* NVIC interrupt configuration */

    /* Enable port D interrupt in NVIC */

        NVIC_EN0_R=0x00000008;

    /* set priority for PD1 : priority level 2 */

        NVIC_PRI0_R = (NVIC_PRI0_R | 0xFFFFFFFF) & (0x4FFFFFFF);

    /* GPIO interrupt configuration */

    /* Mask the interrupt till it is configured */

        GPIO_PORTD_IM_R=0x00;

    /* Configure it as edge sensitive interrupt */

        GPIO_PORTD_IS_R =0x00;

    /* Rising edge senitive */

        GPIO_PORTD_IEV_R=0x01;

    /* Both edge senistive : yes */

        GPIO_PORTD_IBE_R=0x01;    // 0x00

    /* clear the interrupt status if any */

        GPIO_PORTD_ICR_R  =0x01;

    /* enable the interupt */

        GPIO_PORTD_IM_R=0x01;



           SYSCTL_RCGCTIMER_R |= TIMER0; // Clock Enable to timer0
            TIMER0_CTL_R &= (~TAEN);   // bit 0 timer A en, bit 8 timber B en, required to disable during initialization
            TIMER0_CFG_R=TA32BIT;      // Timer 0 as 16bit(0x4), 32bit(0x00) or RTC
            TIMER0_TAMR_R=PERIODIC;    //Timer0 A mode register, oneshot(01),periodic(10), capture(11), 4th bit 1: up direction
            //TIMER0_TAPR_R= PRESCALAR;  // 8 bit max value can be given for extra delay
            TIMER0_TAILR_R = TIMEOUT;  //The value loaded for counting
            //TIMER0_TBILR_R = TIMEOUTB;  //The value loaded for counting
            //TIMER0_IMR_R= TATOIM;      // Enable interrupt mask for timer A
            //TIMER0_CTL_R = TAEN;       // Start the timer by enabling A and B for 32 bit Enable
            //TIMER0_ICR_R= CLEARALL;    // clearing all the interrupt registered

        /* Globally interrupt enable  */
           EnableInterrupts();



}

void toggle_led(uint8_t color)
{
    GPIO_PORTF_DATA_R ^= color;         /* toggle LED */
}










