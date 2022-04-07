// code = utf-8

#ifndef __al_stc16x_adc_h
#define __al_stc16x_adc_h

#include "al_stc16x.h"

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
#define IS_ADC_Channel(CH) (((CH) == ADC_P10) || ((CH) == ADC_P11) || ((CH) == ADC_P13) || \
                            ((CH) == ADC_P14) || ((CH) == ADC_P15) || ((CH) == ADC_P16) || \
                            ((CH) == ADC_P17) || ((CH) == ADC_P00) || ((CH) == ADC_P01) || \
                            ((CH) == ADC_P02) || ((CH) == ADC_P03) || ((CH) == ADC_P04) || \
                            ((CH) == ADC_P05) || ((CH) == ADC_P06) || ((CH) == ADC_POW))

#define IS_ADC_ChannelEXT(CH) (((CH) == ADC_P10) || ((CH) == ADC_P11) || \
                               ((CH) == ADC_P13) || ((CH) == ADC_P14) || \
                               ((CH) == ADC_P15) || ((CH) == ADC_P16) || \
                               ((CH) == ADC_P17) || ((CH) == ADC_P00) || \
                               ((CH) == ADC_P01) || ((CH) == ADC_P02) || \
                               ((CH) == ADC_P03) || ((CH) == ADC_P04) || \
                               ((CH) == ADC_P05) || ((CH) == ADC_P06))
/**
 * @brief ADC时钟分频枚举
 *
 */
typedef enum
{
    ADC_ClockDiv_2 = ((uint8_t)0),
    ADC_ClockDiv_4 = ((uint8_t)1),
    ADC_ClockDiv_6 = ((uint8_t)2),
    ADC_ClockDiv_8 = ((uint8_t)3),
    ADC_ClockDiv_10 = ((uint8_t)4),
    ADC_ClockDiv_12 = ((uint8_t)5),
    ADC_ClockDiv_14 = ((uint8_t)6),
    ADC_ClockDiv_16 = ((uint8_t)7),
    ADC_ClockDiv_18 = ((uint8_t)8),
    ADC_ClockDiv_20 = ((uint8_t)9),
    ADC_ClockDiv_22 = ((uint8_t)10),
    ADC_ClockDiv_24 = ((uint8_t)11),
    ADC_ClockDiv_26 = ((uint8_t)12),
    ADC_ClockDiv_28 = ((uint8_t)13),
    ADC_ClockDiv_30 = ((uint8_t)14),
    ADC_ClockDiv_32 = ((uint8_t)15)
} ADC_ClockDiv_enum;
#define IS_ADC_ClockDiv(Div) (((Div) == ADC_ClockDiv_2) || ((Div) == ADC_ClockDiv_4) ||   \
                              ((Div) == ADC_ClockDiv_6) || ((Div) == ADC_ClockDiv_8) ||   \
                              ((Div) == ADC_ClockDiv_10) || ((Div) == ADC_ClockDiv_12) || \
                              ((Div) == ADC_ClockDiv_14) || ((Div) == ADC_ClockDiv_16) || \
                              ((Div) == ADC_ClockDiv_18) || ((Div) == ADC_ClockDiv_20) || \
                              ((Div) == ADC_ClockDiv_22) || ((Div) == ADC_ClockDiv_24) || \
                              ((Div) == ADC_ClockDiv_26) || ((Div) == ADC_ClockDiv_28) || \
                              ((Div) == ADC_ClockDiv_30) || ((Div) == ADC_ClockDiv_32))
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
    ADC_ClockDiv_enum ADC_ClockDiv;
    ADC_DataAlign_enum ADC_DataAlign;
} ADC_InitTypeDef;

void ADC_Init1(ADC_InitTypeDef *initStruct);

uint16_t ADC_SingleConv(ADC_Channel_enum ADC_Channel);


#endif