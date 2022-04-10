
// code = utf-8

#include "al_stc16x_tim.h"

/**
 * @brief 用给定参数初始化定时器功能
 *
 * @param TIMx 需要初始化的定时器
 * @param initStruct 初始化结构体
 */
void TIM_Init(TIM_enum TIMx, TIM_InitTypeDef *initStruct)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));
    al_assert(IS_TIM_ClkSrc(initStruct->TIM_ClockSource));
    al_assert(IS_TIM_Mode(initStruct->TIM_Mode));

    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        TR0 = 0; // 停止定时器使能

        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            AUXR |= (1 << 7);
            TMOD &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            AUXR &= ~(1 << 7);
            TMOD &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            TMOD |= (1 << 2);
            break;
        }
        default:
            break;
        }

        /* 设置初始值 */
        if (initStruct->TIM_Mode == TIM_Mode_8AR)
        {
            TL0 = (uint8_t)initStruct->TIM_AutoReloadValue; // 低8位
            TH0 = (uint8_t)initStruct->TIM_AutoReloadValue; // 低8位
        }
        else
        {
            TL0 = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
            TH0 = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位
        }

        /* 工作模式设置 */
        TMOD &= ~(0x03);                         // 清空工作模式
        TMOD |= ((uint8_t)initStruct->TIM_Mode); // 设置工作模式

        break;
    }
    case TIM1: // TIM1
    {
        TR1 = 0; // 停止定时器使能

        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            AUXR |= (1 << 6);
            TMOD &= ~(1 << 6);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            AUXR &= ~(1 << 6);
            TMOD &= ~(1 << 6);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            TMOD |= (1 << 6);
            break;
        }
        default:
            break;
        }

        /* 设置初始值 */
        if (initStruct->TIM_Mode == TIM_Mode_8AR)
        {
            TL1 = (uint8_t)initStruct->TIM_AutoReloadValue; // 低8位
            TH1 = (uint8_t)initStruct->TIM_AutoReloadValue; // 低8位
        }
        else
        {
            TL1 = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
            TH1 = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位
        }

        /* 工作模式设置 */
        TMOD &= ~(0x30);                              // 清空工作模式
        TMOD |= ((uint8_t)initStruct->TIM_Mode << 4); // 设置工作模式

        break;
    }
    case TIM2: // TIM2
    {
        AUXR &= ~(1 << 4); // 停止定时器使能

        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            AUXR |= (1 << 2);
            AUXR &= ~(1 << 3);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            AUXR &= ~(1 << 2);
            AUXR &= ~(1 << 3);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            AUXR |= (1 << 3);
            break;
        }

        default:
            break;
        }

        /* 设置初始值 */
        T2L = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
        T2H = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位

        break;
    }
    case TIM3: // TIM3
    {
        T4T3M &= ~(1 << 3); // 停止定时器使能

        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            T4T3M |= (1 << 1);
            T4T3M &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            T4T3M &= ~(1 << 1);
            T4T3M &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            T4T3M |= (1 << 2);
            break;
        }
        default:
            break;
        }

        /* 设置初始值 */
        T3L = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
        T3H = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位

        break;
    }
    case TIM4: // TIM4
    {
        T4T3M &= ~(1 << 7); // 停止定时器使能
        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            T4T3M |= (1 << 5);
            T4T3M &= ~(1 << 6);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            T4T3M &= ~(1 << 5);
            T4T3M &= ~(1 << 6);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            T4T3M |= (1 << 6);
            break;
        }
        default:
            break;
        }

        /* 设置初始值 */
        T4L = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
        T4H = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位

        break;
    }
    default:
        break;
    }
}

/**
 * @brief 用给定参数初始化定时器基础功能
 *
 * @param TIMx 需要初始化的定时器
 * @param initStruct 初始化结构体
 */
void TIM_BaseInit(TIM_enum TIMx, TIM_InitTypeDef *initStruct)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_PeriphBase(TIMx));
    al_assert(IS_TIM_ClkSrc(initStruct->TIM_ClockSource));
    al_assert(IS_TIM_BaseMode(initStruct->TIM_Mode));

    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        TR0 = 0; // 停止定时器使能

        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            AUXR |= (1 << 7);
            TMOD &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            AUXR &= ~(1 << 7);
            TMOD &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            TMOD |= (1 << 2);
            break;
        }
        default:
            break;
        }

        /* 设置初始值 */
        TL0 = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
        TH0 = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位

        /* 工作模式设置 */
        TMOD &= ~(0x03);                         // 清空工作模式
        TMOD |= ((uint8_t)initStruct->TIM_Mode); // 设置工作模式

        break;
    }
    case TIM1: // TIM1
    {
        TR1 = 0; // 停止定时器使能

        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            AUXR |= (1 << 6);
            TMOD &= ~(1 << 6);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            AUXR &= ~(1 << 6);
            TMOD &= ~(1 << 6);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            TMOD |= (1 << 6);
            break;
        }
        default:
            break;
        }

        /* 设置初始值 */
        TL1 = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
        TH1 = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位

        /* 工作模式设置 */
        TMOD &= ~(0x30);                              // 清空工作模式
        TMOD |= ((uint8_t)initStruct->TIM_Mode << 4); // 设置工作模式

        break;
    }
    case TIM2: // TIM2
    {
        AUXR &= ~(1 << 4); // 停止定时器使能

        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            AUXR |= (1 << 2);
            AUXR &= ~(1 << 3);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            AUXR &= ~(1 << 2);
            AUXR &= ~(1 << 3);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            AUXR |= (1 << 3);
            break;
        }

        default:
            break;
        }

        /* 设置初始值 */
        T2L = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
        T2H = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位

        break;
    }
    case TIM3: // TIM3
    {
        T4T3M &= ~(1 << 3); // 停止定时器使能

        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            T4T3M |= (1 << 1);
            T4T3M &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            T4T3M &= ~(1 << 1);
            T4T3M &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            T4T3M |= (1 << 2);
            break;
        }
        default:
            break;
        }

        /* 设置初始值 */
        T3L = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
        T3H = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位

        break;
    }
    case TIM4: // TIM4
    {
        T4T3M &= ~(1 << 7); // 停止定时器使能
        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            T4T3M |= (1 << 5);
            T4T3M &= ~(1 << 6);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            T4T3M &= ~(1 << 5);
            T4T3M &= ~(1 << 6);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            T4T3M |= (1 << 6);
            break;
        }
        default:
            break;
        }

        /* 设置初始值 */
        T4L = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
        T4H = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位

        break;
    }
    default:
        break;
    }
}

/**
 * @brief 用给定参数初始化定时器高级功能
 *
 * @param TIMx 需要初始化的定时器，仅TIM0、TIM1
 * @param initStruct 初始化结构体
 */
void TIM_AdvInit(TIM_enum TIMx, TIM_InitTypeDef *initStruct)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_PeriphAdv(TIMx));
    al_assert(IS_TIM_ClkSrc(initStruct->TIM_ClockSource));
    al_assert(IS_TIM_AdvMode(initStruct->TIM_Mode));

    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        TR0 = 0; // 停止定时器使能

        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            AUXR |= (1 << 7);
            TMOD &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            AUXR &= ~(1 << 7);
            TMOD &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            TMOD |= (1 << 2);
            break;
        }
        default:
            break;
        }

        /* 设置初始值 */
        if (initStruct->TIM_Mode == TIM_Mode_8AR)
        {
            TL0 = (uint8_t)initStruct->TIM_AutoReloadValue; // 低8位
            TH0 = (uint8_t)initStruct->TIM_AutoReloadValue; // 低8位
        }
        else
        {
            TL0 = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
            TH0 = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位
        }

        /* 工作模式设置 */
        TMOD &= ~(0x03);                         // 清空工作模式
        TMOD |= ((uint8_t)initStruct->TIM_Mode); // 设置工作模式

        break;
    }
    case TIM1: // TIM1
    {
        TR1 = 0; // 停止定时器使能

        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            AUXR |= (1 << 6);
            TMOD &= ~(1 << 6);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            AUXR &= ~(1 << 6);
            TMOD &= ~(1 << 6);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            TMOD |= (1 << 6);
            break;
        }
        default:
            break;
        }

        /* 设置初始值 */
        if (initStruct->TIM_Mode == TIM_Mode_8AR)
        {
            TL1 = (uint8_t)initStruct->TIM_AutoReloadValue; // 低8位
            TH1 = (uint8_t)initStruct->TIM_AutoReloadValue; // 低8位
        }
        else
        {
            TL1 = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
            TH1 = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位
        }

        /* 工作模式设置 */
        TMOD &= ~(0x30);                              // 清空工作模式
        TMOD |= ((uint8_t)initStruct->TIM_Mode << 4); // 设置工作模式

        break;
    }
    default:
        break;
    }
}

/**
 * @brief 用给定参数初始化定时器完整功能
 *
 * @param TIMx 需要初始化的定时器，仅TIM0
 * @param initStruct 初始化结构体
 */
void TIM_FullInit(TIM_enum TIMx, TIM_InitTypeDef *initStruct)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_PeriphFull(TIMx));
    al_assert(IS_TIM_ClkSrc(initStruct->TIM_ClockSource));
    al_assert(IS_TIM_FullMode(initStruct->TIM_Mode));

    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        TR0 = 0; // 停止定时器使能

        /* 设置时钟源 */
        switch (initStruct->TIM_ClockSource)
        {
        case TIM_ClkSrc_DIV1: // 时钟源为主时钟
        {
            AUXR |= (1 << 7);
            TMOD &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_DIV12: // 时钟源为12分频的主时钟
        {
            AUXR &= ~(1 << 7);
            TMOD &= ~(1 << 2);
            break;
        }
        case TIM_ClkSrc_EXT: // 时钟源为外部脉冲
        {
            TMOD |= (1 << 2);
            break;
        }
        default:
            break;
        }

        /* 设置初始值 */
        if (initStruct->TIM_Mode == TIM_Mode_8AR)
        {
            TL0 = (uint8_t)initStruct->TIM_AutoReloadValue; // 低8位
            TH0 = (uint8_t)initStruct->TIM_AutoReloadValue; // 低8位
        }
        else
        {
            TL0 = (uint8_t)initStruct->TIM_AutoReloadValue;        // 低8位
            TH0 = (uint8_t)(initStruct->TIM_AutoReloadValue >> 8); // 高8位
        }

        /* 工作模式设置 */
        TMOD &= ~(0x03);                         // 清空工作模式
        TMOD |= ((uint8_t)initStruct->TIM_Mode); // 设置工作模式

        break;
    }
    default:
        break;
    }
}

/**
 * @brief 定时器输出时钟功能配置
 *
 * @param TIMx 要配置的定时器
 * @param status 功能状态: 开启/关闭
 */
void TIM_ClockOutputConfig(TIM_enum TIMx, statusType status)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));
    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        if (status)
            INTCLKO |= (1 << 0); // 设置控制位
        else
            INTCLKO &= ~(1 << 0); // 清除控制位
        break;
    }
    case TIM1: // TIM1
    {
        if (status)
            INTCLKO |= (1 << 1); // 设置控制位
        else
            INTCLKO &= ~(1 << 1); // 清除控制位
        break;
    }
    case TIM2: // TIM2
    {
        if (status)
            INTCLKO |= (1 << 2); // 设置控制位
        else
            INTCLKO &= ~(1 << 2); // 清除控制位
        break;
    }
    case TIM3: // TIM3
    {
        if (status)
            T4T3M |= (1 << 0); // 设置控制位
        else
            T4T3M &= ~(1 << 0); // 清除控制位
        break;
    }
    case TIM4: // TIM4
    {
        if (status)
            T4T3M |= (1 << 4); // 设置控制位
        else
            T4T3M &= ~(1 << 4); // 清除控制位
        break;
    }
    default:
        break;
    }
}

/**
 * @brief 定时器中断功能配置
 *
 * @param TIMx 要配置的定时器
 * @param status 功能状态: 开启/关闭
 */
void TIM_ITConfig(TIM_enum TIMx, statusType status)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));
    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        if (status)
            IE0 = 1; // 设置控制位
        else
            IE0 = 0; // 清除控制位
        break;
    }
    case TIM1: // TIM1
    {
        if (status)
            IE1 = 1; // 设置控制位
        else
            IE1 = 0; // 清除控制位
        break;
    }
    case TIM2: // TIM2
    {
        if (status)
            AUXINTIF |= (1 << 0); // 设置控制位
        else
            AUXINTIF &= ~(1 << 0); // 清除控制位
        break;
    }
    case TIM3: // TIM3
    {
        if (status)
            AUXINTIF |= (1 << 1); // 设置控制位
        else
            AUXINTIF &= ~(1 << 1); // 清除控制位
        break;
    }
    case TIM4: // TIM4
    {
        if (status)
            AUXINTIF |= (1 << 2); // 设置控制位
        else
            AUXINTIF &= ~(1 << 2); // 清除控制位
        break;
    }
    default:
        break;
    }
}

