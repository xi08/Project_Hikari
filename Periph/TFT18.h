/*  code=utf-8
    Project Hikari 显示屏驱动
    ST7735驱动芯片，16位彩色
*/

#ifndef TFT18_h
#define TFT18_h
#include "aa_all_cfg.h"

#define USE_TFT18

extern volatile uint16 tftColorF, tftColorB;

#define tftMaxX 128 //液晶X方宽度
#define tftMaxY 160 //液晶Y方宽度

// 初始化显示屏
void tftInit(void);
// 清空显示屏
void tftClear(void);
// 修改前景色
#define tftSetColorF(Color) (tftColorF = (uint16)Color)
// 修改背景色
#define tftSetColorB(Color) (tftColorB = (uint16)Color)
// 显示字符
void tftDispChar(uint16 x, uint16 y, const int8 ch);
// 显示字符串
void tftDispStr(uint16 x, uint16 y, const int8 *str);
// 显示有符号数字
void tftDispInt(uint16 x, uint16 y, int32 num, uint8 digit_i);
// 显示无符号数字
void tftDispUint(uint16 x, uint16 y, uint32 num, uint8 digit_i);
// 显示浮点数
void tftDispFloat(uint16 x, uint16 y, float num, uint8 digit_i, uint8 digit_d);
// 显示 128*128 图片
void tftDispImage(uint16 *pic);

#endif
