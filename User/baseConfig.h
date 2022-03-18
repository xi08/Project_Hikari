/*  code=utf-8
    Project Hikari 基础配置
*/
#ifndef baseConfig_h
#define baseConfig_h

//引入C库
#include "headfile.h"
#include "stddef.h"

//绝对值
#define abs(x) (x > 0 ? x : (-x))
//判断符号
#define sig(x) (x ? 1 : (-1))
//判断负数
#define neg(x) (x > 0 ? 0 : 1)

//系统警报
typedef enum
{
    S_A0, //正常工作
    S_A1, //电压不足
    S_A2, //电压过高
} alertState_enum;

#endif
