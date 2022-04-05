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
    /* 设置参数 */
    ADC_CONTR |= 1 << 7;                         // 打开ADC电源
    ADC_CONTR &= (0xF0);                         // 清除ADC通道
    ADC_CONTR |= (initStruct->ADC_Channel);      // 设置ADC通道
    ADCCFG |= (initStruct->ADC_ClockDiv) & 0x0f; // 设置ADC时钟
    switch (initStruct->ADC_DataAlign)           // 设置ADC对齐
    {
    case ADC_DataAlign_Left: // 设置左对齐
        ADCCFG &= ~(1 << 5);
        break;
    case ADC_DataAlign_Right: // 设置右对齐
        ADCCFG |= (1 << 5);
        break;
    default:
        break;
    }
}
/**
 * @brief ADC单次转换
 *
 * @param ADC_Channel 需要转换的ADC通道
 * @return uint16_t 转换结果 (RES在前，RESL在后)
 */
uint16_t ADC_SingleConj(ADC_Channel_enum ADC_Channel)
{
    ADC_CONTR &= (0xF0);            // 清除ADC通道
    ADC_CONTR |= ADC_Channel;       // 设置ADC通道
    ADC_CONTR |= (1 << 6);          // 启动转换
    while (!(ADC_CONTR & (1 << 5))) // 查询 ADC 完成标志
        ;
    ADC_CONTR &= ~0x20;             // 清除完成标志
    return ADC_RES << 8 + ADC_RESL; // 返回转换结果
}