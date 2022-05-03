/* code = utf-8 */

#include "al_stc16x_sys.h"
#ifdef USE_AltLib

/**
 * @brief 不精确的软件延时1ms
 *
 * @param delayTime 延时时间
 */
void al_delay1ms(uint16_t delayTime)
{
    uint16_t i;
    while (delayTime--)
    {
        i = SystemCoreClock / 1000;
        while (i--)
            ;
    }
}

#endif