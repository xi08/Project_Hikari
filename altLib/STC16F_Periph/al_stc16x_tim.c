// code = utf-8

#include "al_stc16x_tim.h"
#ifdef USE_AltLib

/**
 * @brief 将定时器恢复初始值
 *
 * @param TIMx 目标定时器
 */
void TIM_DeInit(TIM_enum TIMx)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));

    /* 清空参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        TR0 = 0;              // 停止使能定时器
        TL0 = 0;              // 清除低8位装载值
        TH0 = 0;              // 清除高8位装载值
        TMOD &= ~(1 << 2);    // 清除外部输入设置
        AUXR &= ~(1 << 7);    // 清除主时钟分频设置
        TMOD &= ~(0x03);      // 清除工作模式
        INTCLKO &= ~(1 << 0); // 清除输出时钟功能配置
        ET0 = 0;              // 清除中断功能配置
        break;
    }
    case TIM1: // TIM1
    {
        TR1 = 0;              // 停止使能定时器
        TL1 = 0;              // 清除低8位装载值
        TH1 = 0;              // 清除高8位装载值
        TMOD &= ~(1 << 6);    // 清除外部输入设置
        AUXR &= ~(1 << 6);    // 清除主时钟分频设置
        TMOD &= ~(0x30);      // 清除工作模式
        INTCLKO &= ~(1 << 1); // 清除输出时钟功能配置
        ET1 = 0;              // 清除中断功能配置
        break;
    }
    case TIM2: // TIM2
    {
        AUXR &= ~(1 << 4);    // 停止使能定时器
        T2L = 0;              // 清除低8位装载值
        T2H = 0;              // 清除高8位装载值
        AUXR &= ~(1 << 3);    // 清除外部输入设置
        AUXR &= ~(1 << 2);    // 清除主时钟分频设置
        INTCLKO &= ~(1 << 2); // 清除输出时钟功能配置
        IE2 &= ~(1 << 2);     // 清除中断功能配置
        break;
    }
    case TIM3: // TIM3
    {
        T4T3M &= ~(1 << 3); // 停止使能定时器
        T3L = 0;            // 清除低8位装载值
        T3H = 0;            // 清除高8位装载值
        T4T3M &= ~(1 << 2); // 清除外部输入设置
        T4T3M &= ~(1 << 1); // 清除主时钟分频设置
        T4T3M &= ~(1 << 0); // 清除输出时钟功能配置
        IE2 &= ~(1 << 5);   // 清除中断功能配置
        break;
    }
    case TIM4: // TIM4
    {
        T4T3M &= ~(1 << 7); // 停止使能定时器
        T4L = 0;            // 清除低8位装载值
        T4H = 0;            // 清除高8位装载值
        T4T3M &= ~(1 << 6); // 清除外部输入设置
        T4T3M &= ~(1 << 5); // 清除主时钟分频设置
        T4T3M &= ~(1 << 4); // 清除输出时钟功能配置
        IE2 &= ~(1 << 6);   // 清除中断功能配置
        break;
    }
    default:
        break;
    }
}

/**
 * @brief 用给定参数初始化定时器功能
 *
 * @param TIMx 目标定时器
 * @param initStruct 初始化结构体
 */
void TIM_Init(TIM_enum TIMx, TIM_InitTypeDef *initStruct)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));
    al_assert(IS_TIM_ClkSrc(initStruct->TIM_ClockSource));
    if (IS_TIM_PeriphBase(TIMx))
    {
        al_assert(IS_TIM_Mode(initStruct->TIM_Mode));
    }
    else if (IS_TIM_PeriphAdv(TIMx))
    {
        al_assert(IS_TIM_ModeAdv(initStruct->TIM_Mode));
    }
    else if (IS_TIM_PeriphFull(TIMx))
    {
        al_assert(IS_TIM_ModeFull(initStruct->TIM_Mode));
    }

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
            TL0 = (uint8_t)initStruct->TIM_AutoReloadValue; // 8位
            TH0 = (uint8_t)initStruct->TIM_AutoReloadValue; // 8位
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
            TL1 = (uint8_t)initStruct->TIM_AutoReloadValue; // 8位
            TH1 = (uint8_t)initStruct->TIM_AutoReloadValue; // 8位
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
 * @brief 定时器输出时钟功能配置
 *
 * @param TIMx 目标定时器
 * @param newStatus 功能状态: 开启/关闭
 */
void TIM_ClockOutputConfig(TIM_enum TIMx, statusType newStatus)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));

    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        if (newStatus)
            INTCLKO |= (1 << 0); // 设置控制位
        else
            INTCLKO &= ~(1 << 0); // 清除控制位
        break;
    }
    case TIM1: // TIM1
    {
        if (newStatus)
            INTCLKO |= (1 << 1); // 设置控制位
        else
            INTCLKO &= ~(1 << 1); // 清除控制位
        break;
    }
    case TIM2: // TIM2
    {
        if (newStatus)
            INTCLKO |= (1 << 2); // 设置控制位
        else
            INTCLKO &= ~(1 << 2); // 清除控制位
        break;
    }
    case TIM3: // TIM3
    {
        if (newStatus)
            T4T3M |= (1 << 0); // 设置控制位
        else
            T4T3M &= ~(1 << 0); // 清除控制位
        break;
    }
    case TIM4: // TIM4
    {
        if (newStatus)
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
 * @param TIMx 目标定时器
 * @param TIM_IT 中断的触发来源
 * @param newStatus 功能状态: 开启/关闭
 */
void TIM_ITConfig(TIM_enum TIMx, uint16_t TIM_IT, statusType newStatus)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));
    al_assert(IS_TIM_IT(TIM_IT));
    /* 设置参数 */
    switch (TIM_IT)
    {
    case TIM_IT_Update: // 定时器更新中断
        switch (TIMx)
        {
        case TIM0: // TIM0
        {
            if (newStatus)
                ET0 = 1; // 设置控制位
            else
                ET0 = 0; // 清除控制位
            break;
        }
        case TIM1: // TIM1
        {
            if (newStatus)
                ET1 = 1; // 设置控制位
            else
                ET1 = 0; // 清除控制位
            break;
        }
        case TIM2: // TIM2
        {
            if (newStatus)
                IE2 |= (1 << 2); // 设置控制位
            else
                IE2 &= ~(1 << 2); // 清除控制位
            break;
        }
        case TIM3: // TIM3
        {
            if (newStatus)
                IE2 |= (1 << 5); // 设置控制位
            else
                IE2 &= ~(1 << 5); // 清除控制位
            break;
        }
        case TIM4: // TIM4
        {
            if (newStatus)
                IE2 |= (1 << 6); // 设置控制位
            else
                IE2 &= ~(1 << 6); // 清除控制位
            break;
        }
        default:
            break;
        }
        break;
    default:
        break;
    }
}

/**
 * @brief 获取定时器中断标记
 *
 * @param TIMx 目标定时器
 * @param TIM_IT 中断的触发来源
 * @return flagType 中断标记的置位信息
 */
flagType TIM_GetITStatus(TIM_enum TIMx, uint16_t TIM_IT)
{
}

/**
 * @brief 清除定时器中断标记
 *
 * @param TIMx 目标定时器
 * @param TIM_IT 中断的触发来源
 */
void TIM_ClearITPendingBit(TIM_enum TIMx, uint16_t TIM_IT)
{
}

/**
 * @brief 定时器使能状态配置
 *
 * @param TIMx 目标定时器
 * @param newStatus 功能状态: 开启/关闭
 */
void TIM_Cmd(TIM_enum TIMx, statusType newStatus)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));

    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        if (newStatus)
            TR0 = 1; // 设置控制位
        else
            TR0 = 0; // 清除控制位
        break;
    }
    case TIM1: // TIM1
    {
        if (newStatus)
            TR1 = 1; // 设置控制位
        else
            TR1 = 0; // 清除控制位
        break;
    }
    case TIM2: // TIM2
    {
        if (newStatus)
            AUXR |= (1 << 4); // 设置控制位
        else
            AUXR &= ~(1 << 4); // 清除控制位
        break;
    }
    case TIM3: // TIM3
    {
        if (newStatus)
            T4T3M |= (1 << 3); // 设置控制位
        else
            T4T3M &= ~(1 << 3); // 清除控制位
        break;
    }
    case TIM4: // TIM4
    {
        if (newStatus)
            T4T3M |= (1 << 7); // 设置控制位
        else
            T4T3M &= ~(1 << 7); // 清除控制位
        break;
    }
    default:
        break;
    }
}

/**
 * @brief 定时器工作模式配置
 *
 * @param TIMx 目标定时器
 * @param newMode 新工作状态
 */
void TIM_ModeConfig(TIM_enum TIMx, TIM_Mode_enum newMode)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_PeriphMultiMode(TIMx));
    if (IS_TIM_PeriphAdv(TIMx))
    {
        al_assert(IS_TIM_ModeAdv(newMode));
    }
    else if (IS_TIM_PeriphFull(TIMx))
    {
        al_assert(IS_TIM_ModeFull(newMode));
    }

    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        TMOD &= ~(0x03);            // 清空工作模式
        TMOD |= ((uint8_t)newMode); // 设置工作模式
        break;
    }
    case TIM1: // TIM1
    {
        TMOD &= ~(0x30);                 // 清空工作模式
        TMOD |= ((uint8_t)newMode << 4); // 设置工作模式
        break;
    }
    default:
        break;
    }
}

/**
 * @brief 定时器时钟源配置
 *
 * @param TIMx 目标定时器
 * @param newSrc 新时钟源
 */
void TIM_ClockSourceConfig(TIM_enum TIMx, TIM_ClkSrc_enum newSrc)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));
    al_assert(IS_TIM_ClkSrc(newSrc));

    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        switch (newSrc)
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
        break;
    }
    case TIM1: // TIM1
    {
        switch (newSrc)
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

        break;
    }
    case TIM2: // TIM2
    {
        switch (newSrc)
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
        break;
    }
    case TIM3: // TIM3
    {
        switch (newSrc)
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

        break;
    }
    case TIM4: // TIM4
    {
        switch (newSrc)
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
        break;
    }
    default:
        break;
    }
}

/**
 * @brief 定时器计数值配置
 *
 * @param TIMx 目标定时器
 * @param newVal 新计数值
 */
void TIM_SetVal(TIM_enum TIMx, uint16_t newVal)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));

    /* 设置参数 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        if ((TMOD & (1 << 1)) && !(TMOD & (1 << 0))) // TMOD == 0bxxxxxx10, TIM_Mode_8AR
        {
            TH0 = (uint8_t)newVal; // 8位
        }
        else
        {
            TL0 = (uint8_t)newVal;        // 低8位
            TH0 = (uint8_t)(newVal >> 8); // 高8位
        }
        break;
    }
    case TIM1: // TIM1
    {
        if ((TMOD & (1 << 5)) && !(TMOD & (1 << 4))) // TMOD == 0bxx10xxxx, TIM_Mode_8AR
        {
            TH0 = (uint8_t)newVal; // 8位
        }
        else
        {
            TL0 = (uint8_t)newVal;        // 低8位
            TH0 = (uint8_t)(newVal >> 8); // 高8位
        }
        break;
    }
    case TIM2: // TIM2
    {
        T2L = (uint8_t)newVal;        // 低8位
        T2H = (uint8_t)(newVal >> 8); // 高8位
        break;
    }
    case TIM3: // TIM3
    {
        T3L = (uint8_t)newVal;        // 低8位
        T3H = (uint8_t)(newVal >> 8); // 高8位
        break;
    }
    case TIM4: // TIM4
    {
        T4L = (uint8_t)newVal;        // 低8位
        T4H = (uint8_t)(newVal >> 8); // 高8位
        break;
    }
    default:
        break;
    }
}

/**
 * @brief 获取定时器计数值
 *
 * @param TIMx 目标定时器
 * @return uint16_t 计数值
 */
uint16_t TIM_GetVal(TIM_enum TIMx)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));

    /* 获取值 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        if ((TMOD & (1 << 1)) && !(TMOD & (1 << 0))) // TMOD == 0bxxxxxx10, TIM_Mode_8AR
            return ((uint16_t)TL0);
        else
            return (((uint16_t)TH0 << 8) | ((uint8_t)TL0));
        break;
    }
    case TIM1: // TIM1
    {
        if ((TMOD & (1 << 5)) && !(TMOD & (1 << 4))) // TMOD == 0bxx10xxxx, TIM_Mode_8AR
            return ((uint16_t)TL1);
        else
            return (((uint16_t)TH1 << 8) | ((uint8_t)TL1));
        break;
    }
    case TIM2: // TIM2
    {
        return (((uint16_t)T2H << 8) | ((uint8_t)T2L));
        break;
    }
    case TIM3: // TIM3
    {
        return (((uint16_t)T3H << 8) | ((uint8_t)T3L));
        break;
    }
    case TIM4: // TIM4
    {
        return (((uint16_t)T4H << 8) | ((uint8_t)T4L));
        break;
    }
    default:
    {
        return 0;
        break;
    }
    }
}

/**
 * @brief 设置定时器重装载值
 *
 * @param TIMx 目标定时器
 * @param newVal 新重装载值
 */
void TIM_SetAutoReload(TIM_enum TIMx, uint16_t newVal)
{

    TIM_SetVal(TIMx, newVal);
}

/**
 * @brief 设置定时器外部计数值
 *
 * @param TIMx 目标定时器
 * @param newVal 新计数值
 */
void TIM_SetCounter(TIM_enum TIMx, uint16_t newVal)
{
    TIM_SetVal(TIMx, newVal);
}

/**
 * @brief 获取定时器外部计数值
 *
 * @param TIMx 目标定时器
 * @return uint16_t 外部脉冲数
 */
uint16_t TIM_GetCounter(TIM_enum TIMx)
{
    return TIM_GetVal(TIMx);
}

/**
 * @brief 定时器状态位配置
 *
 * @param TIMx 目标定时器
 * @param TIM_FLAG 状态置位触发来源
 * @param newStatus 功能状态: 开启/关闭
 */
void TIM_FlagConfig(TIM_enum TIMx, uint16_t TIM_FLAG, statusType newStatus)
{
}

/**
 * @brief 获取定时器状态位
 *
 * @param TIMx 目标定时器
 * @param TIM_FLAG 状态置位触发来源
 * @return flagType 状态置位信息
 */
flagType TIM_GetFlagStatus(TIM_enum TIMx, uint16_t TIM_FLAG)
{
}

/**
 * @brief 清除定时器状态位
 *
 * @param TIMx 目标定时器
 * @param TIM_FLAG 状态置位触发来源
 */
void TIM_ClearFlag(TIM_enum TIMx, uint16_t TIM_FLAG)
{
}

/**
 * @brief 初始化定时器定时中断功能，(触发周期T) = 12*(65536-自动重装载值autoReloadValue)/系统频率SystemClock
 *
 *
 * @param TIMx 目标定时器
 * @param autoReloadValue 自动重装载值
 */
void TIM_PIT_Init(TIM_enum TIMx, uint16_t autoReloadValue)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));

    /* 设置定时器 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        TR1 = 0;                    // 停止使能定时器
        TL0 = autoReloadValue;      // 设置低位
        TH0 = autoReloadValue >> 8; // 设置高位
        TR0 = 1;                    // 使能定时器
        ET0 = 1;                    // 使能中断
        break;
    }
    case TIM1: // TIM1
    {
        TR1 = 0;                    // 停止使能定时器
        TL1 = autoReloadValue;      // 设置低位
        TH1 = autoReloadValue >> 8; // 设置高位
        TR1 = 1;                    // 使能定时器
        ET1 = 1;                    // 使能中断
        break;
    }
    case TIM2: // TIM2
    {
        AUXR &= ~(1 << 4);          // 停止使能定时器
        T2L = autoReloadValue;      // 设置低位
        T2H = autoReloadValue >> 8; // 设置高位
        AUXR &= ~(1 << 4);          // 使能定时器
        IE2 |= (1 << 2);            // 使能中断
        break;
    }
    case TIM3: // TIM3
    {
        T4T3M &= ~(1 << 3);         // 停止使能定时器
        T3L = autoReloadValue;      // 设置低位
        T3H = autoReloadValue >> 8; // 设置高位
        T4T3M |= (1 << 3);          // 使能定时器
        IE2 |= (1 << 5);            // 使能中断
        break;
    }
    case TIM4: // TIM4
    {
        T4T3M &= ~(1 << 7);         // 停止使能定时器
        T4L = autoReloadValue;      // 设置低位
        T4H = autoReloadValue >> 8; // 设置高位
        T4T3M |= (1 << 7);          // 使能定时器
        IE2 |= (1 << 6);            // 使能中断
        break;
    }
    default:
        break;
    }
}

/**
 * @brief 初始化定时器外部计数功能
 *
 * @param TIMx 目标定时器
 */
void TIM_CNT_Init(TIM_enum TIMx)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));

    /* 设置定时器 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        TR1 = 0;          // 停止使能定时器
        TMOD |= (1 << 2); // 设置时钟源为外部脉冲
        TL0 = 0;          // 设置低位
        TH0 = 0;          // 设置高位
        TR0 = 1;          // 使能定时器
        break;
    }
    case TIM1: // TIM1
    {
        TR1 = 0;          // 停止使能定时器
        TMOD |= (1 << 6); // 设置时钟源为外部脉冲
        TL1 = 0;          // 设置低位
        TH1 = 0;          // 设置高位
        TR1 = 1;          // 使能定时器
        break;
    }
    case TIM2: // TIM2
    {
        AUXR &= ~(1 << 4); // 停止使能定时器
        AUXR |= (1 << 3);  // 设置时钟源为外部脉冲
        T2L = 0;           // 设置低位
        T2H = 0;           // 设置高位
        AUXR |= (1 << 4);  // 使能定时器
        break;
    }
    case TIM3: // TIM3
    {
        T4T3M &= ~(1 << 3); // 停止使能定时器
        T4T3M |= (1 << 2);  // 设置时钟源为外部脉冲
        T3L = 0;            // 设置低位
        T3H = 0;            // 设置高位
        T4T3M |= (1 << 3);  // 使能定时器
        break;
    }
    case TIM4: // TIM4
    {
        T4T3M &= ~(1 << 7); // 停止使能定时器
        T4T3M |= (1 << 6);  // 设置时钟源为外部脉冲
        T4L = 0;            // 设置低位
        T4H = 0;            // 设置高位
        T4T3M |= (1 << 7);  // 使能定时器
        break;
    }
    default:
        break;
    }
}

/**
 * @brief 获取并清空定时器外部计数值
 *
 * @param TIMx 目标定时器
 * @return uint16_t 计数值
 */
uint16_t TIM_CNT_GetVal(TIM_enum TIMx)
{
    uint16_t timVal = 0;

    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));

    /* 获取并清空计数值 */
    switch (TIMx)
    {
    case TIM0: // TIM0
    {
        TR0 = 0;                     // 停止使能定时器
        timVal = (uint16_t)TH0 << 8; // 读出高位
        timVal |= ((uint8_t)TL0);    // 读出低位
        TH0 = 0;                     // 清除高位
        TL0 = 0;                     // 清除低位
        TR0 = 1;                     // 使能定时器
        break;
    }
    case TIM1: // TIM1
    {
        TR1 = 0;                     // 停止使能定时器
        timVal = (uint16_t)T2H << 8; // 读出高位
        timVal |= ((uint8_t)T2L);    // 读出低位
        TH1 = 0;                     // 清除高位
        TL1 = 0;                     // 清除低位
        TR1 = 1;                     // 使能定时器
        break;
    }
    case TIM2: // TIM2
    {
        AUXR &= ~(1 << 4);           // 停止使能定时器
        timVal = (uint16_t)T3H << 8; // 读出高位
        timVal |= ((uint8_t)T3L);    // 读出低位
        T2H = 0;                     // 清除高位
        T2L = 0;                     // 清除低位
        AUXR |= 1 << 4;              // 使能定时器
        break;
    }
    case TIM3: // TIM3
    {
        T4T3M &= ~(1 << 3);          // 停止使能定时器
        timVal = (uint16_t)T4H << 8; // 读出高位
        timVal |= ((uint8_t)T4L);    // 读出低位
        T3H = 0;                     // 清除高位
        T3L = 0;                     // 清除低位
        T4T3M |= (1 << 3);           // 使能定时器
        break;
    }
    case TIM4: // TIM4
    {
        T4T3M &= ~(1 << 7);          // 停止使能定时器
        timVal = (uint16_t)TH0 << 8; // 读出高位
        timVal |= ((uint8_t)TL0);    // 读出低位
        T4H = 0;                     // 清除高位
        T4L = 0;                     // 清除低位
        T4T3M |= (1 << 7);           // 使能定时器
        break;
    }
    default:
        break;
    }

    /* 返回计数值 */
    return timVal;
}

#endif
