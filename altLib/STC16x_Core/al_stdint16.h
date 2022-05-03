
#ifndef __al_stdint16_h
#define __al_stdint16_h

/* exact-width signed integer types */
typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed long int int32_t;

/* exact-width unsigned integer types */
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned long int uint32_t;

/* smallest type of at least n bits */
/* minimum-width signed integer types */
typedef signed char int_least8_t;
typedef signed short int int_least16_t;
typedef signed long int int_least32_t;

/* minimum-width unsigned integer types */
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned long int uint_least32_t;

/* fastest minimum-width signed integer types */
typedef signed short int int_fast8_t;
typedef signed short int int_fast16_t;
typedef signed long int int_fast32_t;

/* fastest minimum-width unsigned integer types */
typedef unsigned short int uint_fast8_t;
typedef unsigned short int uint_fast16_t;
typedef unsigned long int uint_fast32_t;

/*  greatest-width integer types */
typedef int32_t intmax_t;
typedef uint32_t uintmax_t;

/* minimum values of exact-width signed integer types */
#define INT8_MIN (-128)
#define INT16_MIN (-32767 - 1)
#define INT32_MIN (-2147483647L - 1L)

/* maximum values of exact-width signed integer types */
#define INT8_MAX 127
#define INT16_MAX 32767
#define INT32_MAX 2147483647L

/* maximum values of exact-width unsigned integer types */
#define UINT8_MAX 255
#define UINT16_MAX 0xFFFF
#define UINT32_MAX 0xFFFFFFFF

/* minimum values of minimum-width signed integer types */
#define INT_LEAST8_MIN (-128)
#define INT_LEAST16_MIN (-32767 - 1)
#define INT_LEAST32_MIN (-2147483647L - 1L)

/* maximum values of minimum-width signed integer types */
#define INT_LEAST8_MAX 127
#define INT_LEAST16_MAX 32767
#define INT_LEAST32_MAX 2147483647L

/* maximum values of minimum-width unsigned integer types */
#define UINT_LEAST8_MAX 255
#define UINT_LEAST16_MAX 0xFFFF
#define UINT_LEAST32_MAX 0xFFFFFFFF

/* minimum values of fastest minimum-width signed integer types */
#define INT_FAST8_MIN (-32767 - 1)
#define INT_FAST16_MIN (-32767 - 1)
#define INT_FAST32_MIN (-2147483647L - 1L)

/* maximum values of fastest minimum-width signed integer types */
#define INT_FAST8_MAX 32767
#define INT_FAST16_MAX 32767
#define INT_FAST32_MAX 2147483647L

/* maximum values of fastest minimum-width unsigned integer types */
#define UINT_FAST8_MAX 0xFFFF
#define UINT_FAST16_MAX 0xFFFF
#define UINT_FAST32_MAX 0xFFFFFFFF

/* minimum value of greatest-width signed integer type */
#define INTMAX_MIN (-2147483647L - 1L)

/* maximum value of greatest-width signed integer type */
#define INTMAX_MAX 2147483647L

/* maximum value of greatest-width unsigned integer type */
#define UINTMAX_MAX 0xFFFFFFFF

#endif