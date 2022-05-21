#ifndef __al_debugAux_h
#define __al_debugAux_h

#include "al_stc16x.h"

#ifdef USE_AltLib

BOOL al_debug_strcmp(char *str1, char *str2);
uint32_t al_debug_quickPow(uint8_t base, uint8_t idx);
uint32_t al_debug_atoi(char *str);

#endif

#endif