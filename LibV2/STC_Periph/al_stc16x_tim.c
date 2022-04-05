
// code = utf-8

#include "al_stc16x_tim.h"

/**
 * @brief 用给定参数初始化定时器
 *
 * @param TIMx 需要初始化的定时器
 * @param initStruct 初始化结构体
 */
void TIM_Init(TIM_enum TIMx, TIM_InitTypeDef *initStruct)
{
    /* 检查参数合法性 */
    al_assert(IS_TIM_Periph(TIMx));
    al_assert(IS_TIM_Mode(initStruct->TIM_Mode));
    al_assert(IS_TIM_ClkDiv(initStruct->TIM_CKD_DIVx));
    /* 设置参数 */
    
}
