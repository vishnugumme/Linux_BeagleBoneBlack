/*
 * board.h
 *
 *  Created on: 01-June-2020
 *      Author: J.Shankarappa
 */

#ifndef __BOARD_H_
#define __BOARD_H_

#include <stdint.h>
#include <inc/tm4c123gh6pm.h>

#include "uart0.h"

#define EnableInterrupts() __asm ("CPSIE  I\n")
#define DisableInterrupts() __asm ("CPSID  I\n")

#define  SW1        (GPIO_PORTF_DATA_R&(1<<4))
#define  SW2        (GPIO_PORTF_DATA_R&(1<<0))

#define  LED_RED    0x02
#define  LED_BLUE   0x04
#define  LED_GREEN  0x08

/*TIMER*/

#define TAEN 0x101
#define TIMER0 0x01
#define TA16BIT 0x04
#define TA32BIT 0x00
#define PERIODIC 0x02
#define PRESCALAR   255
#define TIMEOUT     40000000   // for 500 ms 40000000*12.5 ns = 500 ms
#define TIMEOUTB    20000
#define TATOIM      0x01
#define CLEARALL    0xFF

int setup_board(void);
void setup_systick(void);
void setup_clock(void);
void setup_led(void);
void toggle_led(uint8_t color);

#endif /* __BOARD_H_ */
