/*  code=utf-8
    Project Hikari UI菜单
*/
#ifndef ui_h
#define ui_h
#include "aa_all_cfg.h"

typedef enum
{
    Menu,
    Running,
    PID_Config,

} uiState_enum;


extern volatile uiState_enum uiState;

#endif
