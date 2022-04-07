// code = utf-8

#ifndef __al_stc16x_h
#define __al_stc16x_h

#include "stc16f.h"
#include "al_stdint.h"

/**
 * @brief 断言
 *
 */
#ifndef _ReleaseVersion
#ifdef USE_SELF_ASSERT
#define al_assert(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
void assert_failed(uint8_t *file, uint32_t line);
#else
#include <assert.h>
#define al_assert(expr) assert(expr)
#endif
#else
#define al_assert(expr) ((void)0)
#endif

/**
 * @brief 兼容性类型定义
 *
 */
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;

typedef const int32_t sc32; /* 只读 */
typedef const int16_t sc16; /* 只读 */
typedef const int8_t sc8;   /* 只读 */

typedef volatile int32_t vs32;
typedef volatile int16_t vs16;
typedef volatile int8_t vs8;

typedef volatile const int32_t vsc32; /* 只读 */
typedef volatile const int16_t vsc16; /* 只读 */
typedef volatile const int8_t vsc8;   /* 只读 */

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef const uint32_t uc32; /* 只读 */
typedef const uint16_t uc16; /* 只读 */
typedef const uint8_t uc8;   /* 只读 */

typedef volatile uint32_t vu32;
typedef volatile uint16_t vu16;
typedef volatile uint8_t vu8;

typedef volatile const uint32_t vuc32; /* 只读 */
typedef volatile const uint16_t vuc16; /* 只读 */
typedef volatile const uint8_t vuc8;   /* 只读 */

/**
 * @brief 布尔类型定义
 *
 */
typedef bit BOOL;

/**
 * @brief 标志位
 *
 */
typedef enum
{
    RESET = 0,
    SET = !RESET
} flagStatus;

/**
 * @brief 状态位
 *
 */
typedef enum
{
    DISABLE = 0,
    ENABLE = !DISABLE
} funcStatus;

/**
 * @brief 操作状态
 * 
 */
typedef enum
{
    SUCCESS = 0,
    FAILURE = !SUCCESS
} opStatus;
#endif