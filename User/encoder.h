/*  code=utf-8
    Project Hikari 编码器驱动
*/
#ifndef encoder_h
#define encoder_h
#include "aa_all_cfg.h"
// 初始化编码器输入
void encoderInit(void);
// 读出编码器值
int16 getEncoder0Data(void);
int16 getEncoder1Data(void);

#endif
