// code = uft-8

#include "al_stc16x_adc.h"

/**
 * @brief 用给定参数初始化ADC通道
 *
 * @param initStruct 初始化结构体
 */
void ADC_Init(ADC_InitTypeDef *initStruct)
{
    /* 检查参数合法性 */
    al_assert(IS_ADC_ChannelEXT(initStruct->ADC_Channel));
    al_assert(IS_ADC_ClockDiv(initStruct->ADC_ClockDiv));
    al_assert(IS_ADC_DataAlign(initStruct->ADC_DataAlign));
    /* 设置参数 */
    ADC_CONTR |= 1 << 7;                    // 打开ADC电源
    ADC_CONTR &= (0xF0);                    // 清除ADC通道
    ADC_CONTR |= (initStruct->ADC_Channel); // 设置ADC通道
    ADCCFG = 0;                             // 清除ADC配置
    ADCCFG |= (initStruct->ADC_ClockDiv);   // 设置ADC时钟
    ADCCFG |= (initStruct->ADC_DataAlign);  // 设置ADC对齐
}

uint16_t ADC_SingleConj(ADC_Channel_enum ADC_Channel)
{
}