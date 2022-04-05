// code = utf-8

#include "al_stc16x_gpio.h"

/**
 * @brief 用给定参数初始化GPIO引脚
 *
 * @param GPIOx 需要初始化的引脚所属GPIO组
 * @param initStruct 初始化结构体
 */
void GPIO_Init(GPIO_enum GPIOx, GPIO_InitTypeDef *initStruct)
{
    /* 检查参数合法性 */
    al_assert(IS_GPIO_Periph(GPIOx));
    al_assert(IS_GPIO_Mode(initStruct->GPIO_Mode));
    al_assert(IS_GPIO_Pin(initStruct->GPIO_Pin));
    /* 设置参数 */
    switch (initStruct->GPIO_Mode)
    {
    case GPIO_Mode_Dual_Normal:

        switch (GPIOx)
        {
        case GPIO0:
            P0M1 &= ~initStruct->GPIO_Pin;
            P0M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO1:
            P1M1 &= ~initStruct->GPIO_Pin;
            P1M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO2:
            P2M1 &= ~initStruct->GPIO_Pin;
            P2M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO3:
            P3M1 &= ~initStruct->GPIO_Pin;
            P3M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO4:
            P4M1 &= ~initStruct->GPIO_Pin;
            P4M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO5:
            P5M1 &= ~initStruct->GPIO_Pin;
            P5M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO6:
            P6M1 &= ~initStruct->GPIO_Pin;
            P6M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO7:
            P7M1 &= ~initStruct->GPIO_Pin;
            P7M0 &= ~initStruct->GPIO_Pin;
            break;
        default:
            break;
        }
        break;
    case GPIO_Mode_Out_PP:
        switch (GPIOx)
        {
        case GPIO0:
            P0M1 &= ~initStruct->GPIO_Pin;
            P0M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO1:
            P1M1 &= ~initStruct->GPIO_Pin;
            P1M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO2:
            P2M1 &= ~initStruct->GPIO_Pin;
            P2M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO3:
            P3M1 &= ~initStruct->GPIO_Pin;
            P3M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO4:
            P4M1 &= ~initStruct->GPIO_Pin;
            P4M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO5:
            P5M1 &= ~initStruct->GPIO_Pin;
            P5M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO6:
            P6M1 &= ~initStruct->GPIO_Pin;
            P6M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO7:
            P7M1 &= ~initStruct->GPIO_Pin;
            P7M0 |= initStruct->GPIO_Pin;
            break;
        default:
            break;
        }
        break;
    case GPIO_Mode_In_Floating:
        switch (GPIOx)
        {
        case GPIO0:
            P0M1 |= initStruct->GPIO_Pin;
            P0M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO1:
            P1M1 |= initStruct->GPIO_Pin;
            P1M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO2:
            P2M1 |= initStruct->GPIO_Pin;
            P2M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO3:
            P3M1 |= initStruct->GPIO_Pin;
            P3M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO4:
            P4M1 |= initStruct->GPIO_Pin;
            P4M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO5:
            P5M1 |= initStruct->GPIO_Pin;
            P5M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO6:
            P6M1 |= initStruct->GPIO_Pin;
            P6M0 &= ~initStruct->GPIO_Pin;
            break;
        case GPIO7:
            P7M1 |= initStruct->GPIO_Pin;
            P7M0 &= ~initStruct->GPIO_Pin;
            break;
        default:
            break;
        }
        break;
    case GPIO_Mode_Out_OD:
        switch (GPIOx)
        {
        case GPIO0:
            P0M1 |= initStruct->GPIO_Pin;
            P0M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO1:
            P1M1 |= initStruct->GPIO_Pin;
            P1M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO2:
            P2M1 |= initStruct->GPIO_Pin;
            P2M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO3:
            P3M1 |= initStruct->GPIO_Pin;
            P3M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO4:
            P4M1 |= initStruct->GPIO_Pin;
            P4M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO5:
            P5M1 |= initStruct->GPIO_Pin;
            P5M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO6:
            P6M1 |= initStruct->GPIO_Pin;
            P6M0 |= initStruct->GPIO_Pin;
            break;
        case GPIO7:
            P7M1 |= initStruct->GPIO_Pin;
            P7M0 |= initStruct->GPIO_Pin;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

/**
 * @brief 恢复整组GPIO初始值
 *
 * @param GPIOx 需要恢复的GPIO组
 */
void GPIO_DeInit(GPIO_enum GPIOx)
{
    /* 检查参数合法性 */
    al_assert(IS_GPIO_Periph(GPIOx));
    /* 清除参数 */
    switch (GPIOx)
    {
    case GPIO0:
        P0M1 = 0xff;
        P0M0 = 0;
        break;
    case GPIO1:
        P1M1 = 0xff;
        P1M0 = 0;
        break;
    case GPIO2:
        P2M1 = 0xff;
        P2M0 = 0;
        break;
    case GPIO3:
        P3M1 = 0x3c;
        P3M0 = 0;
        break;
    case GPIO4:
        P4M1 = 0xff;
        P4M0 = 0;
        break;
    case GPIO5:
        P5M1 = 0xff;
        P5M0 = 0;
        break;
    case GPIO6:
        P6M1 = 0xff;
        P6M0 = 0;
        break;
    case GPIO7:
        P7M1 = 0xff;
        P7M0 = 0;
        break;
    default:
        break;
    }
}

/**
 * @brief 设置GPIO引脚翻转速度
 *
 * @param GPIOx 所设置的引脚所属GPIO组
 * @param GPIO_Pin 所设置的引脚
 * @param GPIO_Speed 翻转速率
 */
void GPIO_SpeedConfig(GPIO_enum GPIOx, uint8_t GPIO_Pin, GPIO_Speed_enum GPIO_Speed)
{
    /* 检查参数合法性 */
    al_assert(IS_GPIO_Periph(GPIOx));
    al_assert(IS_GPIO_Pin(GPIO_Pin));
    al_assert(IS_GPIO_Speed(GPIO_Speed));
    /* 设置参数 */
    switch (GPIO_Speed)
    {
    case GPIO_Speed_Normal:
        switch (GPIOx)
        {
        case GPIO0:
            P0SR |= GPIO_Pin;
            break;
        case GPIO1:
            P1SR |= GPIO_Pin;
            break;
        case GPIO2:
            P2SR |= GPIO_Pin;
            break;
        case GPIO3:
            P3SR |= GPIO_Pin;
            break;
        case GPIO4:
            P4SR |= GPIO_Pin;
            break;
        case GPIO5:
            P5SR |= GPIO_Pin;
            break;
        case GPIO6:
            P6SR |= GPIO_Pin;
            break;
        case GPIO7:
            P7SR |= GPIO_Pin;
            break;
        default:
            break;
        }
        break;
    case GPIO_Speed_High:
        switch (GPIOx)
        {
        case GPIO0:
            P0SR &= ~GPIO_Pin;
            break;
        case GPIO1:
            P1SR &= ~GPIO_Pin;
            break;
        case GPIO2:
            P2SR &= ~GPIO_Pin;
            break;
        case GPIO3:
            P3SR &= ~GPIO_Pin;
            break;
        case GPIO4:
            P4SR &= ~GPIO_Pin;
            break;
        case GPIO5:
            P5SR &= ~GPIO_Pin;
            break;
        case GPIO6:
            P6SR &= ~GPIO_Pin;
            break;
        case GPIO7:
            P7SR &= ~GPIO_Pin;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

/**
 * @brief 设置GPIO内部集成上拉电阻状态
 *
 * @param GPIOx 所设置的引脚所属GPIO组
 * @param GPIO_Pin 所设置的引脚
 * @param GPIO_PullUpType 上拉电阻模式
 */
void GPIO_PullUpConfig(GPIO_enum GPIOx, uint8_t GPIO_Pin, GPIO_PullUp_enum GPIO_PullUpType)
{
    /* 检查参数合法性 */
    al_assert(IS_GPIO_Periph(GPIOx));
    al_assert(IS_GPIO_Pin(GPIO_Pin));
    al_assert(IS_GPIO_PullUp(GPIO_PullUpType));
    /* 设置参数 */
    switch (GPIO_PullUpType)
    {
    case GPIO_PullUp_4K1:
        switch (GPIOx)
        {
        case GPIO0:
            P0PU |= GPIO_Pin;
            break;
        case GPIO1:
            P1PU |= GPIO_Pin;
            break;
        case GPIO2:
            P2PU |= GPIO_Pin;
            break;
        case GPIO3:
            P3PU |= GPIO_Pin;
            break;
        case GPIO4:
            P4PU |= GPIO_Pin;
            break;
        case GPIO5:
            P5PU |= GPIO_Pin;
            break;
        case GPIO6:
            P6PU |= GPIO_Pin;
            break;
        case GPIO7:
            P7PU |= GPIO_Pin;
            break;
        default:
            break;
        }
        break;
    case GPIO_PullUp_0:
        switch (GPIOx)
        {
        case GPIO0:
            P0PU &= ~GPIO_Pin;
            break;
        case GPIO1:
            P1PU &= ~GPIO_Pin;
            break;
        case GPIO2:
            P2PU &= ~GPIO_Pin;
            break;
        case GPIO3:
            P3PU &= ~GPIO_Pin;
            break;
        case GPIO4:
            P4PU &= ~GPIO_Pin;
            break;
        case GPIO5:
            P5PU &= ~GPIO_Pin;
            break;
        case GPIO6:
            P6PU &= ~GPIO_Pin;
            break;
        case GPIO7:
            P7PU &= ~GPIO_Pin;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

/**
 * @brief 配置GPIO引脚驱动电流
 *
 * @param GPIOx 所设置的引脚所属GPIO组
 * @param GPIO_Pin 所设置的引脚
 * @param GPIO_CurrectType 驱动电流模式
 */
void GPIO_CurrectConfig(GPIO_enum GPIOx, uint8_t GPIO_Pin, GPIO_Currect_enum GPIO_CurrectType)
{
    /* 检查参数合法性 */
    al_assert(IS_GPIO_Periph(GPIOx));
    al_assert(IS_GPIO_Pin(GPIO_Pin));
    al_assert(IS_GPIO_Currect(GPIO_CurrectType));
    /* 设置参数 */
    switch (GPIO_CurrectType)
    {
    case GPIO_Currect_Normal:
        switch (GPIOx)
        {
        case GPIO0:
            P0DR |= GPIO_Pin;
            break;
        case GPIO1:
            P1DR |= GPIO_Pin;
            break;
        case GPIO2:
            P2DR |= GPIO_Pin;
            break;
        case GPIO3:
            P3DR |= GPIO_Pin;
            break;
        case GPIO4:
            P4DR |= GPIO_Pin;
            break;
        case GPIO5:
            P5DR |= GPIO_Pin;
            break;
        case GPIO6:
            P6DR |= GPIO_Pin;
            break;
        case GPIO7:
            P7DR |= GPIO_Pin;
            break;
        default:
            break;
        }
        break;
    case GPIO_Currect_High:
        switch (GPIOx)
        {
        case GPIO0:
            P0DR &= ~GPIO_Pin;
            break;
        case GPIO1:
            P1DR &= ~GPIO_Pin;
            break;
        case GPIO2:
            P2DR &= ~GPIO_Pin;
            break;
        case GPIO3:
            P3DR &= ~GPIO_Pin;
            break;
        case GPIO4:
            P4DR &= ~GPIO_Pin;
            break;
        case GPIO5:
            P5DR &= ~GPIO_Pin;
            break;
        case GPIO6:
            P6DR &= ~GPIO_Pin;
            break;
        case GPIO7:
            P7DR &= ~GPIO_Pin;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

/**
 * @brief 读出整组GPIO电平
 *
 * @param GPIOx 需读出的GPIO组
 * @return uint8_t 电平状态
 */
uint8_t GPIO_ReadData(GPIO_enum GPIOx)
{
    /* 检查参数合法性 */
    al_assert(IS_GPIO_Periph(GPIOx));
    /* 读出并返回数据 */
    switch (GPIOx)
    {
    case GPIO0:
        return ((uint8_t)P0);
        break;
    case GPIO1:
        return ((uint8_t)P1);
        break;
    case GPIO2:
        return ((uint8_t)P2);
        break;
    case GPIO3:
        return ((uint8_t)P3);
        break;
    case GPIO4:
        return ((uint8_t)P4);
        break;
    case GPIO5:
        return ((uint8_t)P5);
        break;
    case GPIO6:
        return ((uint8_t)P6);
        break;
    case GPIO7:
        return ((uint8_t)P7);
        break;
    default:
        return 0;
        break;
    }
}

/**
 * @brief 读出单个引脚GPIO电平
 *
 * @param GPIOx 需读出的引脚所属GPIO组
 * @param GPIO_Pin 需读出的引脚
 * @return BOOL 电平状态
 */
BOOL GPIO_ReadDataBit(GPIO_enum GPIOx, uint8_t GPIO_Pin)
{
    /* 检查参数合法性 */
    al_assert(IS_GPIO_Periph(GPIOx));
    al_assert(IS_GPIO_GetPin(GPIO_Pin));
    /* 读出数据 */
    switch (GPIOx)
    {
    case GPIO0:
        return (((uint8_t)P0) & (GPIO_Pin) ? 1 : 0);
        break;
    case GPIO1:
        return (((uint8_t)P1) & (GPIO_Pin) ? 1 : 0);
        break;
    case GPIO2:
        return (((uint8_t)P2) & (GPIO_Pin) ? 1 : 0);
        break;
    case GPIO3:
        return (((uint8_t)P3) & (GPIO_Pin) ? 1 : 0);
        break;
    case GPIO4:
        return (((uint8_t)P4) & (GPIO_Pin) ? 1 : 0);
        break;
    case GPIO5:
        return (((uint8_t)P5) & (GPIO_Pin) ? 1 : 0);
        break;
    case GPIO6:
        return (((uint8_t)P6) & (GPIO_Pin) ? 1 : 0);
        break;
    case GPIO7:
        return (((uint8_t)P7) & (GPIO_Pin) ? 1 : 0);
        break;
    default:
        return 0;
        break;
    }
}

/**
 * @brief 设置单个引脚GPIO电平为高
 *
 * @param GPIOx 所设置的引脚所属GPIO组
 * @param GPIO_Pin 所设置的引脚
 */
void GPIO_SetBits(GPIO_enum GPIOx, uint8_t GPIO_Pin)
{
    /* 检查参数合法性 */
    al_assert(IS_GPIO_Periph(GPIOx));
    al_assert(IS_GPIO_GetPin(GPIO_Pin));
    /* 写入数据 */
    switch (GPIOx)
    {
    case GPIO0:
        P0 |= GPIO_Pin;
        break;
    case GPIO1:
        P1 |= GPIO_Pin;
        break;
    case GPIO2:
        P2 |= GPIO_Pin;
        break;
    case GPIO3:
        P3 |= GPIO_Pin;
        break;
    case GPIO4:
        P4 |= GPIO_Pin;
        break;
    case GPIO5:
        P5 |= GPIO_Pin;
        break;
    case GPIO6:
        P6 |= GPIO_Pin;
        break;
    case GPIO7:
        P7 |= GPIO_Pin;
        break;
    default:
        break;
    }
}

/**
 * @brief 设置单个引脚GPIO电平为低
 *
 * @param GPIOx 所设置的引脚所属GPIO组
 * @param GPIO_Pin 所设置的引脚
 */
void GPIO_ResetBits(GPIO_enum GPIOx, uint8_t GPIO_Pin)
{
    /* 检查参数合法性 */
    al_assert(IS_GPIO_Periph(GPIOx));
    al_assert(IS_GPIO_GetPin(GPIO_Pin));
    /* 写入数据 */
    switch (GPIOx)
    {
    case GPIO0:
        P0 &= ~GPIO_Pin;
        break;
    case GPIO1:
        P1 &= ~GPIO_Pin;
        break;
    case GPIO2:
        P2 &= ~GPIO_Pin;
        break;
    case GPIO3:
        P3 &= ~GPIO_Pin;
        break;
    case GPIO4:
        P4 &= ~GPIO_Pin;
        break;
    case GPIO5:
        P5 &= ~GPIO_Pin;
        break;
    case GPIO6:
        P6 &= ~GPIO_Pin;
        break;
    case GPIO7:
        P7 &= ~GPIO_Pin;
        break;
    default:
        break;
    }
}

/**
 * @brief 设置单个引脚GPIO电平
 *
 * @param GPIOx 所设置的引脚所属GPIO组
 * @param GPIO_Pin 所设置的引脚
 * @param Val 电平状态
 */
void GPIO_WriteBit(GPIO_enum GPIOx, uint8_t GPIO_Pin, BOOL Val)
{
    /* 检查参数合法性 */
    al_assert(IS_GPIO_Periph(GPIOx));
    al_assert(IS_GPIO_Pin(GPIO_Pin));
    /* 写入数据 */
    if (Val)
    {
        switch (GPIOx)
        {
        case GPIO0:
            P0 |= GPIO_Pin;
            break;
        case GPIO1:
            P1 |= GPIO_Pin;
            break;
        case GPIO2:
            P2 |= GPIO_Pin;
            break;
        case GPIO3:
            P3 |= GPIO_Pin;
            break;
        case GPIO4:
            P4 |= GPIO_Pin;
            break;
        case GPIO5:
            P5 |= GPIO_Pin;
            break;
        case GPIO6:
            P6 |= GPIO_Pin;
            break;
        case GPIO7:
            P7 |= GPIO_Pin;
            break;
        default:
            break;
        }
    }
    else
    {
        switch (GPIOx)
        {
        case GPIO0:
            P0 &= ~GPIO_Pin;
            break;
        case GPIO1:
            P1 &= ~GPIO_Pin;
            break;
        case GPIO2:
            P2 &= ~GPIO_Pin;
            break;
        case GPIO3:
            P3 &= ~GPIO_Pin;
            break;
        case GPIO4:
            P4 &= ~GPIO_Pin;
            break;
        case GPIO5:
            P5 &= ~GPIO_Pin;
            break;
        case GPIO6:
            P6 &= ~GPIO_Pin;
            break;
        case GPIO7:
            P7 &= ~GPIO_Pin;
            break;
        default:
            break;
        }
    }
}

/**
 * @brief 设置整组GPIO电平
 *
 * @param GPIOx 所设置的GPIO组
 * @param Val 电平状态
 */
void GPIO_Write(GPIO_enum GPIOx, uint8_t Val)
{
    /* 检查参数合法性 */
    al_assert(IS_GPIO_Periph(GPIOx));
    /* 写入数据 */
    switch (GPIOx)
    {
    case GPIO0:
        P0 = Val;
        break;
    case GPIO1:
        P1 = Val;
        break;
    case GPIO2:
        P2 = Val;
        break;
    case GPIO3:
        P3 = Val;
        break;
    case GPIO4:
        P4 = Val;
        break;
    case GPIO5:
        P5 = Val;
        break;
    case GPIO6:
        P6 = Val;
        break;
    case GPIO7:
        P7 = Val;
        break;
    default:
        break;
    }
}
