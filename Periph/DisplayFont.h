/*  code=utf-8
    Project Hikari 显示屏字体文件
*/
#ifndef DisplayFont_h
#define DisplayFont_h

#ifdef USE_TFT18
typedef enum
{
    Font_8x16,
    Font_6x8,

} tftFont_enum;

extern uint8 tftFontX, tftFontY;
extern uint8 **tftFont;
void tftChangeFont(tftFont_enum f);

#endif
extern const uint8 dispFont_8x16[95][16];
extern const uint8 dispFont_6x8[95][8];
#endif