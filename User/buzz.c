/*  code=utf-8
    Project Hikari 蜂鸣器驱动
*/
#include "buzz.h"
// 蜂鸣器初始化
void buzzInit(void)
{
    gpio_mode(P7_7,GPO_PP);
    BUZ=0;
}

// 短响
void beepShort(void)
{
    BUZ=1;
    delay_ms(50);
    BUZ=0;
}
// 长响
void beepLong(void)
{
    BUZ=1;
    delay_ms(150);
    BUZ=0;
}
// 警告
void beepAlert(void)
{
    BUZ=1;
}
