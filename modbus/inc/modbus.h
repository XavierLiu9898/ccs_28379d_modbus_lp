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


typedef enum
{
    Initial,
    Idle,
    Emission,
    Reception,
    Waiting,

}ModbusTransState_e;



#endif /* MODBUS_INC_MODBUS_H_ */
