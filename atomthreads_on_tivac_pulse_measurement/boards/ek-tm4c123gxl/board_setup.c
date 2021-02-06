/*
 * board_setup.c
 *
 *  Created on: 22-May-2020
 *      Author: J.Shankarappa
 */

#include <stdbool.h>
#include <stdint.h>
#include "cortex.h"
#include "atomport.h"
#include "board.h"

/**
 * Callback from your main program to set up the board's hardware before
 * the kernel is started.
 */
int setup_board(void)
{
    /* Disable interrupts. This makes sure that the sys_tick_handler will
     * not be called before the first thread has been started.
     * Interrupts will be enabled by archFirstThreadRestore().
     */
    cm_mask_interrupts(true);

    /* configure system clock, user LED and UART */
    setup_clock();
    setup_led();
    setup_uart0();

    /* Initialise SysTick counter */
    setup_systick();

    /* Interrupts will be enabled by archFirstThreadRestore(). */
//    cm_enable_interrupts();

    /* Set exception priority levels. Make PendSv the lowest priority and
     * SysTick the second to lowest */
    NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0x00FFFFFF) | 0xC0000000; /* SysTick priority 6 */
    NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R & 0xFFFFFFFF) | 0x00D00000; /* PendSV priority 7 */

    return 0;
}
