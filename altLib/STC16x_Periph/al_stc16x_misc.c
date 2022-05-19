
#include "al_stc16x_misc.h"
#ifdef USE_AltLib

/**
 * @brief 不精确的软件延时1ms
 *
 * @param delayTime 延时时间
 */
void al_delay1ms(uint16_t delayTime)
{
    uint16_t i;
    while (delayTime--)
    {
        i = _al_delayVal1m; // 设置循环数
        while (i--)
            ;
    }
}

/**
 * @brief 不精确的软件延时50us
 *
 * @param delayTime 延时时间
 */
void al_delay50us(uint16_t delayTime)
{
    uint16_t i;
    while (delayTime--)
    {
        i = _al_delayVal50u; // 设置循环数
        while (i--)
            ;
    }
}

/**
 * @brief 极不精确的软件延时2us
 *
 * @param delayTime 延时时间
 */
void al_delay2us(uint16_t delayTime)
{
    uint16_t i;
    while (delayTime--)
    {
        i = _al_delayVal2u; // 设置循环数
        while (i--)
            ;
    }
}

/**
 * @brief 软件复位
 *
 */
void al_softwareReset(void)
{
    IAP_CONTR = 0x20;
}

/**
 * @brief ISP下载复位
 *
 */
void al_downloadReset(void)
{
    IAP_CONTR = 0x60;
}

#endif