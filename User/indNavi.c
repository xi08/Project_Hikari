/*  code=utf-8
    Project Hikari 前瞻电感
*/
#include "indNavi.h"
#include "string.h"
// 电感原始数据
volatile uint16 indRawData[indNum], indRawDataMax[indNum], indRawDataMin[indNum];
// 电感滤波后数据
volatile uint16 indFilteredData[indNum];
// 归一化上下限值
volatile uint16 indMaxData[indNum], indMinData[indNum];



// 电感初始化
void indInit(void)
{
    // 初始化adc
    adc_init(IND_LL, ADC_SYSclk_DIV_2);
    adc_init(IND_MF, ADC_SYSclk_DIV_2);
    adc_init(IND_RR, ADC_SYSclk_DIV_2);
#ifdef IND_EXT_MidSide
    adc_init(IND_LM, ADC_SYSclk_DIV_2);
    adc_init(IND_RM, ADC_SYSclk_DIV_2);
#endif
#ifdef IND_EXT_MidRear
    adc_init(IND_MR, ADC_SYSclk_DIV_2);
#endif
    // 设置归一化初始下限的值
    memset(indMinData, 0xff, indNum * sizeof(uint16));
}
// 获取已滤波，已归一化的电感数据，以 LL-MF-RR-LM-RM-MR 序列给出
void getIndInfo(uint8 *indDataArray)
{
    uint8 i, j;
    // 设置比较量的值
    memset(indRawDataMin, 0xff, indNum * sizeof(uint16));
    // 滤波前获取数据
    for (i = 0; i < (1<<indFilterT+2); i++)
    {
        // 获取电感值
        indRawData[0] = adc_once(IND_MF, ADC_10BIT);
        indRawData[1] = adc_once(IND_LL, ADC_10BIT);
        indRawData[2] = adc_once(IND_RR, ADC_10BIT);
#ifdef IND_EXT_MidSide
        indRawData[3] = adc_once(IND_LM, ADC_10BIT);
        indRawData[4] = adc_once(IND_RM, ADC_10BIT);
#endif
#ifdef IND_EXT_MidRear
        indRawData[5] = adc_once(IND_MR, ADC_10BIT);
#endif
        for (j = 0; j < indNum; j++)
        {
            // 判断最大最小值
            if (indRawData[j] > indRawDataMax[j])
                indRawDataMax[j] = indRawData[j];
            if (indRawData[j] < indRawDataMin[j])
                indRawDataMin[j] = indRawData[j];
            // 进行累加
            indFilteredData[j] += indRawData[j];
        }
    }
    // 去除2个极值以后进行均值滤波
    for (i = 0; i < indNum; i++)
    {
        indFilteredData[i] -= (indRawDataMax[i] + indRawDataMin[i]);
        indFilteredData[i] >>= indFilterT;
    }
    // 归一化，自动刷新上下限
    for (i = 0; i < indNum; i++)
    {
        if (indFilteredData[i] >= indMaxData[i])
        {
            indDataArray[i] = 99;
            indMaxData[i] = indFilteredData[i];
        }
        else if (indFilteredData[i] <= indMinData[i])
        {
            indDataArray[i] = 0;
            indMinData[i] = indFilteredData[i];
        }
        else
        {
            indDataArray[i] = (uint8)((indFilteredData[i] - indMinData[i]) * 99 / (indMaxData[i] - indMinData[i]));
        }
    }
}
