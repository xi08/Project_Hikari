
// code = utf-8

#include "al_stc16x_tim.h"

/**
 * @brief 用给定参数初始化定时器基础功能
 *
 * @param TIMx 需要初始化的定时器
 * @param initStruct 初始化结构体
 */
void TIM_BaseInit(TIM_enum TIMx, TIM_InitTypeDef *initStruct)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_PeriphList1(TIMx));
    al_assert(IS_TIM_ClkSrc(initStruct->TIM_ClockSource));
    al_assert(IS_TIM_ModeList1(initStruct->TIM_Mode));

    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0:
        TR0 = 0;                             // 停止定时器使能
        switch (initStruct->TIM_ClockSource) // 设置时钟源
        {
        case TIM_ClkSrc_DIV1:
            AUXR |= (1 << 7);
            TMOD &= ~(1 << 2);
            break;
        case TIM_ClkSrc_DIV12:
            AUXR &= ~(1 << 7);
            TMOD &= ~(1 << 2);
            break;
        case TIM_ClkSrc_EXT:
            TMOD |= (1 << 2);
            break;
        default:
            break;
        }
        TMOD &= ~(0x03);                         // 清空工作模式
        TMOD |= ((uint8_t)initStruct->TIM_Mode); // 设置工作模式
        break;
    case TIM1:
        TR1 = 0;                             // 停止定时器使能
        switch (initStruct->TIM_ClockSource) // 设置时钟源
        {
        case TIM_ClkSrc_DIV1:
            AUXR |= (1 << 6);
            TMOD &= ~(1 << 6);
            break;
        case TIM_ClkSrc_DIV12:
            AUXR &= ~(1 << 6);
            TMOD &= ~(1 << 6);
            break;
        case TIM_ClkSrc_EXT:
            TMOD |= (1 << 6);
            break;
        default:
            break;
        }
        TMOD &= ~(0x30);                              // 清空工作模式
        TMOD |= ((uint8_t)initStruct->TIM_Mode << 4); // 设置工作模式
        break;
    case TIM2:
        AUXR &= ~(1 << 4);                   // 停止定时器使能
        switch (initStruct->TIM_ClockSource) // 设置时钟源
        {
        case TIM_ClkSrc_DIV1:
            AUXR |= (1 << 2);
            AUXR &= ~(1 << 3);
            break;
        case TIM_ClkSrc_DIV12:
            AUXR &= ~(1 << 2);
            AUXR &= ~(1 << 3);
            break;
        case TIM_ClkSrc_EXT:
            AUXR |= (1 << 3);
            break;
        default:
            break;
        }
        break;
    case TIM3:
        T4T3M &= ~(1 << 3);                  // 停止定时器使能
        switch (initStruct->TIM_ClockSource) // 设置时钟源
        {
        case TIM_ClkSrc_DIV1:
            T4T3M |= (1 << 1);
            T4T3M &= ~(1 << 2);
            break;
        case TIM_ClkSrc_DIV12:
            T4T3M &= ~(1 << 1);
            T4T3M &= ~(1 << 2);
            break;
        case TIM_ClkSrc_EXT:
            T4T3M |= (1 << 2);
            break;
        default:
            break;
        }
        break;
    case TIM4:
        T4T3M &= ~(1 << 7);                  // 停止定时器使能
        switch (initStruct->TIM_ClockSource) // 设置时钟源
        {
        case TIM_ClkSrc_DIV1:
            T4T3M |= (1 << 5);
            T4T3M &= ~(1 << 6);
            break;
        case TIM_ClkSrc_DIV12:
            T4T3M &= ~(1 << 5);
            T4T3M &= ~(1 << 6);
            break;
        case TIM_ClkSrc_EXT:
            T4T3M |= (1 << 6);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}