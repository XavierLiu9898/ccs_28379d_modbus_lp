/*
 * fsm.h
 *
 *  Created on: 2024Äê1ÔÂ31ÈÕ
 *      Author: Xavier
 */

#ifndef SCI_INC_FSM_H_
#define SCI_INC_FSM_H_

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_types.h"

typedef struct
{
    volatile uint16_t state; // current state.
    volatile uint32_t state_run_cnt; //counter for current state.
} fsm_obj_type;


typedef struct
{
    uint16_t state;
    void (* callbackfcn)(void);
} fsm_tasks_type;

// if callbackfcn() returns yes, state transform from old_state to new_state.
typedef struct
{
    uint16_t old_state;
    uint16_t new_state;
    bool (* callbackfcn)(void);
} fsm_trans_type;

extern void run_fsm_tasks(fsm_tasks_type* list, fsm_obj_type *obj);
extern void run_fsm_trans(fsm_trans_type *list, fsm_obj_type *obj);


#endif /* SCI_INC_FSM_H_ */
