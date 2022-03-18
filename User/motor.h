/*  code=utf-8
    Project Hikari 电机驱动
*/
#ifndef motor_h
#define motor_h
#include "aa_all_cfg.h"
#include "pid.h"
// PID控制
extern volatile PID_extNode motor0PID, motor1PID;
// 初始化电机驱动
void motorInit(void);
// 占空比输入的电机直接控制
void motor0DirectCtrl(int16 pwmDuty);
void motor1DirectCtrl(int16 pwmDuty);
// PID电机占空比计算
int16 motor0DutyUpdate(int16 encoderData);
int16 motor1DutyUpdate(int16 encoderData);
#endif