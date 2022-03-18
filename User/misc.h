/*  code=utf-8
    Project Hikari 杂项函数
*/
#ifndef misc_h
#define misc_h
#include "aa_all_cfg.h"

//杂项周期计数器
extern volatile timeDataType misc_tick;
//系统警报状态
extern volatile alertState_enum sysAlertState;
//驱动刷新标记
extern volatile bit drvFlag;

//系统启动
void system_init(void);
//核心轮询功能
void system_loop(void);
//驱动控制
void drvFUNC(void);

#endif
