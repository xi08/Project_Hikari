// code = utf-8
#include "al_stc16x_i2c.h"
#ifdef USE_AltLib

/**
 * @brief 用给定参数初始化I2C功能
 *
 * @param I2Cx 目标I2C单元
 * @param initStruct 初始化结构体
 */
void I2C_Init(I2C_enum I2Cx, I2C_InitTypeDef *initStruct)
{
}

/**
 * @brief 反初始化I2C功能
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_DeInit(I2C_enum I2Cx)
{
}

/**
 * @brief I2C使能状态配置
 *
 * @param I2Cx 目标I2C单元
 * @param newStatus 功能状态: 开启/关闭
 */
void I2C_Cmd(I2C_enum I2Cx, statusType newStatus)
{
}

/**
 * @brief I2C接口配置
 *
 * @param I2Cx 目标I2C单元
 * @param newPort 新I2C接口对
 */
void I2C_PortConfig(I2C_enum I2Cx, I2C_Port_enum newPort)
{
}

/**
 * @brief I2C工作模式配置
 *
 * @param I2Cx 目标I2C单元
 * @param newMode 新工作模式
 */
void I2C_ModeConfig(I2C_enum I2Cx, I2C_Mode_enum newMode)
{
}

/**
 * @brief I2C时钟配置
 *
 * @param I2Cx 目标I2C单元
 * @param newClockDiv 新时钟分频系数
 */
void I2C_ClockConfig(I2C_enum I2Cx, uint8_t newClockDiv)
{
}

/**
 * @brief I2C从机地址配置
 *
 * @param I2Cx 目标I2C单元
 * @param newOwnAddr 新从机地址
 */
void I2C_OwnAddrConfig(I2C_enum I2Cx, uint8_t newOwnAddr)
{
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
 * @brief I2C主机指令-发送START信号
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_CMD_SendSTART(I2C_enum I2Cx)
{
}

/**
 * @brief I2C主机指令-发送STOP信号
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_CMD_SendSTOP(I2C_enum I2Cx)
{
}

/**
 * @brief I2C主机指令-发送ACK信号
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_CMD_SendACK(I2C_enum I2Cx)
{
}

/**
 * @brief I2C主机指令-发送NACK信号
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_CMD_SendNACK(I2C_enum I2Cx)
{
}

/**
 * @brief I2C主机指令-接收ACK信号
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_CMD_RecvACK(I2C_enum I2Cx)
{
}

/**
 * @brief I2C主机指令-发送数据
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_CMD_SendData(I2C_enum I2Cx)
{
}

/**
 * @brief I2C主机指令-接受数据
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_CMD_RecvData(I2C_enum I2Cx)
{
}

/**
 * @brief I2C主机指令序列-首次发送
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_SCMD_FirstSend(I2C_enum I2Cx)
{
}

/**
 * @brief I2C主机指令序列-首次发送后的连续发送
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_SCMD_SerialSend(I2C_enum I2Cx)
{
}

/**
 * @brief I2C主机指令序列-连续接收
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_SCMD_SerialRecv(I2C_enum I2Cx)
{
}

/**
 * @brief I2C主机指令序列-末次接收
 *
 * @param I2Cx 目标I2C单元
 */
void I2C_SCMD_EndRecv(I2C_enum I2Cx)
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
