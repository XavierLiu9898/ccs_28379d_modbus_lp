/*
 * modbus.h
 *
 *  Created on: 2024Äê3ÔÂ12ÈÕ
 *      Author: Xavier
 */

#ifndef MODBUS_INC_MODBUS_H_
#define MODBUS_INC_MODBUS_H_

#include <stdbool.h>
#include <stdint.h>
#include "board.h"
#include "driverlib.h"

#include "fsm.h"

typedef enum
{
    Initial,
    Idle,
    Emission,
    Reception,
    Waiting,

}Modbus_State_e;


typedef struct
{
    fsm_obj_type fsm;

} Modbus_obj_type;


//modbus task callbacks.
extern void initial_task(void);
extern void Idle_task(void);
extern void Emission_task(void);
extern void Reception_task(void);
extern void Waiting_task(void);
//modbus trans callbacks.

extern bool initial_initial_trans(void);




extern void Test_Sending(void);
extern void start_timer(void);
extern bool timer_expired(void);

#endif /* MODBUS_INC_MODBUS_H_ */
