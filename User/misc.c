/*  code=utf-8
    Project Hikari 杂项函数
*/
#include "misc.h"
#include "key.h"
#include "buzz.h"
#include "encoder.h"
#include "servo.h"
#include "motor.h"
#include "indNavi.h"

//杂项周期计数器
volatile timeDataType misc_tick;
//系统警报状态
volatile alertState_enum sysAlertState;
//驱动刷新标记
volatile bit drvFlag;
//电池电压
float battVoltage;

//系统启动
void system_init(void)
{
    //关闭中断功能
    DisableGlobalIRQ();

    //设置运行频率
    sys_clk = SysTimeClock_Hz;
    //主板启动
    board_init();
    //初始化延时
    delay_init();

    //初始化系统警报
    sysAlertState = S_A0;
    //初始化电池检测
    adc_init(BATT, ADC_SYSclk_DIV_32);
    //初始化蜂鸣器
    buzzInit();

    //初始化电机定时周期
    pit_timer_ms(TIM_1, PITD);
    //初始化前瞻电感采集
    indInit();
    //初始化编码器
    encoderInit();
    //初始化电机
    motorInit();
    //初始化舵机
    servoInit();

    //初始化杂项定时周期
    pit_timer_ms(TIM_4, PITM);
    misc_tick = 0;
    //初始化显示屏
    lcd_init();

    //启动中断功能
    EnableGlobalIRQ();

    //显示启动信息
    lcd_showstr(0, 0, "Project Hikari");
    lcd_showstr(0, 1, "Compiled in");
    lcd_showstr(0, 2, __DATE__);
    lcd_showstr(0, 3, __TIME__);

    //发送启动信息
    printf("Project Hikari Load OK\n");

    //本机提示完成
    delay_ms(1000);
    beepShort();
    lcd_clear(WHITE);
}
//核心轮询功能
void system_loop(void)
{
    //获取电池电压
    battVoltage = (adc_once(BATT, ADC_8BIT) * 20.0) / 256;
    lcd_showfloat(40, 1, battVoltage, 1, 2);
    //电池检测
    if (battVoltage < BATTMIN && battVoltage > 3)
        sysAlertState = S_A1;
    if (battVoltage > BATTMAX)
        sysAlertState = S_A2;

    //按键处理
    updateKey();
    keyProg();
    //拨码开关处理
    swProg();
    //系统警报处理
    switch (sysAlertState)
    {
    case S_A1:
        lcd_clear(WHITE);
        lcd_showstr(0, 0, "Error: Low Battery");
        printf("Low Battery, STOP");
        motor0DirectCtrl(0);
        motor1DirectCtrl(0);
        beepAlert();
        while (1)
            ;
        break;
    case S_A2:
        lcd_clear(WHITE);
        printf("Too High Voltage, STOP");
        lcd_showstr(0, 0, "Error: Too High Voltage");
        motor0DirectCtrl(0);
        motor1DirectCtrl(0);
        beepAlert();
        while (1)
            ;
        break;
    default:
        break;
    }
}
