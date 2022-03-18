/*  code=utf-8
    Project Hikari 舵机驱动
*/
#include "servo.h"
// 舵机PID
volatile PID_baseNode servoPID;
// 初始化舵机驱动
void servoInit(void)
{
    pwm_init(Servo_PWM, servoPWMfreq, servoDutyMid);
}
//占空比输入的舵机直接控制
void servoDirectCtrl(uint16 *pwmDuty)
{
    if (*pwmDuty > servoDutyMax)
        *pwmDuty = servoDutyMax;
    if (*pwmDuty < servoDutyMin)
        *pwmDuty = servoDutyMin;
    pwm_duty(Servo_PWM, *pwmDuty);
}
// PID舵机占空比计算
int16 servoDutyUpdate(void)
{
    servoPID.actual = servoPID.output;
    pidUpdate_base(&servoPID);
    return (servoPID.output);
}
