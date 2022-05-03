/* code = utf-8 */

#ifndef __al_stc16x_sys_h
#define __al_stc16x_sys_h

#include "al_stc16x.h"

#ifdef USE_AltLib

#define SysFreq_20Mhz 20000000
#define SysFreq_24Mhz 24000000
#define SysFreq_27Mhz 27000000
#define SysFreq_30Mhz 30000000

#if defined SysClk_Freq_20Mhz
uint32_t SystemCoreClock = SysFreq_20Mhz;
#elif defined SysClk_Freq_24Mhz
uint32_t SystemCoreClock = SysFreq_24Mhz;
#elif defined SysClk_Freq_27Mhz
uint32_t SystemCoreClock = SysFreq_27Mhz;
#elif defined SysClk_Freq_30Mhz
uint32_t SystemCoreClock = SysFreq_30Mhz;
#endif

void al_delay1ms(uint16_t delayTime);

#endif
#endif
