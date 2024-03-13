/*
 * fsm.c
 *
 *  Created on: 2024Äê1ÔÂ31ÈÕ
 *      Author: Xavier
 */

#include "fsm.h"

void run_fsm(fsm_tasks_type* task_list, fsm_trans_type *trans_list,  fsm_obj_type *obj)
{
    run_fsm_tasks(task_list,obj);
    run_fsm_trans(trans_list,obj);
}


// this function runs regular FSM state tasks.
void run_fsm_tasks(fsm_tasks_type* list, fsm_obj_type *obj)
{
    uint16_t index = 0;
    while(list[index].callbackfcn != NULL) //search all tasks.
    {
        if(list[index].state == obj->state) //found the task callback address for the current state.
        {
            list[index].callbackfcn(); // run task callback function.
            if (obj->state_run_cnt == 0) obj->state_run_cnt ++;
        }
        index ++; //go to next task.
    }
}

//this function check if there is a state transform.
void run_fsm_trans(fsm_trans_type *list, fsm_obj_type *obj)
{
    uint16_t index = 0;
    while(list[index].callbackfcn != NULL) //search all list.
    {
        if(list[index].old_state == obj->state
                && list[index].callbackfcn())
        {
            obj->state = list[index].new_state;
            obj->state_run_cnt = 0;
            return;
        }
    }
}

