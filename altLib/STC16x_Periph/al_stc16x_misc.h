
#ifndef __al_stc16x_misc_h
#define __al_stc16x_misc_h

#include "al_stc16x.h"

#ifdef USE_AltLib

// 延时循环数设置
#if defined SYSclk_24Mhz
#define _al_delayVal1m 24000
#define _al_delayVal50u 1200
#define _al_delayVal2u 48
#elif defined SYSclk_30Mhz
#define _al_delayVal1m 30000
#define _al_delayVal50u 1500
#define _al_delayVal2u 60
#elif defined SYSclk_35Mhz
#define _al_delayVal1m 35000
#define _al_delayVal50u 1750
#define _al_delayVal2u 70
#endif

void al_delay1ms(uint16_t delayTime);
void al_delay2us(uint16_t delayTime);
void al_delay50us(uint16_t delayTime);

void al_softwareReset(void);
void al_downloadReset(void);

#define al_swRST() IAP_CONTR = 0x20 // 软件复位
#define al_dlRST() IAP_CONTR = 0x60 // 下载复位

#endif
#endif
