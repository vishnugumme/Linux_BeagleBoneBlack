/*
 * main.c
 *
 *  Created on: 25-May-2020
 *      Author: J.Shankarappa
 */

#include <stdio.h>
#include "atomport-private.h"
#include "atom.h"
#include "atomsem.h"
#include "atomtimer.h"
#include "board.h"



int ticks = 0;
int A[256];
int readptr = 0 ,writeptr = 0;
int COUNT=0;

/* Constants */

/*
 * Idle thread stack size
 *
 * This needs to be large enough to handle any interrupt handlers
 * and callbacks called by interrupt handlers (e.g. user-created
 * timer callbacks) as well as the saving of all context when
 * switching away from this thread.
 *
 * In this case, the idle stack is allocated on the BSS via the
 * idle_thread_stack[] byte array.
 */
#define IDLE_STACK_SIZE_BYTES       512

/*
 * Main thread stack size
 *
 * The Main thread stack generally needs to be larger than the idle
 * thread stack, as not only does it need to store interrupt handler
 * stack saves and context switch saves, but the application main thread
 * will generally be carrying out more nested function calls and require
 * stack for application code local variables etc.
 *
 */
#define MAIN_STACK_SIZE_BYTES       1024

/* Default thread priority */
#define MAIN_THREAD_PRIO            16

/* Application threads' TCBs */
static ATOM_TCB main_tcb;

/* SEMAPHORE*/
static ATOM_SEM SEM1;

/* Main thread's stack area */
static uint8_t main_thread_stack[MAIN_STACK_SIZE_BYTES];

/* Idle thread's stack area */
static uint8_t idle_thread_stack[IDLE_STACK_SIZE_BYTES];

/* Forward declarations */
static void main_thread_func(uint32_t data);

/**
 * main - Program entry point.
 *
 * Sets up the TM4C123GXL hardware resources (system tick timer interrupt) necessary
 * for the OS to be started. Creates an application thread and starts the OS.
 *
 */

int main(void)
{
    int8_t status;
    uint32_t loop;

    /*
     * Brief delay to give the debugger a chance to stop the core before we
     * muck around with the chip's configuration.
     */
    for(loop = 0; loop < 1000000; ++loop) {
        __asm__("nop");
    }

    /**
     * Note: to protect OS structures and data during initialisation,
     * interrupts must remain disabled until the first thread
     * has been restored. They are re-enabled at the very end of
     * the first thread restore, at which point it is safe for a
     * reschedule to take place.
     */

    setup_board();
    status = atomSemCreate(&SEM1,0);
    if(status == ATOM_OK) {

    /*
     * Initialise the OS before creating our threads.
     *
     */
    status = atomOSInit(&idle_thread_stack[0], IDLE_STACK_SIZE_BYTES, FALSE);

    if(status == ATOM_OK) {

        /* Create an application thread */
        status = atomThreadCreate( &main_tcb,
                                   MAIN_THREAD_PRIO,
                                   main_thread_func,
                                   0,
                                   &main_thread_stack[0],
                                   MAIN_STACK_SIZE_BYTES,
                                   TRUE
                                  );
        if(status == ATOM_OK) {
            /**
             * First application thread successfully created. It is
             * now possible to start the OS. Execution will not return
             * from atomOSStart(), which will restore the context of
             * our application thread and start executing it.
             *
             * Note that interrupts are still disabled at this point.
             * They will be enabled as we restore and execute our first
             * thread in archFirstThreadRestore().
             */
            atomOSStart();
        }
    }

  }
    while(1) {
        ;
    }

    /* There was an error starting the OS if we reach here */
    return (0);
}

/**
 * main_thread_func
 *
 * Entry point for main application thread.
 *
 * This is the first thread that will be executed when the OS is started.
 *
 * param[in]: data Unused (optional thread entry parameter)
 *
 * return: None
 */

static void main_thread_func(uint32_t data __maybe_unused)
{


    while(1) {

        atomSemGet (&SEM1,0);
        printf("%d\n",(int)(A[readptr] * 1.25));
        readptr = (readptr + 1) % 256;
    }
}


/* interrupt for PD0 : to reset the timers */  /* Need to modify  handler part*/
/* PortD Interrupt Service Routine */

void gpiod_isr(void)
{

    if ((GPIO_PORTD_MIS_R &(0x00000001))==0x01)               //interrupt detected to PD0
    {
     GPIO_PORTD_ICR_R = 0x01;     /* clear PD0 int */

    /* Must be called at the start of interrupt handler that may call an
       OS primitive and make a thread ready.  */
    atomIntEnter();

    if ( GPIO_PORTD_DATA_R == 0x01)
    {

        TIMER0_TAILR_R = TIMEOUT;
        TIMER0_CTL_R = TAEN;
        toggle_led(LED_GREEN);
        atomIntExit(0);
        return;

    }

    else
    {
        TIMER0_CTL_R &= (~TAEN);
        A[writeptr]=(TIMEOUT -(TIMER0_TAR_R));
        writeptr = (writeptr + 1)%256;
        atomSemPut (&SEM1);
        toggle_led(LED_GREEN);
        atomIntExit(0);
        return;
    }
    /* Process GPIO Port D Interrupt */

    /* Must be called at the end of interrupt handler that may call an
        OS primitive and make a thread ready. */

    }

    return;
}


//void timer0a_isr(void)  /* need to modify */
//{
//    if((TIMER0_MIS_R & CAEIM)!=0)
//    {
//        TIMER0_ICR_R=TIMER0_MIS_R;
//
//        atomIntEnter();
//        COUNT++;
//        if (TIMER0_TAR_R < TIMER0_TBR_R )
//        {
//            A[writeptr]=((TIMER0_TBR_R)-(TIMER0_TAR_R));
//            TIMER0_CTL_R &= (~TAEN);
//            TIMER0_CTL_R &= (~TBEN);
//            writeptr++;
//            atomSemPut (&SEM1);
//            atomIntExit(0);
//            return;
//        }
//
//        else
//        {
//            atomIntExit(0);
//            return;
//        }
//    }
//    else
//
//
//        TIMER0_ICR_R=TIMER0_MIS_R;
//        atomIntExit(0);
//        return;
//
//}
//
