/*
 * modbus.c
 *
 *  Created on: 2024Äê3ÔÂ12ÈÕ
 *      Author: Xavier.
 */


#include "modbus.h"
uint16_t Tx_Buff[16] = {0};

Modbus_obj_type modbus_obj;

fsm_tasks_type modbus_fsm_task_list[] =
{
 {.state = (uint16_t)(Initial),     .callbackfcn = initial_task},
 {.state = (uint16_t)(Idle),        .callbackfcn = Idle_task},
 {.state = (uint16_t)(Emission),    .callbackfcn = Emission_task},
 {.state = (uint16_t)(Reception),   .callbackfcn = Reception_task},
 {.state = (uint16_t)(Waiting),     .callbackfcn = Waiting_task},

 {.state = 0, .callbackfcn = NULL},
};

fsm_trans_type modbus_fsm_trans_list[] =
{
    {
        .old_state = (uint16_t)(Initial),
        .new_state = (uint16_t)(Initial),
        .callbackfcn = initial_initial_trans,
    },


    {
        .old_state = 0,
        .new_state = 0,
        .callbackfcn = NULL,
    },
};



void initial_task(void)
{
    Modbus_obj_type * obj = &modbus_obj;

    if(obj->fsm.state_run_cnt == 0) //first time in this state
    {
        start_timer();
    }
}

bool initial_initial_trans(void)
{
    return timer_expired();
}



void start_timer(void)
{

}


bool timer_expired(void)
{
    return true;
}





void Test_Sending(void)
{
    char * msg = "Hello!";
    SCI_writeCharArray(sci_modbus_BASE,(uint16_t *)(msg),
                       6);
}
