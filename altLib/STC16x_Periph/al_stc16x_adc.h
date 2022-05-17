
#ifndef __al_stc16x_adc_h
#define __al_stc16x_adc_h

#include "al_stc16x.h"
#ifdef USE_AltLib

/**
 * @brief ADC引脚/通道枚举
 *
 */
typedef enum
{
    ADC_P10 = 0,
    ADC_P11,
    ADC_P13 = 3,
    ADC_P14,
    ADC_P15,
    ADC_P16,
    ADC_P17,

    ADC_P00,
    ADC_P01,
    ADC_P02,
    ADC_P03,
    ADC_P04,
    ADC_P05,
    ADC_P06,

    ADC_POW = 0x0f,
} ADC_Channel_enum;
#define IS_ADC_Channel(CH)                                                                                             \
    (((CH) == ADC_P10) || ((CH) == ADC_P11) || ((CH) == ADC_P13) || ((CH) == ADC_P14) || ((CH) == ADC_P15) ||          \
     ((CH) == ADC_P16) || ((CH) == ADC_P17) || ((CH) == ADC_P00) || ((CH) == ADC_P01) || ((CH) == ADC_P02) ||          \
     ((CH) == ADC_P03) || ((CH) == ADC_P04) || ((CH) == ADC_P05) || ((CH) == ADC_P06) || ((CH) == ADC_POW))

#define IS_ADC_ChannelEXT(CH)                                                                                          \
    (((CH) == ADC_P10) || ((CH) == ADC_P11) || ((CH) == ADC_P13) || ((CH) == ADC_P14) || ((CH) == ADC_P15) ||          \
     ((CH) == ADC_P16) || ((CH) == ADC_P17) || ((CH) == ADC_P00) || ((CH) == ADC_P01) || ((CH) == ADC_P02) ||          \
     ((CH) == ADC_P03) || ((CH) == ADC_P04) || ((CH) == ADC_P05) || ((CH) == ADC_P06))

/**
 * @brief ADC时钟分频
 *
 */
#define IS_ADC_ClockDiv(Div) ((Div) < 16)

/**
 * @brief ADC对齐方向枚举
 *
 */
typedef enum
{
    ADC_DataAlign_Left,
    ADC_DataAlign_Right = 1 << 5,
} ADC_DataAlign_enum;
#define IS_ADC_DataAlign(DA) (((DA) == ADC_DataAlign_Left) || ((DA) == ADC_DataAlign_Right))

/**
 * @brief ADC初始化结构体
 *
 */
typedef struct
{
    ADC_Channel_enum ADC_Channel;
    uint8_t ADC_ClockDiv;
    ADC_DataAlign_enum ADC_DataAlign;
} ADC_InitTypeDef;

void ADC_Init1(ADC_InitTypeDef *initStruct);

uint16_t ADC_SingleConv(ADC_Channel_enum ADC_Channel);

#endif
#endif
