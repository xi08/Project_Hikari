// code = utf-8

#ifndef __al_stc16x_tim_h
#define __al_stc16x_tim_h

#include "al_stc16x.h"

#ifdef USE_AltLib

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
#define IS_TIM_Periph(PERIPH) (((PERIPH) == TIM0) || \
                               ((PERIPH) == TIM1) || \
                               ((PERIPH) == TIM2) || \
                               ((PERIPH) == TIM3) || \
                               ((PERIPH) == TIM4))

#define IS_TIM_PeriphBase(PERIPH) (((PERIPH) == TIM0) || \
                                   ((PERIPH) == TIM1) || \
                                   ((PERIPH) == TIM2) || \
                                   ((PERIPH) == TIM3) || \
                                   ((PERIPH) == TIM4))

#define IS_TIM_PeriphAdv(PERIPH) (((PERIPH) == TIM0) || \
                                  ((PERIPH) == TIM1))

#define IS_TIM_PeriphFull(PERIPH) (((PERIPH) == TIM0))

#define IS_TIM_PeriphMultiMode(PERIPH) (((PERIPH) == TIM0) || \
                                        ((PERIPH) == TIM1))

/**
 * @brief 定时器基础功能枚举
 *
 */
typedef enum
{
    TIM_Mode_16AR = 0, // 16位自动重载
    TIM_Mode_16,       // 16位软件重载
    TIM_Mode_8AR,      // 8位自动重载
    TIM_Mode_16NR,     // 16位不可屏蔽自动重载
} TIM_Mode_enum;
#define IS_TIM_Mode(MODE) (((MODE) == TIM_Mode_16AR) || \
                           ((MODE) == TIM_Mode_16) ||   \
                           ((MODE) == TIM_Mode_8AR) ||  \
                           ((MODE) == TIM_Mode_16NR))

#define IS_TIM_ModeFull(MODE) (((MODE) == TIM_Mode_16AR) || \
                               ((MODE) == TIM_Mode_16) ||   \
                               ((MODE) == TIM_Mode_8AR) ||  \
                               ((MODE) == TIM_Mode_16NR))

#define IS_TIM_ModeBase(MODE) (((MODE) == TIM_Mode_16AR))

#define IS_TIM_ModeAdv(MODE) (((MODE) == TIM_Mode_16AR) || \
                              ((MODE) == TIM_Mode_16) ||   \
                              ((MODE) == TIM_Mode_8AR))

/**
 * @brief 定时器时钟源枚举
 *
 */
typedef enum
{
    TIM_ClkSrc_DIV1 = 0, // 主时钟, 1分频
    TIM_ClkSrc_DIV12,    // 主时钟, 12分频
    TIM_ClkSrc_EXT,      // 外部时钟源

} TIM_ClockSource_enum;
#define IS_TIM_ClkSrc(SRC) (((SRC) == TIM_ClkSrc_DIV1) ||  \
                            ((SRC) == TIM_ClkSrc_DIV12) || \
                            ((SRC) == TIM_ClkSrc_EXT))

/**
 * @brief 定时器中断触发源
 *
 */
#define TIM_IT_Update ((uint8_t)0x01) // 定时器更新中断
#define IS_TIM_IT(SRC) ((SRC) != (uint8_t)0x00)

/**
 * @brief 定时器标记位置位触发源
 *
 */
#define TIM_FLAG_Update ((uint8_t)0x01) // 定时器更新标记
#define IS_TIM_FLAG(SRC) ((SRC) != (uint8_t)0x00)

/**
 * @brief 定时器初始化结构体
 *
 */
typedef struct
{
    TIM_Mode_enum TIM_Mode;
    TIM_ClockSource_enum TIM_ClockSource;
    uint16_t TIM_AutoReloadValue;

} TIM_InitTypeDef;

void TIM_DeInit(TIM_enum TIMx);
void TIM_Init(TIM_enum TIMx, TIM_InitTypeDef *initStruct);
void TIM_Cmd(TIM_enum TIMx, statusType newStatus);

void TIM_ClockOutputConfig(TIM_enum TIMx, statusType newStatus);
void TIM_ModeConfig(TIM_enum TIMx, TIM_Mode_enum newMode);
void TIM_ClkSrcConfig(TIM_enum TIMx, TIM_ClockSource_enum newSrc);

void TIM_SetVal(TIM_enum TIMx, uint16_t newVal);
void TIM_SetAutoReload(TIM_enum TIMx, uint16_t newVal);
void TIM_SetCounter(TIM_enum TIMx, uint16_t newVal);

uint16_t TIM_GetVal(TIM_enum TIMx);
uint16_t TIM_GetCounter(TIM_enum TIMx);

void TIM_ITConfig(TIM_enum TIMx, uint16_t TIM_IT, statusType newStatus);
flagType TIM_GetITStatus(TIM_enum TIMx, uint16_t TIM_IT);
void TIM_ClearITPendingBit(TIM_enum TIMx, uint16_t TIM_IT);

void TIM_FlagConfig(TIM_enum TIMx, uint16_t TIM_FLAG, statusType newStatus);
flagType TIM_GetFlagStatus(TIM_enum TIMx, uint16_t TIM_FLAG);
void TIM_ClearFlag(TIM_enum TIMx, uint16_t TIM_FLAG);

void TIM_PIT_Init(TIM_enum TIMx, uint16_t autoReloadValue);
void TIM_CNT_Init(TIM_enum TIMx);
uint16_t TIM_CNT_GetVal(TIM_enum TIMx);

#endif
#endif
