/*
 * modbus.h
 *
 *  Created on: 2024��3��12��
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
