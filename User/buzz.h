/*  code=utf-8
    Project Hikari 蜂鸣器驱动
*/
#ifndef buzz_h
#define buzz_h
#include "aa_all_cfg.h"
//蜂鸣器初始化
void buzzInit(void);
//短响
void beepShort(void);
//长响
void beepLong(void);
//警告
void beepAlert(void);
#endif
