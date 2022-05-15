/* code = utf-8 */

#ifndef __al_stc16x_rcc_h
#define __al_stc16x_rcc_h

#include "al_stc16x.h"

#ifdef USE_AltLib

// 时钟设置
#if defined SYSclk_24Mhz
uint32_t SystemCoreClock = 24000000;
#elif defined SYSclk_30Mhz
uint32_t SystemCoreClock = 30000000;
#elif defined SYSclk_35Mhz
uint32_t SystemCoreClock = 35000000;
#endif



#endif
#endif
