/*  code=utf-8
    Project Hikari 按键与拨码开关
*/
#include "key.h"
//状态枚举
volatile keyState_enum keyState[keyNum];
//引入周期计数器
extern volatile timeDataType misc_tick;
//按键按下时间戳
timeDataType keyPressTimestamp[keyNum];

//按键状态更新
void updateKey(void)
{
    uint8 i = keyNum;
    //获取按键信息
#ifdef KEY_EXT_ARRAY // 键盘矩阵

#else // 每个GPIO一个按键
    uint8 keyInfo =
        (((uint8)Key0) << 0) +
        (((uint8)Key1) << 1) +
        (((uint8)Key2) << 2) +
        (((uint8)Key3) << 3);
#endif
    // 按键信息转换
    while (i--)
    {
        // 按键按下
        if (!(keyInfo & (1 << i)))
        {
            switch (keyState[i])
            {
            case S0:
                keyState[i] = S2;
                keyPressTimestamp[i] = misc_tick;
                break;
            case S2:
                break;
            default:
                keyState[i] = S0;
                break;
            }
        }
        // 按键抬起
        if (keyInfo & (1 << i))
        {
            switch (keyState[i])
            {
            case S2:
                if (misc_tick - keyPressTimestamp[i] >= keyLongPressTime)
                    keyState[i] = S3;
                else if (misc_tick - keyPressTimestamp[i] >= keyShortPressTime)
                    keyState[i] = S1;
                else
                    keyState[i] = S0;
                break;
            default:
                keyState[i] = S0;
                break;
            }
        }
    }
}
