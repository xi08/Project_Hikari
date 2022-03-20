/*  code=utf-8
	Project Hikari 显示屏驱动
	ST7735驱动芯片，16位彩色
*/

#include "TFT18.h"
#include "DisplayFont.h"

// 前景色
uint16 tftColorF = 0x0000;
// 背景色
uint16 tftColorB = 0xFFFF;

// 写命令
void _tftWriteCMD8(uint8 dat)
{
	tftCS(0);
	tftCMD(0);
	spi_mosi(dat);
	tftCS(1);
}
// 写8位数据
void _tftWriteData8(uint8 dat)
{
	tftCS(0);
	tftCMD(1);
	spi_mosi(dat);
	tftCS(1);
}
// 写16位数据
void _tftWriteData16(uint16 dat)
{
	//分割数据
	uint8 dataTmp[2];
	dataTmp[0] = dat >> 8;
	dataTmp[1] = (uint8)dat;
	//发送数据
	tftCS(0);
	tftCMD(1);
	spi_mosi(dataTmp[0]);
	spi_mosi(dataTmp[1]);
	tftCS(1);
}
// 初始化显示屏
void tftInit(void)
{
}
// 清空显示屏
void tftClear(void)
{
}
// 设置前景颜色
void tftSetColorF(uint16 color)
{
}
// 设置背景颜色
void tftSetColorB(uint16 color)
{
}
// 显示字符
void tftDispChar(uint16 x, uint16 y, const int8 c)
{
}
// 显示字符串
void tftDispStr(uint16 x, uint16 y, const int8 *str)
{
}
// 显示有符号数字
void tftDispInt(uint16 x, uint16 y, int32 num, uint8 digit_i)
{
}
// 显示无符号数字
void tftDispUint(uint16 x, uint16 y, uint32 num, uint8 digit_i)
{
}
// 显示浮点数
void tftDispFloat(uint16 x, uint16 y, float num, uint8 digit_i, uint8 digit_d)
{
}
// 显示 128*128 图片
void tftDispImage(uint16 *pic)
{
}
