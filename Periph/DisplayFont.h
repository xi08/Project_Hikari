/*  code=utf-8
    Project Hikari 显示屏字体文件
*/
#ifndef DisplayFont_h
#define DisplayFont_h
#include "common.h"

typedef enum
{
    Font_8x16,
    Font_6x8,

} tftFont_enum;

extern uint8 tftFontX, tftFontY;
extern const uint8 **tftFont;
void tftChangeFont(tftFont_enum f);

extern const uint8 code dispFont_8x16[95][16];
extern const uint8 code dispFont_6x8[95][8];
#endif