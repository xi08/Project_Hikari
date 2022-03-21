/*  code=utf-8
	Project Hikari 显示屏驱动
	ST7735驱动芯片，16位彩色
*/

#include "TFT18.h"
#include "DisplayFont.h"

// 前景色
volatile uint16 tftColorF = 0x0000;
// 背景色
volatile uint16 tftColorB = 0xffff;

#define _tftRST(x) (DISP_RST = x)
#define _tftCMD(x) (DISP_CMD = x)
#define _tftCS(x) (DISP_CS = x)
#define _tftBL(x) (DISP_BL = x)

// 写命令
void _tftWriteCMD8(uint8 dat)
{
	_tftCS(0);
	_tftCMD(0);
	spi_mosi(dat);
	_tftCS(1);
}
// 写8位数据
void _tftWriteDAT8(uint8 dat)
{
	_tftCS(0);
	_tftCMD(1);
	spi_mosi(dat);
	_tftCS(1);
}
// 写16位数据
void _tftWriteDAT16(uint16 dat)
{
	//分割数据
	uint8 dataTmp[2];
	dataTmp[0] = dat >> 8;
	dataTmp[1] = (uint8)dat;
	//发送数据
	_tftCS(0);
	_tftCMD(1);
	spi_mosi(dataTmp[0]);
	spi_mosi(dataTmp[1]);
	_tftCS(1);
}
// 设置修改区域
void _tftRegion(uint16 stX, uint16 stY, uint16 edX, uint16 edY)
{
	_tftWriteCMD8(0x2a);
	_tftWriteDAT8(0x00);
	_tftWriteDAT8((uint8)(stX + 2));
	_tftWriteDAT8(0x00);
	_tftWriteDAT8((uint8)(edX + 2));
	_tftWriteCMD8(0x2b);
	_tftWriteDAT8(0x00);
	_tftWriteDAT8((uint8)(stY + 1));
	_tftWriteDAT8(0x00);
	_tftWriteDAT8((uint8)(edY + 1));
	_tftWriteCMD8(0x2c);
}
// 初始化显示屏
void tftInit(void)
{
	spi_init(SD_SPIx, SD_SCLK, SD_MOSI, SD_MISO, 0, MASTER, SPI_SYSclk_DIV_4);
	_tftRST(0);
	delay_ms(10);
	_tftRST(1);
	delay_ms(120);
	_tftWriteCMD8(0x11);
	delay_ms(120);
	_tftWriteCMD8(0xB1);
	_tftWriteDAT8(0x01);
	_tftWriteDAT8(0x2C);
	_tftWriteDAT8(0x2D);
	_tftWriteCMD8(0xB2);
	_tftWriteDAT8(0x01);
	_tftWriteDAT8(0x2C);
	_tftWriteDAT8(0x2D);
	_tftWriteCMD8(0xB3);
	_tftWriteDAT8(0x01);
	_tftWriteDAT8(0x2C);
	_tftWriteDAT8(0x2D);
	_tftWriteDAT8(0x01);
	_tftWriteDAT8(0x2C);
	_tftWriteDAT8(0x2D);
	_tftWriteCMD8(0xB4);
	_tftWriteDAT8(0x07);
	_tftWriteCMD8(0xC0);
	_tftWriteDAT8(0xA2);
	_tftWriteDAT8(0x02);
	_tftWriteDAT8(0x84);
	_tftWriteCMD8(0xC1);
	_tftWriteDAT8(0xC5);
	_tftWriteCMD8(0xC2);
	_tftWriteDAT8(0x0A);
	_tftWriteDAT8(0x00);
	_tftWriteCMD8(0xC3);
	_tftWriteDAT8(0x8A);
	_tftWriteDAT8(0x2A);
	_tftWriteCMD8(0xC4);
	_tftWriteDAT8(0x8A);
	_tftWriteDAT8(0xEE);
	_tftWriteCMD8(0xC5);
	_tftWriteDAT8(0x0E);
	_tftWriteCMD8(0x36);
	_tftWriteDAT8(0xc0);
	_tftWriteCMD8(0xe0);
	_tftWriteDAT8(0x0f);
	_tftWriteDAT8(0x1a);
	_tftWriteDAT8(0x0f);
	_tftWriteDAT8(0x18);
	_tftWriteDAT8(0x2f);
	_tftWriteDAT8(0x28);
	_tftWriteDAT8(0x20);
	_tftWriteDAT8(0x22);
	_tftWriteDAT8(0x1f);
	_tftWriteDAT8(0x1b);
	_tftWriteDAT8(0x23);
	_tftWriteDAT8(0x37);
	_tftWriteDAT8(0x00);
	_tftWriteDAT8(0x07);
	_tftWriteDAT8(0x02);
	_tftWriteDAT8(0x10);
	_tftWriteCMD8(0xe1);
	_tftWriteDAT8(0x0f);
	_tftWriteDAT8(0x1b);
	_tftWriteDAT8(0x0f);
	_tftWriteDAT8(0x17);
	_tftWriteDAT8(0x33);
	_tftWriteDAT8(0x2c);
	_tftWriteDAT8(0x29);
	_tftWriteDAT8(0x2e);
	_tftWriteDAT8(0x30);
	_tftWriteDAT8(0x30);
	_tftWriteDAT8(0x39);
	_tftWriteDAT8(0x3f);
	_tftWriteDAT8(0x00);
	_tftWriteDAT8(0x07);
	_tftWriteDAT8(0x03);
	_tftWriteDAT8(0x10);
	_tftWriteCMD8(0x2a);
	_tftWriteDAT8(0x00);
	_tftWriteDAT8(0x02);
	_tftWriteDAT8(0x00);
	_tftWriteDAT8(0x82);
	_tftWriteCMD8(0x2b);
	_tftWriteDAT8(0x00);
	_tftWriteDAT8(0x03);
	_tftWriteDAT8(0x00);
	_tftWriteDAT8(0x83);
	_tftWriteCMD8(0xF0);
	_tftWriteDAT8(0x01);
	_tftWriteCMD8(0xF6);
	_tftWriteDAT8(0x00);
	_tftWriteCMD8(0x3A);
	_tftWriteDAT8(0x05);
	_tftWriteCMD8(0x29);
	//清屏
	tftClear();
	//设置字体
	tftChangeFont(Font_8x16);
}
// 清空显示屏
void tftClear(void)
{
	uint8 i, j;
	_tftRegion(0, 0, tftMaxX - 1, tftMaxY - 1);
	for (i = 0; i < tftMaxX; i++)
		for (j = 0; j < tftMaxY; j++)
			_tftWriteDAT16(tftColorB);
}
// 显示字符
void tftDispChar(uint16 posX, uint16 posY, const int8 ch)
{
	uint8 i, j;
	uint8 fontLineTmp;

	for (i = 0; i < tftFontY; i++)
	{
		_tftRegion(posX, posY + i, posX + tftFontX, posY + i);
		fontLineTmp = tftFont[ch - ' '][i];
		for (j = 0; j < tftFontX; j++)
		{
			if (fontLineTmp & 1)
				_tftWriteDAT16(tftColorF);
			else
				_tftWriteDAT16(tftColorB);
			fontLineTmp >>= 1;
		}
	}
}
// 显示字符串
void tftDispStr(uint16 x, uint16 y, const int8 *str)
{
	size_t j = 0;
	while (str[j])
	{
		tftDispChar(x + 8 * j, y * 16, str[j]);
		j++;
	}
}
// 显示有符号数字
void tftDispInt(uint16 x, uint16 y, int32 num, uint8 digit_i)
{
	int8 buff[12];
	uint8 length;
	if (digit_i > 10)
		digit_i = 10;
	digit_i++;
	if (digit_i < 0)
		// 负数
		length = zf_sprintf(&buff[0], "%d", num);
	else
	{
		// 正数
		buff[0] = ' ';
		length = zf_sprintf(&buff[1], "%d", num);
		length++;
	}
	while (length < digit_i)
		buff[length++] = ' ';
	buff[digit_i] = '\0';
	//显示
	tftDispStr(x, y, buff);
}
// 显示无符号数字
void tftDispUint(uint16 x, uint16 y, uint32 num, uint8 digit_i)
{
	int8 buff[12];
	uint8 length;
	if (digit_i > 10)
		digit_i = 10;
	length = zf_sprintf(buff, "%u", num);
	while (length < digit_i)
		buff[length++] = ' ';
	buff[digit_i] = '\0';

	tftDispStr(x, y, buff); //显示
}
// 显示浮点数
void tftDispFloat(uint16 x, uint16 y, float num, uint8 digit_i, uint8 digit_d)
{
	int8 buff[20];
	uint8 length;
	int8 start, end, point;

	if (digit_d > 6)
		digit_d = 6;
	if (digit_i > 10)
		digit_i = 10;

	if (num > 0)
		// 负数
		length = zf_sprintf(&buff[0], "%f", num);
	else
	{
		// 正数
		length = zf_sprintf(&buff[1], "%f", num);
		length++;
	}

	point = length - 7;			 //计算小数点位置
	start = point - digit_i - 1; //计算起始位
	end = point + digit_d + 1;	 //计算结束位

	while (start < 0) //整数位不够  末尾应该填充空格
	{
		buff[end] = ' ';
		end++;
		start++;
	}

	if (num < 0)
		buff[start] = '-';
	else
		buff[start] = ' ';

	buff[end] = '\0';

	tftDispStr(x, y, buff); //显示数字
}
// 显示 128*128 图片
void tftDispImage(uint16 **pic)
{
}
