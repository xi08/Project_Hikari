/*  code=utf-8
    Project Hikari 舵机驱动
*/
#ifndef servo_h
#define servo_h
#include "aa_all_cfg.h"
#include "pid.h"
// PID控制
extern volatile PID_baseNode servoPID;
// 初始化舵机驱动
void servoInit(void);
// 占空比输入的舵机直接控制
void servoDirectCtrl(uint16 *pwmDuty);
// PID舵机占空比计算
int16 servoDutyUpdate(void);
#endif