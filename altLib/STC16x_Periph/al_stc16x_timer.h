
#ifndef __al_stc16x_Timer_h
#define __al_stc16x_Timer_h

#include "al_stc16x.h"

#ifdef USE_AltLib

/**
 * @brief 定时器枚举
 *
 */
typedef enum
{
    Timer0,
    Timer1,
    Timer2,
    Timer3,
    Timer4,
} Timer_enum;
#define IS_Timer_Periph(PERIPH)                                                                                        \
    (((PERIPH) == Timer0) || ((PERIPH) == Timer1) || ((PERIPH) == Timer2) || ((PERIPH) == Timer3) ||                   \
     ((PERIPH) == Timer4))

#define IS_Timer_PeriphBase(PERIPH)                                                                                    \
    (((PERIPH) == Timer0) || ((PERIPH) == Timer1) || ((PERIPH) == Timer2) || ((PERIPH) == Timer3) ||                   \
     ((PERIPH) == Timer4))

#define IS_Timer_PeriphAdv(PERIPH) (((PERIPH) == Timer0) || ((PERIPH) == Timer1))

#define IS_Timer_PeriphFull(PERIPH) (((PERIPH) == Timer0))

#define IS_Timer_PeriphMulTimerode(PERIPH) (((PERIPH) == Timer0) || ((PERIPH) == Timer1))

/**
 * @brief 定时器基础功能枚举
 *
 */
typedef enum
{
    Timer_Mode_16AR = 0, // 16位自动重载
    Timer_Mode_16,       // 16位软件重载
    Timer_Mode_8AR,      // 8位自动重载
    Timer_Mode_16NR,     // 16位不可屏蔽自动重载
} Timer_Mode_enum;
#define IS_Timer_Mode(MODE)                                                                                            \
    (((MODE) == Timer_Mode_16AR) || ((MODE) == Timer_Mode_16) || ((MODE) == Timer_Mode_8AR) ||                         \
     ((MODE) == Timer_Mode_16NR))

#define IS_Timer_ModeFull(MODE)                                                                                        \
    (((MODE) == Timer_Mode_16AR) || ((MODE) == Timer_Mode_16) || ((MODE) == Timer_Mode_8AR) ||                         \
     ((MODE) == Timer_Mode_16NR))

#define IS_Timer_ModeBase(MODE) (((MODE) == Timer_Mode_16AR))

#define IS_Timer_ModeAdv(MODE) (((MODE) == Timer_Mode_16AR) || ((MODE) == Timer_Mode_16) || ((MODE) == Timer_Mode_8AR))

/**
 * @brief 定时器时钟源枚举
 *
 */
typedef enum
{
    Timer_ClkSrc_DIV1 = 0, // 主时钟, 1分频
    Timer_ClkSrc_DIV12,    // 主时钟, 12分频
    Timer_ClkSrc_EXT,      // 外部时钟源

} Timer_ClkSrc_enum;
#define IS_Timer_ClkSrc(SRC)                                                                                           \
    (((SRC) == Timer_ClkSrc_DIV1) || ((SRC) == Timer_ClkSrc_DIV12) || ((SRC) == Timer_ClkSrc_EXT))

/**
 * @brief 定时器中断触发源
 *
 */
#define Timer_IT_Update ((uint16_t)0x0001) // 定时器更新
#define IS_Timer_IT(SRC) ((SRC) != (uint16_t)0)
#define IS_Timer_GET_IT(SRC) (((SRC) == Timer_IT_Update))

/**
 * @brief 定时器状态置位触发源
 *
 */
#define Timer_FLAG_Update ((uint16_t)0x0001) // 定时器更新
#define IS_Timer_FLAG(SRC) ((SRC) != (uint16_t)0)
#define IS_Timer_GET_FLAG(SRC) (((SRC) == Timer_IT_Update))

/**
 * @brief 定时器初始化结构体
 *
 */
typedef struct
{
    Timer_Mode_enum Timer_Mode;          // 定时器模式
    Timer_ClkSrc_enum Timer_ClockSource; // 定时器时钟源
    uint16_t Timer_AutoReloadValue;      // 定时器初始装载值

} Timer_InitTypeDef;

void Timer_DeInit(Timer_enum Timerx);
void Timer_Init(Timer_enum Timerx, Timer_InitTypeDef *initStruct);
void Timer_StructInit(Timer_InitTypeDef *initStruct);
void Timer_Cmd(Timer_enum Timerx, statusType newStatus);

void Timer_ClockOutputConfig(Timer_enum Timerx, statusType newStatus);
void Timer_ModeConfig(Timer_enum Timerx, Timer_Mode_enum newMode);
void Timer_ClockSourceConfig(Timer_enum Timerx, Timer_ClkSrc_enum newSrc);

void Timer_SetVal(Timer_enum Timerx, uint16_t newVal);
void Timer_SetAutoReload(Timer_enum Timerx, uint16_t newVal);
void Timer_SetCounter(Timer_enum Timerx, uint16_t newVal);

uint16_t Timer_GetVal(Timer_enum Timerx);
uint16_t Timer_GetCounter(Timer_enum Timerx);

void Timer_ITConfig(Timer_enum Timerx, uint16_t Timer_IT, statusType newStatus);
flagType Timer_GetITStatus(Timer_enum Timerx, uint16_t Timer_IT);
flagType Timer_GetFlagStatus(Timer_enum Timerx, uint16_t Timer_FLAG);
void Timer_ClearITPendingBit(Timer_enum Timerx, uint16_t Timer_IT);
void Timer_ClearFlag(Timer_enum Timerx, uint16_t Timer_FLAG);

void Timer_PIT_Init(Timer_enum Timerx, uint16_t autoReloadValue);
void Timer_CNT_Init(Timer_enum Timerx);
uint16_t Timer_CNT_GetVal(Timer_enum Timerx);

#endif
#endif
