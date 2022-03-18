/*  code=utf-8
    Project Hikari
    使用STC16F40K128@30MHz (Native MCS-251)
    8KB+32KB SRAM
    60KB+60KB Flash ROM
*/
#ifndef allCFG_h
#define allCFG_h

#include "baseConfig.h"
#include "pin_cfg.h"

//周期计数类型；uint16最长27分钟，uint32最长3.4年
#ifndef TIME_32
typedef uint16 timeDataType;
#else
typedef uint32 timeDataType;
#endif
// MCU频率，务必与STC-ISP内保持一致，Hz
#define SysTimeClock_Hz 30000000
// 电池电压限制
#define BATTMIN 7.5
#define BATTMAX 8.5


//电机定时中断周期，ms
#define PITD 5
//系统心跳定时周期，ms
#define PITM 25

//按键计数
#define keyNum 4
//长按所需周期，n*PITM
#define keyLongPressTime 16
//短按所需周期，n*PITM
#define keyShortPressTime 1

//电感计数
#if (defined(IND_EXT_MidSide) && defined(IND_EXT_MidRear))
#define indNum 6
#elif (defined(IND_EXT_MidSide))
#define indNum 5
#elif (defined(IND_EXT_MidRear))
#define indNum 4
#else
#define indNum 3
#endif

//舵机驱动频率，Hz
#define servoPWMfreq 50
//舵机最左占空比，(n/100)%
#define servoDutyMin 660
//舵机中点占空比，(n/100)%
#define servoDutyMid 740
//舵机最右占空比，(n/100)%
#define servoDutyMax 820

//电机驱动频率，Hz
#define motorPWMfreq 13000
//电机最大占空比，(n/100)%
#define motorDutyMax 3000

#endif
