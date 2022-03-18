/*  code=utf-8
    Project Hikari 电机驱动
*/
#include "motor.h"
// PID控制
volatile PID_extNode motor0PID, motor1PID;
// 初始化电机驱动
void motorInit(void)
{
    pwm_init(Motor_PWM1, motorPWMfreq, 0);
    pwm_init(Motor_PWM2, motorPWMfreq, 0);
#ifdef USE_8701E
    gpio_mode(Motor_DIR1, GPO_PP);
    gpio_mode(Motor_DIR2, GPO_PP);
#endif
#ifdef USE_298N
    gpio_mode(Motor_DIR1A, GPO_PP);
    gpio_mode(Motor_DIR1B, GPO_PP);
    gpio_mode(Motor_DIR2A, GPO_PP);
    gpio_mode(Motor_DIR2B, GPO_PP);
#endif
}
// 占空比输入的电机直接控制
void motor0DirectCtrl(int16 pwmDuty)
{
#ifdef USE_8701E
    bit dir;
    int16 duty;
    dir = neg(pwmDuty);
    duty = abs(pwmDuty);
    Motor_DIR1 = dir;
    pwm_duty(Motor_PWM1, duty);
#endif
#ifdef USE_298N
    bit dirA, dirB;
    int16 duty;
    dirA = neg(pwmDuty);
    dirB = !dirA;
    duty = abs(pwmDuty);
    Motor_DIR1A = dirA;
    Motor_DIR1B = dirB;
    pwm_duty(Motor_PWM1, duty);
#endif
}
void motor1DirectCtrl(int16 pwmDuty)
{
#ifdef USE_8701E
    bit dir;
    int16 duty;
    dir = neg(pwmDuty);
    duty = abs(pwmDuty);
    Motor_DIR2 = dir;
    pwm_duty(Motor_PWM2, duty);
#endif
#ifdef USE_298N
    bit dirA, dirB;
    int16 duty;
    dirA = neg(pwmDuty);
    dirB = !dirA;
    duty = abs(pwmDuty);
    Motor_DIR2A = dirA;
    Motor_DIR2B = dirB;
    pwm_duty(Motor_PWM2, duty);
#endif
}

// PID电机占空比计算
int16 motor0DutyUpdate(int16 encoderData)
{
    motor0PID.actual = encoderData;
    pidUpdate_ext(&motor0PID);
    return (motor0PID.output);
}
int16 motor1DutyUpdate(int16 encoderData)
{
    motor1PID.actual = encoderData;
    pidUpdate_ext(&motor1PID);
    return (motor1PID.output);
}
