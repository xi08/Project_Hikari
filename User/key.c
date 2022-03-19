/*  code=utf-8
    Project Hikari 按键与拨码开关
*/
#include "key.h"
// 状态枚举
volatile keyState_enum keyState[keyNum];
// 引入周期计数器
extern volatile timeDataType misc_tick;
// 按键按下时间戳
timeDataType keyPressTimestamp[keyNum];

// 按键状态更新
void updateKey(void)
{
    uint8 i = keyNum, keyInfo = 0xff;
#ifdef KEY_EXT_Matrix // 键盘矩阵
    //获取按键信息
    //第0列
    KeyMatrix_X0 = 1;
    if (KeyMatrix_Y0)
        keyInfo = 0;
    if (KeyMatrix_Y1)
        keyInfo = 1;
    if (KeyMatrix_Y2)
        keyInfo = 2;
    KeyMatrix_X0 = 0;
    //第1列
    keyMatrix_X1 = 1;
    if (KeyMatrix_Y0)
        keyInfo = 3;
    if (KeyMatrix_Y1)
        keyInfo = 4;
    if (KeyMatrix_Y2)
        keyInfo = 5;
    keyMatrix_X1 = 0;
    //第2列
    keyMatrix_X2 = 1;
    if (KeyMatrix_Y0)
        keyInfo = 6;
    if (KeyMatrix_Y1)
        keyInfo = 7;
    if (KeyMatrix_Y2)
        keyInfo = 8;
    keyMatrix_X2 = 0;

#else // 每个GPIO一个按键
    //获取按键信息
    keyInfo ^= (((uint8)Key0) << 0);
    keyInfo ^= (((uint8)Key1) << 1);
    keyInfo ^= (((uint8)Key2) << 2);
    keyInfo ^= (((uint8)Key3) << 3);
#ifdef KEY_EXT_6KEY
    keyInfo ^= (((uint8)Key4) << 4);
    keyInfo ^= (((uint8)Key5) << 5);
#endif
    // 按键信息转换
    while (i--)
    {
        // 按键按下
#ifdef KEY_EXT_Matrix
        if (i == keyInfo)
        {
#else
        if (keyInfo & (1 << i))
        {
#endif
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
#ifdef KEY_EXT_Matrix
        if (i != keyInfo)
        {
#else
        if (!(keyInfo & (1 << i)))
        {
#endif
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
#endif
}
