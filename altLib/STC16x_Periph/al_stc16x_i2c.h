/* code = utf-8 */

#ifndef __al_stc16x_i2c_h
#define __al_stc16x_i2c_h

#include "al_stc16x.h"
#ifdef USE_AltLib

/**
 * @brief I2C外设枚举
 *
 */
typedef enum
{
    I2C1,
} I2C_enum;
#define IS_I2C_Periph(PERIPH) (((PERIPH) == I2C1))

/**
 * @brief I2C外设引脚枚举
 *
 */
typedef enum
{
    I2C1_Port0 = 0x00, // SCL=P15, SDA=P14
    I2C1_Port1 = 0x01, // SCL=P25, SDA=P24
    I2C1_Port3 = 0x03, // SCL=P32, SDA=P33
} I2C_Port_enum;
#define IS_I2C_Port(PORT) (((PORT) == I2C1_Port0) || ((PORT) == I2C1_Port1) || ((PORT) == I2C1_Port3))

/**
 * @brief I2C模式枚举
 *
 */
typedef enum
{
    I2C_Mode_Slave = 0,
    I2C_Mode_Master = 1,
} I2C_Mode_enum;
#define IS_I2C_Mode(MODE) (((MODE) == I2C_Mode_Master) || ((MODE) == I2C_Mode_Slave))

#define IS_I2C_ClockDiv(CKD) (CKD < 64)

/**
 * @brief I2C初始化结构体
 *
 */
typedef struct
{
    I2C_Port_enum I2C_Port;
    I2C_Mode_enum I2C_Mode;
    uint8_t I2C_ClockDiv;
    uint8_t I2C_OwnAddress;
} I2C_InitTypeDef;

void I2C_Init(I2C_enum I2Cx, I2C_InitTypeDef *initStruct);
void I2C_DeInit(I2C_enum I2Cx);
void I2C_StructInit(I2C_InitTypeDef *initStruct);
void I2C_Cmd(I2C_enum I2Cx, statusType newStatus);

void I2C_PortConfig(I2C_enum I2Cx, I2C_Port_enum newPort);
void I2C_ModeConfig(I2C_enum I2Cx, I2C_Mode_enum newMode);
void I2C_ClockConfig(I2C_enum I2Cx, uint8_t newClockDiv);
void I2C_OwnAddrConfig(I2C_enum I2Cx, uint8_t newOwnAddr);

void I2C_RecvByte(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t srcRegAddr, uint8_t *dest);
void I2C_SendByte(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t destRegAddr, uint8_t src);
void I2C_RecvPage(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t srcRegAddr, uint8_t *dest, uint8_t n);
void I2C_SendPage(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t destRegAddr, uint8_t *src, uint8_t n);

void I2C_ITConfig(I2C_enum I2Cx, uint16_t I2C_IT, statusType newStatus);
flagType I2C_GetITStatus(I2C_enum I2Cx, uint16_t I2C_IT);
void I2C_ClearITPendingBit(I2C_enum I2Cx, uint16_t I2C_IT);

void I2C_FlagConfig(I2C_enum I2Cx, uint16_t I2C_FLAG, statusType newStatus);
flagType I2C_GetFlagStatus(I2C_enum I2Cx, uint16_t I2C_FLAG);
void I2C_ClearFlag(I2C_enum I2Cx, uint16_t I2C_FLAG);

#endif
#endif
