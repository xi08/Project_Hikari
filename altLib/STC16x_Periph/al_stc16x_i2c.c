
#include "al_stc16x_i2c.h"
#include "al_stc16x_misc.h"
#ifdef USE_AltLib

#define I2C_Delay(x) al_delay2us(x)

/**
 * @brief 用给定参数初始化I2C功能
 *
 * @param I2Cx 目标I2C单元
 * @param initStruct 初始化结构体
 */
void I2C_Init(I2C_enum I2Cx, I2C_InitTypeDef *initStruct)
{
    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));
    al_assert(IS_I2C_Port(initStruct->I2C_Port));
    al_assert(IS_I2C_Mode(initStruct->I2C_Mode));
    al_assert(IS_I2C_ClockDiv(initStruct->I2C_ClockDiv));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        if (initStruct->I2C_Mode) // 主从机设置
            I2CCFG |= (1 << 6);   // 主机模式
        else
            I2CCFG &= ~(1 << 6); // 从机模式

        I2CCFG |= (initStruct->I2C_ClockDiv);          // 分频设置
        P_SW2 |= (initStruct->I2C_Port << 4);          // 引脚设置
        I2CSLADR |= (initStruct->I2C_OwnAddress << 1); // 从机地址设置
        break;
    }

    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
}

/**
 * @brief I2C使能状态配置
 *
 * @param I2Cx 目标I2C单元
 * @param newStatus 功能状态: 开启/关闭
 */
void I2C_Cmd(I2C_enum I2Cx, statusType newStatus)
{
    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        if (newStatus)
            I2CCFG |= (1 << 6); // 开
        else
            I2CCFG &= ~(1 << 6); // 关
        break;
    }

    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
}

/**
 * @brief I2C接口配置
 *
 * @param I2Cx 目标I2C单元
 * @param newPort 新I2C接口对
 */
void I2C_PortConfig(I2C_enum I2Cx, I2C_Port_enum newPort)
{
    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));
    al_assert(IS_I2C_Port(newPort));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        P_SW2 &= ~(0x03 << 4);   // 清除原有接口
        P_SW2 |= (newPort << 4); // 设置新接口
        break;
    }

    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
}

/**
 * @brief I2C工作模式配置
 *
 * @param I2Cx 目标I2C单元
 * @param newMode 新工作模式
 */
void I2C_ModeConfig(I2C_enum I2Cx, I2C_Mode_enum newMode)
{
    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));
    al_assert(IS_I2C_Mode(newMode));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        if (newMode)            // 主从机设置
            I2CCFG |= (1 << 6); // 主机模式
        else
            I2CCFG &= ~(1 << 6); // 从机模式
        break;
    }

    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
}

/**
 * @brief I2C时钟配置
 *
 * @param I2Cx 目标I2C单元
 * @param newClockDiv 新时钟分频系数
 */
void I2C_ClockConfig(I2C_enum I2Cx, uint8_t newClockDiv)
{
    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));
    al_assert(IS_I2C_ClockDiv(newClockDiv));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        I2CCFG |= newClockDiv; // 分频设置
        break;
    }

    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
}

/**
 * @brief I2C从机地址配置
 *
 * @param I2Cx 目标I2C单元
 * @param newOwnAddr 新从机地址
 */
void I2C_OwnAddrConfig(I2C_enum I2Cx, uint8_t newOwnAddr)
{
    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        I2CSLADR |= (newOwnAddr << 1); // 从机地址设置
        break;
    }

    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
}

/**
 * @brief 发送开始信号
 *
 * @param I2Cx
 */
void I2C_SendSTART(I2C_enum I2Cx)
{
    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        I2CMSCR &= ~0x0f; // 清除I2C主机模式指令
        I2CMSCR |= 0x01;  // 设置I2C主机模式指令
        while (!(I2CMSST & (1 << 6)))
            ;
        I2CMSST &= ~(1 << 6);
        break;
    }
    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
}

/**
 * @brief 发送结束信号
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_SendSTOP(I2C_enum I2Cx)
{
    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        I2CMSCR &= ~0x0f; // 清除I2C主机模式指令
        I2CMSCR |= 0x06;  // 设置I2C主机模式指令
        while (!(I2CMSST & (1 << 6)))
            ;
        I2CMSST &= ~(1 << 6);
        break;
    }
    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
}

/**
 * @brief 发送应答信号
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_SendACK(I2C_enum I2Cx)
{
    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        I2CMSST |= 0x01;  // 设置MSACKO位
        I2CMSCR &= ~0x0f; // 清除I2C主机模式指令
        I2CMSCR |= 0x05;  // 设置I2C主机模式指令
        while (!(I2CMSST & (1 << 6)))
            ;
        I2CMSST &= ~(1 << 6);
        break;
    }
    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
}

/**
 * @brief 发送非应答信号
 *
 * @param I2Cx  目标I2C单元
 */
void I2C_SendNACK(I2C_enum I2Cx)
{
    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        I2CMSCR &= ~0x01; // 设置MSACKO位
        I2CMSCR &= ~0x0f; // 清除I2C主机模式指令
        I2CMSCR |= 0x05;  // 设置I2C主机模式指令
        while (!(I2CMSST & (1 << 6)))
            ;
        I2CMSST &= ~(1 << 6);
        break;
    }
    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
}

/**
 * @brief 等待应答信号
 *
 * @param I2Cx 目标I2C单元
 * @return uint8_t 应答位高低电平
 */
uint8_t I2C_WaitACK(I2C_enum I2Cx)
{
    uint8_t tmp;

    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        I2CMSCR &= ~0x0f;           // 清除I2C主机模式指令
        I2CMSCR |= 0x02;            // 设置I2C主机模式指令
        al_delay2us(5);             // 延时
        tmp = (I2CMSST & (1 << 1)); // 获取应答位高低电平
        break;
    }
    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
    return tmp;
}

/**
 * @brief 发送单字节
 *
 * @param I2Cx 目标I2C单元
 * @param dat 需要发送的数据
 */
void I2C_Send(I2C_enum I2Cx, uint8_t dat)
{
    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        I2CTXD = dat;
        I2CMSCR &= ~0x0f; // 清除I2C主机模式指令
        I2CMSCR |= 0x02;  // 设置I2C主机模式指令
        al_delay2us(5);   // 延时
        break;
    }
    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问
}

/**
 * @brief 接收单字节
 *
 * @param I2Cx 目标I2C单元
 * @return uint8_t 接收到的数据
 */
uint8_t I2C_Receive(I2C_enum I2Cx)
{
    uint8_t tmp;

    /* 检查参数合法性 */
    al_assert(IS_I2C_Periph(I2Cx));

    /* 设置参数 */
    EnableXFR(); // 开启XFR访问
    switch (I2Cx)
    {
    case I2C1: // I2C1
    {
        I2CMSCR &= ~0x0f; // 清除I2C主机模式指令
        I2CMSCR |= 0x04;  // 设置I2C主机模式指令
        al_delay2us(5);   // 延时
        tmp = I2CRXD;
        break;
    }
    default:
        break;
    }
    DisableXFR(); // 关闭XFR访问

    return tmp;
}

/**
 * @brief I2C主机单字节接收
 *
 * @param I2Cx 目标I2C单元
 * @param deviceAddr 目标外设I2C地址
 * @param srcRegAddr 目标外设内部地址
 * @param dest 接受数据地址
 */
void I2C_RecvByte(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t srcRegAddr, uint8_t *dest)
{
}

/**
 * @brief I2C主机单字节发送
 *
 * @param I2Cx 目标I2C单元
 * @param deviceAddr 目标外设I2C地址
 * @param destRegAddr 目标外设内部地址
 * @param src 发送数据
 */
void I2C_SendByte(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t destRegAddr, uint8_t src)
{
}

/**
 * @brief I2C主机多字节接收
 *
 * @param I2Cx 目标I2C单元
 * @param deviceAddr 目标外设I2C地址
 * @param srcRegAddr 目标外设内部地址
 * @param dest 接受数据首地址
 * @param n 通信字节数
 */
void I2C_RecvPage(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t srcRegAddr, uint8_t *dest, uint8_t n)
{
}

/**
 * @brief I2C主机多字节发送
 *
 * @param I2Cx 目标I2C单元
 * @param deviceAddr 目标外设I2C地址
 * @param destRegAddr 目标外设内部地址
 * @param src 发送数据首地址
 * @param n 通信字节数
 */
void I2C_SendPage(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t destRegAddr, uint8_t *src, uint8_t n)
{
}

/**
 * @brief I2C中断功能配置
 *
 * @param I2Cx 目标I2C单元
 * @param I2C_IT 中断的触发来源
 * @param newStatus 功能状态: 开启/关闭
 */
void I2C_ITConfig(I2C_enum I2Cx, uint16_t I2C_IT, statusType newStatus)
{
}

/**
 * @brief 获取I2C中断标记
 *
 * @param I2Cx 目标I2C单元
 * @param I2C_IT 中断的触发来源
 * @return flagType 中断标记的置位信息
 */
flagType I2C_GetITStatus(I2C_enum I2Cx, uint16_t I2C_IT)
{
}

/**
 * @brief 清除定时器中断标记
 *
 * @param I2Cx 目标I2C单元
 * @param I2C_IT 中断的触发来源
 */
void I2C_ClearITPendingBit(I2C_enum I2Cx, uint16_t I2C_IT)
{
}

/**
 * @brief I2C状态位配置
 *
 * @param I2Cx 目标I2C单元
 * @param I2C_FLAG 状态置位触发来源
 * @param newStatus 功能状态: 开启/关闭
 */
void I2C_FlagConfig(I2C_enum I2Cx, uint16_t I2C_FLAG, statusType newStatus)
{
}

/**
 * @brief 获取I2C状态位
 *
 * @param I2Cx 目标I2C单元
 * @param I2C_FLAG 状态置位触发来源
 * @return flagType 状态置位信息
 */
flagType I2C_GetFlagStatus(I2C_enum I2Cx, uint16_t I2C_FLAG)
{
}

/**
 * @brief 清除I2C状态位
 *
 * @param I2Cx 目标I2C单元
 * @param I2C_FLAG 状态置位触发来源
 */
void I2C_ClearFlag(I2C_enum I2Cx, uint16_t I2C_FLAG)
{
}

#endif
