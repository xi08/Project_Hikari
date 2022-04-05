// code = utf-8

#ifndef __al_stc16x_gpio_h
#define __al_stc16x_gpio_h

#include "al_stc16x.h"

/**
 * @brief GPIO组枚举
 *
 */
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
} GPIO_enum;
#define IS_GPIO_Periph(PERIPH) (((PERIPH) == GPIO0) || ((PERIPH) == GPIO1) || \
                            ((PERIPH) == GPIO2) || ((PERIPH) == GPIO3) || \
                            ((PERIPH) == GPIO4) || ((PERIPH) == GPIO5) || \
                            ((PERIPH) == GPIO6) || ((PERIPH) == GPIO7))
/**
 * @brief GPIO引脚
 *
 */
#define GPIO_Pin_0 ((uint8_t)0x01)
#define GPIO_Pin_1 ((uint8_t)0x02)
#define GPIO_Pin_2 ((uint8_t)0x04)
#define GPIO_Pin_3 ((uint8_t)0x08)
#define GPIO_Pin_4 ((uint8_t)0x10)
#define GPIO_Pin_5 ((uint8_t)0x20)
#define GPIO_Pin_6 ((uint8_t)0x40)
#define GPIO_Pin_7 ((uint8_t)0x80)
#define GPIO_Pin_All ((uint8_t)0xFF)
#define IS_GPIO_Pin(PIN) ((PIN) != (uint8_t)0x00)
#define IS_GPIO_GetPin(PIN) (((PIN) == (GPIO_Pin_0)) || ((PIN) == (GPIO_Pin_1)) || \
                             ((PIN) == (GPIO_Pin_2)) || ((PIN) == (GPIO_Pin_3)) || \
                             ((PIN) == (GPIO_Pin_4)) || ((PIN) == (GPIO_Pin_5)) || \
                             ((PIN) == (GPIO_Pin_6)) || ((PIN) == (GPIO_Pin_7)))

/**
 * @brief GPIO功能枚举
 *
 */
typedef enum
{
    GPIO_Mode_Dual_Normal, // 准双向口, PxM1=0/PxM0=0
    GPIO_Mode_Out_PP,      // 推挽输出, PxM1=0/PxM0=1
    GPIO_Mode_In_Floating, // 浮空输入, PxM1=0/PxM0=0
    GPIO_Mode_Out_OD,      // 开漏输出, PxM1=1/PxM0=1
} GPIO_Mode_enum;
#define IS_GPIO_Mode(MODE) (((MODE) == GPIO_Mode_Dual_Normal) || \
                            ((MODE) == GPIO_Mode_Out_PP) ||      \
                            ((MODE) == GPIO_Mode_In_Floating) || \
                            ((MODE) == GPIO_Mode_Out_OD))

/**
 * @brief GPIO速度状态枚举
 *
 */
typedef enum
{
    GPIO_Speed_Normal, // 慢速翻转, PxSR=1
    GPIO_Speed_High,   // 快速反转, PxSR=0
} GPIO_Speed_enum;
#define IS_GPIO_Speed(SPEED) (((SPEED) == GPIO_Speed_Normal) || ((SPEED) == GPIO_Speed_High))

/**
 * @brief GPIO端口内部集成上拉电阻状态枚举
 *
 */
typedef enum
{
    GPIO_PullUp_0,   // 禁止端口内部集成上拉电阻, PxPU=0
    GPIO_PullUp_4K1, // 端口内部集成上拉电阻为4.1K, PxPU=1
} GPIO_PullUp_enum;
#define IS_GPIO_PullUp(PUUP) (((PUUP) == GPIO_PullUp_0) || ((PUUP) == GPIO_PullUp_4K1))

/**
 * @brief GPIO驱动电流状态枚举
 *
 */
typedef enum
{
    GPIO_Currect_Normal, // 一般驱动电流, PxDR=1
    GPIO_Currect_High,   // 增强驱动电流, PxDR=0
} GPIO_Currect_enum;
#define IS_GPIO_Currect(CURR) (((CURR) == GPIO_Currect_Normal) || ((CURR) == GPIO_Currect_High))

/**
 * @brief GPIO引脚初始化结构体
 *
 */
typedef struct
{
    GPIO_Mode_enum GPIO_Mode;
    uint8_t GPIO_Pin;
} GPIO_InitTypeDef;

void GPIO_Init(GPIO_enum GPIOx, GPIO_InitTypeDef *initStruct);
void GPIO_DeInit(GPIO_enum GPIOx);

void GPIO_SpeedConfig(GPIO_enum GPIOx, uint8_t GPIO_Pin, GPIO_Speed_enum GPIO_Speed);
void GPIO_PullUpConfig(GPIO_enum GPIOx, uint8_t GPIO_Pin, GPIO_PullUp_enum GPIO_PullUpType);
void GPIO_CurrectConfig(GPIO_enum GPIOx, uint8_t GPIO_Pin, GPIO_Currect_enum GPIO_CurrectType);

uint8_t GPIO_ReadData(GPIO_enum GPIOx);
BOOL GPIO_ReadDataBit(GPIO_enum GPIOx, uint8_t GPIO_Pin);

void GPIO_SetBits(GPIO_enum GPIOx, uint8_t GPIO_Pin);
void GPIO_ResetBits(GPIO_enum GPIOx, uint8_t GPIO_Pin);
void GPIO_WriteBit(GPIO_enum GPIOx, uint8_t GPIO_Pin, BOOL Val);
void GPIO_Write(GPIO_enum GPIOx, uint8_t Val);
#endif