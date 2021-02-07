/*
 * tick.c
 *
 *  Created on: 31-May-2020
 *      Author: J.Shankarappa
 */

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

/*
 * Initialise and start SysTick Timer/Counter. This will trigger the
 * sys_tick_handler() periodically once interrupts have been enabled
 * by archFirstThreadRestore()
 *
*/
void setup_systick(void)
{
    NVIC_ST_CTRL_R = 0;             /* disable SysTick during setup */
    NVIC_ST_CURRENT_R = 0;          /* any write to current clears it */
    NVIC_ST_RELOAD_R = 0xC3500;     /* 10ms @80Mhz, reload with number of clocks per second */
    NVIC_ST_CTRL_R = 7;             /* enable SysTick interrupt, use system clock */
}


