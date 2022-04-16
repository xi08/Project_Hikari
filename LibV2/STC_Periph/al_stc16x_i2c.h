// code = utf-8

#ifndef __al_stc16x_i2c_h
#define __al_stc16x_i2c_h

#include "al_stc16x.h"
#ifdef USE_AltLib

/**
 * @brief 
 * 
 */
typedef enum
{
    I2C_Port0 = 0, // SCL=P15, SDA=P14
    I2C_Port1 = 1, // SCL=P25, SDA=P24
    I2C_Port3 = 3, // SCL=P32, SDA=P33
} I2C_Port_enum;
#define IS_I2C_Port(PORT) (((PORT) == I2C_Port0) || \
                           ((PORT) == I2C_Port1) || \
                           ((PORT) == I2C_Port3))

/**
 * @brief 
 * 
 */
typedef enum
{
    I2C_Mode_Master,
    I2C_Mode_Slave,
} I2C_Mode_enum;
#define IS_I2C_Mode(MODE) (((MODE) == I2C_Mode_Master) || \
                           ((PORT) == I2C_Mode_Slave))



void I2C_Init();
void I2C_DeInit();

void I2C_ClockConfig();
void I2C_PortConfig();

void I2C_ReceiveByte();
void I2C_SendByte();

void I2C_CMD_Start();
void I2C_CMD_Stop();
void I2C_CMD_ACK();
void I2C_CMD_NACK();

void I2C_IRQConfig();
flagType I2C_GetFlagStatus();
void I2C_ClearFlag();

#endif
#endif