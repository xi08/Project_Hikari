
#ifndef __al_stc16x_exti_h
#define __al_stc16x_exti_h

#include "al_stc16x.h"
#ifdef USE_AltLib

/**
 * @brief 外部中断通道枚举
 *
 */
typedef enum
{
    EXTI_P32,
    EXTI_P33,
    EXTI_P36,
    EXTI_P37,
    EXTI_P30,
} EXTI_Channel_enum;
#define IS_EXTI_Channel(CH)                                                                                            \
    (((CH) == EXTI_P32) || ((CH) == EXTI_P33) || ((CH) == EXTI_P36) || ((CH) == EXTI_P37) || ((CH) == EXTI_P30))
#define IS_EXTI_Channel_Full(CH) (((CH) == EXTI_P32) || ((CH) == EXTI_P33))
#define IS_EXTI_Channel_Fall(CH) (((CH) == EXTI_P36) || ((CH) == EXTI_P37) || ((CH) == EXTI_P30))

/**
 * @brief 外部中断触发模式枚举
 *
 */
typedef enum
{
    EXTI_Trigger_Rising_Falling, // 边沿触发
    EXTI_Trigger_Falling,        // 下降沿触发
} EXTI_Trigger_enum;
#define IS_EXTI_TRIGGER(TRIG) (((TRIG) == EXTI_Trigger_Falling) || ((TRIG) == EXTI_Trigger_Rising_Falling))

/**
 * @brief 外部中断工作模式枚举
 *
 */
typedef enum
{
    EXTI_Mode_Interrupt, // 中断模式
    EXTI_Mode_Event,     // 事件模式（查询模式）
} EXTI_Mode_enum;
#define IS_EXTI_MODE(MODE) (((MODE) == EXTI_Mode_Interrupt) || ((MODE) == EXTI_Mode_Event))

typedef struct
{
    EXTI_Channel_enum EXTIx;
    EXTI_Trigger_enum EXTI_Trigger;
    EXTI_Mode_enum EXTI_Mode;
} EXTI_InitTypeDef;

void EXTI_Init(EXTI_InitTypeDef *initStruct);
flagType EXTI_GetFlagStatus(EXTI_Channel_enum EXTI_Channel);
void EXTI_ClearFlag(EXTI_Channel_enum EXTI_Channel);
flagType EXTI_GetITStatus(EXTI_Channel_enum EXTI_Channel);
void EXTI_ClearITPendingBit(EXTI_Channel_enum EXTI_Channel);

#endif
#endif
