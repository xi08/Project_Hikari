
#ifndef __STC16F40K_GPIO_H
#define __STC16F40K_GPIO_H

#include "stc16f40k.h"

typedef enum
{
    GPIO0,
    GPIO1,
    GPIO2,
    GPIO3,
    GPIO4,
    GPIO5,
    GPIO6,
    GPIO7,
} GPIO_Port_enum;
#define IS_GPIO_Port(PORT) (((PORT) == GPIO0) || ((PORT) == GPIO1) || \
                            ((PORT) == GPIO2) || ((PORT) == GPIO3) || \
                            ((PORT) == GPIO4) || ((PORT) == GPIO5) || \
                            ((PORT) == GPIO6) || ((PORT) == GPIO7))

#define GPIO_Pin_0 ((uint8_t)0x01)
#define GPIO_Pin_1 ((uint8_t)0x02)
#define GPIO_Pin_2 ((uint8_t)0x04)
#define GPIO_Pin_3 ((uint8_t)0x08)
#define GPIO_Pin_4 ((uint8_t)0x10)
#define GPIO_Pin_5 ((uint8_t)0x20)
#define GPIO_Pin_6 ((uint8_t)0x40)
#define GPIO_Pin_7 ((uint8_t)0x80)
#define GPIO_Pin_All ((uint8_t)0xFF)
#define IS_GPIO_PIN(PIN) ((PIN) != (uint8_t)0x00)
#define IS_GET_GPIO_Pin(PIN) (((PIN) == GPIO_Pin_0) || ((PIN) == GPIO_Pin_1) || \
                              ((PIN) == GPIO_Pin_2) || ((PIN) == GPIO_Pin_3) || \
                              ((PIN) == GPIO_Pin_4) || ((PIN) == GPIO_Pin_5) || \
                              ((PIN) == GPIO_Pin_6) || ((PIN) == GPIO_Pin_7))

typedef enum
{
    GPIO_Mode_Dual_Normal,
    GPIO_Mode_Out_PP,
    GPIO_Mode_In_HI,
    GPIO_Mode_Dual_OD,
} GPIO_Mode_enum;
#define IS_GPIO_Mode(MODE) (((MODE) == GPIO_Mode_Dual_Normal) || \
                            ((MODE) == GPIO_Mode_Out_PP) ||      \
                            ((MODE) == GPIO_Mode_In_HI) ||       \
                            ((MODE) == GPIO_Mode_Dual_OD))

typedef enum
{
    GPIO_Speed_Normal,
    GPIO_Speed_High,
} GPIO_Speed_enum;
#define IS_GPIO_Speed(SPEED) (((SPEED) == GPIO_Speed_Normal) || ((SPEED) == GPIO_Speed_High))

typedef enum
{
    GPIO_PullUp_0,
    GPIO_PullUp_4K1,
} GPIO_PullUp_enum;
#define IS_GPIO_PullUp(PU) (((PU) == GPIO_PullUp_0) || ((PU) == GPIO_PullUp_4K1))

typedef enum
{
    GPIO_Drive_Normal,
    GPIO_Drive_High,
} GPIO_Drive_enum;
#define IS_GPIO_Drive(DRV) (((DRV) == GPIO_Drive_Normal) || ((DRV) == GPIO_Drive_High))

typedef struct
{
    uint8_t GPIO_Pin;
    GPIO_Mode_enum GPIO_Mode;
} GPIO_InitTypedef;

void GPIO_Init(GPIO_Port_enum GPIOx, GPIO_InitTypedef *GPIO_InitStruct);
void GPIO_DeInit(GPIO_Port_enum GPIOx);

void GPIO_SpeedConfig(GPIO_Port_enum GPIOx, uint8_t GPIO_Pin, GPIO_Speed_enum GPIO_Speed);
void GPIO_PullUpConfig(GPIO_Port_enum GPIOx, uint8_t GPIO_Pin, GPIO_PullUp_enum GPIO_PullUpType);
void GPIO_DriveConfig(GPIO_Port_enum GPIOx, uint8_t GPIO_Pin, GPIO_Drive_enum GPIO_DriveType);

uint8_t GPIO_ReadData(GPIO_Port_enum GPIOx);
uint8_t GPIO_ReadDataBit(GPIO_Port_enum GPIOx, uint8_t GPIO_Pin);

void GPIO_SetBits(GPIO_Port_enum GPIOx, uint8_t GPIO_Pin);
void GPIO_ResetBits(GPIO_Port_enum GPIOx, uint8_t GPIO_Pin);
void GPIO_WriteBit(GPIO_Port_enum GPIOx, uint8_t GPIO_Pin, BOOL Val);
void GPIO_Write(GPIO_Port_enum GPIOx);
#endif