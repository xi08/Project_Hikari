

#ifndef __STC16F40K_ADC_H
#define __STC16F40K_ADC_H

#include "stc16f40k.h"

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
    ADC_POWER = 0x0f,
} ADC_Channel_enum;
#define IS_ADC_Channel(CH) (((CH) == ADC_P10) || ((CH) == ADC_P11) || \
                            ((CH) == ADC_P13) || ((CH) == ADC_P14) || \
                            ((CH) == ADC_P15) || ((CH) == ADC_P16) || \
                            ((CH) == ADC_P00) || ((CH) == ADC_P01) || \
                            ((CH) == ADC_P02) || ((CH) == ADC_P03) || \
                            ((CH) == ADC_P04) || ((CH) == ADC_P05) || \
                            ((CH) == ADC_P06) || ((CH) == ADC_POWER))

#define ADC_ClockDiv_2 ((uint8_t)0)
#define ADC_ClockDiv_4 ((uint8_t)1)
#define ADC_ClockDiv_6 ((uint8_t)2)
#define ADC_ClockDiv_8 ((uint8_t)3)
#define ADC_ClockDiv_10 ((uint8_t)4)
#define ADC_ClockDiv_12 ((uint8_t)5)
#define ADC_ClockDiv_14 ((uint8_t)6)
#define ADC_ClockDiv_16 ((uint8_t)7)
#define ADC_ClockDiv_18 ((uint8_t)8)
#define ADC_ClockDiv_20 ((uint8_t)9)
#define ADC_ClockDiv_22 ((uint8_t)10)
#define ADC_ClockDiv_24 ((uint8_t)11)
#define ADC_ClockDiv_26 ((uint8_t)12)
#define ADC_ClockDiv_28 ((uint8_t)13)
#define ADC_ClockDiv_30 ((uint8_t)14)
#define ADC_ClockDiv_32 ((uint8_t)15)

#define IS_ADC_ClockDiv(Div) (((Div) == ADC_ClockDiv_2) || ((Div) == ADC_ClockDiv_4) ||   \
                              ((Div) == ADC_ClockDiv_6) || ((Div) == ADC_ClockDiv_8) ||   \
                              ((Div) == ADC_ClockDiv_10) || ((Div) == ADC_ClockDiv_12) || \
                              ((Div) == ADC_ClockDiv_14) || ((Div) == ADC_ClockDiv_16) || \
                              ((Div) == ADC_ClockDiv_18) || ((Div) == ADC_ClockDiv_20) || \
                              ((Div) == ADC_ClockDiv_22) || ((Div) == ADC_ClockDiv_24) || \
                              ((Div) == ADC_ClockDiv_26) || ((Div) == ADC_ClockDiv_28) || \
                              ((Div) == ADC_ClockDiv_30) || ((Div) == ADC_ClockDiv_32))

#define ADC_DataAlign_Left (BOOL)0
#define ADC_DataAlign_Right (BOOL)1

typedef struct
{
    ADC_Channel_enum ADC_Channel;
    uint8_t ADC_ClockDiv;
    BOOL ADC_DataAlign;
} ADC_InitTypedef;

void ADC_Init(ADC_InitTypedef *ADC_InitStruct);

uint16_t ADC_SingleConj(ADC_Channel_enum ADC_Channel);

#endif