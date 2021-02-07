/*
 * vector.h
 *
 *  Created on: 31-May-2020
 *      Author: J.Shankarappa
 *
 *  Adapted from libopencm3 project
 *
 */

#ifndef __VECTOR_H_
#define __VECTOR_H_

#define NVIC_INT_CTRL_R         (*((volatile uint32_t *)0xE000ED04))
#define SCB_ICSR_PENDSVSET      (1 << 28)
#define SCB_CCR_STKALIGN            (1 << 9)        /* STKALIGN */

/*
 *  Type of an interrupt function. Only used to avoid hard-to-read function
 *  pointers in the vector_table_t struct.
 *
*/
typedef void (*vector_table_entry_t)(void);

typedef struct {
    unsigned int *initial_sp_value; /**< Initial stack pointer value. */
    vector_table_entry_t reset;
    vector_table_entry_t nmi;
    vector_table_entry_t hard_fault;
    vector_table_entry_t memory_manage_fault; /* not in CM0 */
    vector_table_entry_t bus_fault;           /* not in CM0 */
    vector_table_entry_t usage_fault;         /* not in CM0 */
    vector_table_entry_t reserved_x001c[4];
    vector_table_entry_t sv_call;
    vector_table_entry_t debug_monitor;       /* not in CM0 */
    vector_table_entry_t reserved_x0034;
    vector_table_entry_t pend_sv;
    vector_table_entry_t systick;
    vector_table_entry_t irq[NVIC_IRQ_COUNT];
} vector_table_t;

/* Common symbols exported by the linker script(s): */
extern unsigned _data_loadaddr, _data, _edata, _ebss, _stack;
extern vector_table_t vector_table;

#endif /* __VECTOR_H_ */
