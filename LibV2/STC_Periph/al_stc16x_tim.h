// code = utf-8

#ifndef __al_stc16x_tim_h
#define __al_stc16x_tim_h

#include "al_stc16x.h"

/**
 * @brief 定时器枚举
 *
 */
typedef enum
{
    TIM0,
    TIM1,
    TIM2,
    TIM3,
    TIM4,
} TIM_enum;
#define IS_TIM_Periph(PERIPH) (((PERIPH) == TIM0) || ((PERIPH) == TIM1) || \
                               ((PERIPH) == TIM2) || ((PERIPH) == TIM3) || \
                               ((PERIPH) == TIM4))
/**
 * @brief 定时器基础功能枚举
 *
 */
typedef enum
{
    TIM_Mode_A16, // 16位自动重载
    TIM_Mode_CNT, // 外部计数
} TIM_Mode_enum;
#define IS_TIM_Mode(MODE) ((MODE == TIM_Mode_A16) || (MODE == TIM_Mode_CNT))
/**
 * @brief 定时器分频系数枚举
 *
 */
typedef enum
{
    TIM_CKD_DIV1,  // 主时钟1分频
    TIM_CKD_DIV12, // 主时钟12分频
} TIM_ClockDivision_enum;
#define IS_TIM_ClkDiv(DIV) ((DIV == TIM_CKD_DIV1) || (DIV == TIM_CKD_DIV12))

/**
 * @brief 定时器初始化结构体
 *
 */
typedef struct
{
    TIM_Mode_enum TIM_Mode;
    TIM_ClockDivision_enum TIM_CKD_DIVx;
} TIM_InitTypeDef;

void TIM_Init(TIM_enum TIMx, TIM_InitTypeDef *initStruct);

void TIM_DeInit(TIM_enum TIMx);

void TIM0_NoMaskModeInit(TIM_ClockDivision_enum TIM_CLKDIV);

void TIM_ClockOutputConfig(TIM_enum TIMx, BOOL funcStatus);

#endif