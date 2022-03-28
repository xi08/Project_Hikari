/*  code=utf-8
    Project Hikari 按键与拨码开关
*/
#ifndef key_h
#define key_h
#include "aa_all_cfg.h"

// 按键状态枚举
typedef enum
{
    S0, // 抬起
    S1, // 短按
    S2, // 按下
    S3, // 长按
    S4, // 满足长按所需周期但未抬起
} keyState_enum;
// 状态枚举
extern volatile keyState_enum keyState[keyNum];
#ifdef KEY_EXT_Matrix
// 按键状态初始化
void keyInit(void);
#endif
// 按键状态更新
void updateKey(void);
// 按键处理程序
void keyProg(void);
// 拨码开关处理程序
void swProg(void);
#endif
