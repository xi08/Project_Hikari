/*  code=utf-8
    Project Hikari PID控制
*/
#include "pid.h"

void pidUpdate_base(volatile PID_baseNode *p)
{
    // 更新误差项
    p->err_2 = p->err_1;
    p->err_1 = p->err;
    p->err = p->target - p->actual;
    // 计算反馈
    p->delta = p->Kp * (p->err - p->err_1) + p->Ki * p->err + p->Kd * (p->err - 2 * p->err_1 + p->err_2);
    // 最终输出
    p->output = p->actual + p->delta;
}
void pidUpdate_ext(volatile PID_extNode *p)
{
    // 更新误差项
    p->err_2 = p->err_1;
    p->err_1 = p->err;
    p->err = p->target - p->actual;
    // 变积分
    if (abs(p->err) < p->pKi_start * p->target)
        p->pKi = 1;
    else if (abs(p->err) > p->pKi_end * p->target)
        p->pKi = 0;
    else
        p->pKi = (p->pKi_end * p->target - abs(p->err)) / (p->target * (p->pKi_end - p->pKi_start));
    // 计算反馈
    p->delta = p->Kp * (p->err - p->err_1) + (p->Ki * p->pKi) * (p->err) + p->Kd * (p->err - 2 * p->err_1 + p->err_2);
    // 最终输出
    p->output = p->actual + p->delta;
}