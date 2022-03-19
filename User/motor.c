/*  code=utf-8
    Project Hikari 电机驱动
*/
#include "motor.h"
// PID控制
volatile PID_extNode motor0PID, motor1PID;
// 初始化电机驱动
void motorInit(void)
{

#ifdef USE_8701E
    pwm_init(Motor_PWM0, motorPWMfreq, 0);
    gpio_mode(Motor_DIR0, GPO_PP);
    pwm_init(Motor_PWM1, motorPWMfreq, 0);
    gpio_mode(Motor_DIR1, GPO_PP);
#endif
#ifdef USE_4082
    pwm_init(Motor_PWM0A, motorPWMfreq, 0);
    pwm_init(Motor_PWM0B, motorPWMfreq, 0);
    pwm_init(Motor_PWM1A, motorPWMfreq, 0);
    pwm_init(Motor_PWM1B, motorPWMfreq, 0);
#endif
#ifdef USE_298N
    pwm_init(Motor_PWM0, motorPWMfreq, 0);
    gpio_mode(Motor_DIR0A, GPO_PP);
    gpio_mode(Motor_DIR0B, GPO_PP);
    pwm_init(Motor_PWM1, motorPWMfreq, 0);
    gpio_mode(Motor_DIR1A, GPO_PP);
    gpio_mode(Motor_DIR1B, GPO_PP);
#endif
}
// 占空比输入的电机直接控制
void motor0DirectCtrl(int16 pwmDuty)
{
    if (pwmDuty >= 0)
    {
#ifdef USE_8701E
        pwm_duty(Motor_PWM0, pwmDuty);
        Motor_DIR0 = 0;
#endif
#ifdef USE_4082
        pwm_duty(Motor_PWM0A, pwmDuty);
        pwm_duty(Motor_PWM0B, 0);
#endif
#ifdef USE_298N
        pwm_duty(Motor_PWM0, pwmDuty);
        Motor_DIR0A = 0;
        Motor_DIR0B = 1;
#endif
    }
    else
    {
#ifdef USE_8701E
        pwm_duty(Motor_PWM0, -pwmDuty);
        Motor_DIR0 = 1;
#endif
#ifdef USE_4082
        pwm_duty(Motor_PWM0A, 0);
        pwm_duty(Motor_PWM0B, pwmDuty);
#endif
#ifdef USE_298N
        pwm_duty(Motor_PWM0, pwmDuty);
        Motor_DIR0A = 1;
        Motor_DIR0B = 0;
#endif
    }
}
void motor1DirectCtrl(int16 pwmDuty)
{
    if (pwmDuty >= 0)
    {
#ifdef USE_8701E
        pwm_duty(Motor_PWM1, pwmDuty);
        Motor_DIR1 = 0;
#endif
#ifdef USE_4082
        pwm_duty(Motor_PWM1A, pwmDuty);
        pwm_duty(Motor_PWM1B, 0);
#endif
#ifdef USE_298N
        pwm_duty(Motor_PWM1, pwmDuty);
        Motor_DIR1A = 0;
        Motor_DIR1B = 1;
#endif
    }
    else
    {
#ifdef USE_8701E
        pwm_duty(Motor_PWM1, -pwmDuty);
        Motor_DIR1 = 1;
#endif
#ifdef USE_4082
        pwm_duty(Motor_PWM1A, 0);
        pwm_duty(Motor_PWM1B, pwmDuty);
#endif
#ifdef USE_298N
        pwm_duty(Motor_PWM1, pwmDuty);
        Motor_DIR1A = 1;
        Motor_DIR1B = 0;
#endif
    }
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
