/*  code=utf-8
    Project Hikari PID控制
*/
#ifndef pid_h
#define pid_h
#include "aa_all_cfg.h"
//基础增量式PID
typedef struct PID_baseNode
{
    int16 target, actual;
    int16 err, err_1, err_2; // err(t),err(t-1),err(t-2)
    float Kp, Ki, Kd;
    int16 delta, output;
} PID_baseNode;

void pidUpdate_base(volatile PID_baseNode *);


//变积分增量式PID
typedef struct PID_extNode
{
    int16 target, actual;
    int16 err, err_1, err_2; // err(t),err(t-1),err(t-2)
    float Kp, Ki, Kd;
    float pKi; // weight
    float pKi_start, pKi_end;
    int16 delta, output;
} PID_extNode;

void pidUpdate_ext(volatile PID_extNode *);



#endif