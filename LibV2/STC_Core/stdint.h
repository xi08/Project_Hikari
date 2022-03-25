/*
 * C251头文件补充
 * STDINT.H
 * 适用于16位机
 * 仅提供部分STDINT.H的内容
 */

#ifndef __stdint_h
#define __stdint_h

#include <LIMITS.H>

/* 7.18.1.1 */

/* exact-width signed integer types */
typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed long int int32_t;

/* exact-width unsigned integer types */
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long int uint32_t;

/* 7.18.1.2 */

/* smallest type of at least n bits */
/* minimum-width signed integer types */
typedef signed char int_least8_t;
typedef signed short int int_least16_t;
typedef signed long int int_least32_t;

/* minimum-width unsigned integer types */
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned long int uint_least32_t;

/* 7.18.1.3 */

/* fastest minimum-width signed integer types */
typedef signed short int int_fast8_t;
typedef signed short int int_fast16_t;
typedef signed long int int_fast32_t;

/* fastest minimum-width unsigned integer types */
typedef unsigned short int uint_fast8_t;
typedef unsigned short int uint_fast16_t;
typedef unsigned long int uint_fast32_t;

/* 7.18.1.5 greatest-width integer types */
typedef int32_t intmax_t;
typedef uint32_t uintmax_t;

/* 7.18.2.1 */

/* minimum values of exact-width signed integer types */
#define INT8_MIN SCHAR_MIN
#define INT16_MIN SHRT_MIN
#define INT32_MIN LONG_MIN

/* maximum values of exact-width signed integer types */
#define INT8_MAX SCHAR_MAX
#define INT16_MAX SHRT_MAX
#define INT32_MAX LONG_MAX

/* maximum values of exact-width unsigned integer types */
#define UINT8_MAX UCHAR_MAX
#define UINT16_MAX USHRT_MAX
#define UINT32_MAX ULONG_MAX

/* 7.18.2.2 */

/* minimum values of minimum-width signed integer types */
#define INT_LEAST8_MIN SCHAR_MIN
#define INT_LEAST16_MIN SHRT_MIN
#define INT_LEAST32_MIN LONG_MIN

/* maximum values of minimum-width signed integer types */
#define INT_LEAST8_MAX SCHAR_MAX
#define INT_LEAST16_MAX SHRT_MAX
#define INT_LEAST32_MAX LONG_MAX

/* maximum values of minimum-width unsigned integer types */
#define UINT_LEAST8_MAX UCHAR_MAX
#define UINT_LEAST16_MAX USHRT_MAX
#define UINT_LEAST32_MAX ULONG_MAX

/* 7.18.2.3 */

/* minimum values of fastest minimum-width signed integer types */
#define INT_FAST8_MIN SHRT_MIN
#define INT_FAST16_MIN SHRT_MIN
#define INT_FAST32_MIN LONG_MIN

/* maximum values of fastest minimum-width signed integer types */
#define INT_FAST8_MAX SHRT_MAX
#define INT_FAST16_MAX SHRT_MAX
#define INT_FAST32_MAX LONG_MAX

/* maximum values of fastest minimum-width unsigned integer types */
#define UINT_FAST8_MAX USHRT_MAX
#define UINT_FAST16_MAX USHRT_MAX
#define UINT_FAST32_MAX ULONG_MAX

/* 7.18.2.5 */

/* minimum value of greatest-width signed integer type */
#define INTMAX_MIN LONG_MIN

/* maximum value of greatest-width signed integer type */
#define INTMAX_MAX LONG_MAX

/* maximum value of greatest-width unsigned integer type */
#define UINTMAX_MAX ULONG_MAX

#endif