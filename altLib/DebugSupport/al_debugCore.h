#ifndef __al_debugCore_h
#define __al_debugCore_h

#include "al_stc16x.h"
#include "al_debugAux.h"

#ifdef USE_AltLib

#define MaxFuncNameLength 30 // 函数名最大匹配长度
#define MaxFuncParmNum 10    // 函数最大参数量
#define MaxFuncParmSize 200  // 所有参数大小之和

/**
 * @brief 函数执行结构
 *
 */
typedef struct
{
    void *ptr;                         // 函数指针
    const char *name;                  // 函数名
    uint8_t parmNum;                   // 参数数量
    uint8_t parmSize[MaxFuncParmNum];  // 每个参数的所占的字节数
    uint8_t parmList[MaxFuncParmSize]; // 函数的参数储存
} al_debug_funcNode;

void usmart_init(u8 sysclk);        // 初始化
u8 usmart_cmd_rec(u8 *str);         // 识别
void usmart_exec(void);             // 执行
u32 read_addr(u32 addr);            // 读取指定地址的值
void write_addr(u32 addr, u32 val); // 在指定地址写入指定的值

#endif

#endif