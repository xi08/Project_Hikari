// code = utf-8
#include "al_stc16x_i2c.h"
#ifdef USE_AltLib

/**
 * @brief
 *
 * @param I2Cx
 * @param initStruct
 */
void I2C_Init(I2C_enum I2Cx, I2C_InitTypeDef *initStruct)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_DeInit(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param initStruct
 */
void I2C_StructInit(I2C_InitTypeDef *initStruct)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param newStatus
 */
void I2C_Cmd(I2C_enum I2Cx, statusType newStatus)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param newPort
 */
void I2C_PortConfig(I2C_enum I2Cx, I2C_Port_enum newPort)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param newMode
 */
void I2C_ModeConfig(I2C_enum I2Cx, I2C_Mode_enum newMode)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param newCommSpeed
 */
void I2C_ClockConfig(I2C_enum I2Cx, uint8_t newCommSpeed)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param newOwnAddr
 */
void I2C_OwnAddrConfig(I2C_enum I2Cx, uint8_t newOwnAddr)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param deviceAddr
 * @param srcRegAddr
 * @param dest
 */
void I2C_RecvByte(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t srcRegAddr, uint8_t *dest)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param deviceAddr
 * @param destRegAddr
 * @param src
 */
void I2C_SendByte(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t destRegAddr, uint8_t src)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param deviceAddr
 * @param srcRegAddr
 * @param dest
 * @param n
 */
void I2C_RecvPage(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t srcRegAddr, uint8_t *dest, uint8_t n)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param deviceAddr
 * @param destRegAddr
 * @param src
 * @param n
 */
void I2C_SendPage(I2C_enum I2Cx, uint8_t deviceAddr, uint8_t destRegAddr, uint8_t *src, uint8_t n)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_CMD_SendSTART(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_CMD_SendSTOP(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_CMD_SendACK(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_CMD_SendNACK(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_CMD_WaitACK(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_CMD_SendData(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_CMD_RecvData(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_SCMD_FirstSend(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_SCMD_SerialSend(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_SCMD_SerialRecv(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param I2Cx
 */
void I2C_SCMD_EndRecv(I2C_enum I2Cx)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param I2C_IT
 * @param newStatus
 */
void I2C_ITConfig(I2C_enum I2Cx, uint16_t I2C_IT, statusType newStatus)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param I2C_IT
 * @return flagType
 */
flagType I2C_GetITStatus(I2C_enum I2Cx, uint16_t I2C_IT)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param I2C_IT
 */
void I2C_ClearITPendingBit(I2C_enum I2Cx, uint16_t I2C_IT)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param I2C_FLAG
 * @param newStatus
 */
void I2C_FlagConfig(I2C_enum I2Cx, uint16_t I2C_FLAG, statusType newStatus)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param I2C_FLAG
 * @return flagType
 */
flagType I2C_GetFlagStatus(I2C_enum I2Cx, uint16_t I2C_FLAG)
{
}

/**
 * @brief
 *
 * @param I2Cx
 * @param I2C_FLAG
 */
void I2C_ClearFlag(I2C_enum I2Cx, uint16_t I2C_FLAG)
{
}

#endif
