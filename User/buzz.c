/*  code=utf-8
    Project Hikari 蜂鸣器驱动
*/
#include "buzz.h"
// 蜂鸣器初始化
void buzzInit(void)
{
#ifdef BUZZ_EXT_PWM
    pwm_init(BUZZ_PWM, 50, 0);
#else
    gpio_mode(Buzz, GPO_PP);
    BUZZ = 0;
#endif
}

// 短响
void beepShort(void)
{
    BUZZ = 1;
    delay_ms(50);
    BUZZ = 0;
}
// 长响
void beepLong(void)
{
    BUZZ = 1;
    delay_ms(150);
    BUZZ = 0;
}
// 警告
void beepAlert(void)
{
    BUZZ = 1;
}
