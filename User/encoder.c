/*  code=utf-8
    Project Hikari 编码器驱动
*/
#include "encoder.h"

//初始化编码器输入
void encoderInit(void)
{
    ctimer_count_init(Encoder0_Pluse);
    ctimer_count_init(Encoder1_Pluse);
}
//读出编码器值
int16 getEncoder0Data(void)
{
    int16 tmp = ctimer_count_read(Encoder0_Pluse);
    ctimer_count_clean(Encoder0_Pluse);
    return sig(Encoder0_Dir) * tmp;
}
int16 getEncoder1Data(void)
{
    int16 tmp = ctimer_count_read(Encoder1_Pluse);
    ctimer_count_clean(Encoder1_Pluse);
    return sig(Encoder1_Dir) * tmp;
}
