/*  code=utf-8
    Project Hikari 前瞻电感
*/
#ifndef indNavi_h
#define indNavi_h

#include "aa_all_cfg.h"

//电感滤波后数据
extern volatile uint16 indFilteredData[indNum];
//归一化上下限值
extern volatile uint16 indMaxData[indNum], indMinData[indNum];

//电感初始化
void indInit(void);
//获取已解算的电感数据
void getIndInfo(uint8 *indArray);

#endif