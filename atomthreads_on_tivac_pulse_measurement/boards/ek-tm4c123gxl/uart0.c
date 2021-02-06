/*
 * uart0.c
 *
 *  Created on: 23-May-2020
 *      Author: jshankar
 */

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

#include "uart0.h"

void setup_uart0(void)
{
    SYSCTL_RCGCUART_R |= 0x01;            /* activate UART0 */
    SYSCTL_RCGCGPIO_R |= 0x01;            /* activate port A */

    while((SYSCTL_PRGPIO_R&0x0001) == 0){};/* ready? */
    UART0_CTL_R &= ~UART_CTL_UARTEN;      /* disable UART */
    UART0_IBRD_R = 43;                    /* 80MHz, 115,200 Baud */
    UART0_FBRD_R = 25;
                                          /* 8 bit word length (no parity bits, one stop bit, FIFOs) */
    UART0_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN);
    UART0_CTL_R |= UART_CTL_UARTEN;       /* enable UART */
    GPIO_PORTA_AFSEL_R |= 0x03;           /* enable alt funct on PA1-0 */
    GPIO_PORTA_DEN_R |= 0x03;             /* enable digital I/O on PA1-0 */
                                          /* configure PA1-0 as UART */
    GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011;
    GPIO_PORTA_AMSEL_R &= ~0x03;          /* disable analog functionality on PA */
}

/*
 * Read a Received Data Word with Blocking.
 * Wait until a data word has been received then return the word.
 *
 */

uint16_t uart0_recv_blocking(void)
{
    while( (UART0_FR_R & UART_FR_RXFE) != 0)
        ;
    return((uint16_t)(UART0_DR_R & 0xFF));
}

/*
 * Send Data Word with Blocking.
 * Blocks until the transmit data FIFO can accept the next data word for transmission.
 *
 */

void uart0_send_blocking(uint16_t data)
{
    while((UART0_FR_R & UART_FR_TXFF) != 0)
        ;
    UART0_DR_R = (uint8_t)data;
}
