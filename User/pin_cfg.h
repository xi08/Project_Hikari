/*  code=utf-8
    Project Hikari 引脚配置
*/
#ifndef pinCFG_h
#define pinCFG_h
#include "baseConfig.h"

/* 核心板上LED */
#define CoreBoard_LED P52

/* 电池电压 */
#define BATT ADC_P15

/* 蜂鸣器 */
#define BUZ P77
#ifdef BUZZ_EXT_PWM 
#define BUZ_PWM PWMB_CH4_P77
#endif

/* 拨码开关 */
#define Switch0 P75
#define Switch1 P76

/* 按键 */
// GPIO按键
#define Key0 P70
#define Key1 P71
#define Key2 P72
#define Key3 P73
// 按键阵列
#ifdef KEY_EXT_ARRAY
#define KeyArray_X0 P70
#define KeyArray_Y0 P71
#define KeyArray_X1 P72
#define KeyArray_Y1 P73
#define KeyArray_X2 P65
#define KeyArray_Y2 P67
#endif

/* 编码器 */
#define Encoder0_Pluse CTIM0_P34
#define Encoder0_Dir P35
#define Encoder1_Pluse CTIM3_P04
#define Encoder1_Dir P53

/* 显示 */
// 定义在库文件中，这里仅占位
#define DISP_SPIx SPI_CH2
#define DISP_SCLK SPI_CH2_SCLK_P25
#define DISP_MOSI SPI_CH2_MOSI_P23
#define DISP_MISO SPI_CH2_MISO_P24
#define DISP_RST P20
#define DISP_CMD P21
#define DISP_CS0 P22
#define DISP_BL P27

/* 舵机 */
#define Servo_PWM PWMB_CH1_P74

/* 电机 */
#define Motor_PWM1 PWMA_CH4P_P66
#define Motor_PWM2 PWMA_CH2P_P62
// L298N
#ifdef USE_298N
#define Motor_DIR1A P64
#define Motor_DIR2A P60
#define Motor_DIR1B P61
#define Motor_DIR2B P63
#endif
// DRV8701E
#ifdef USE_8701E
#define Motor_DIR1 P64
#define Motor_DIR2 P60
#endif
// HIP4082
#ifdef USE_4082
#define Motor_PWM1_Aux P64
#define Motor_PWM2_Aux P60
#endif

/* 霍尔检测 */
#define Hall P26

/* 电感 */
// Base
#define IND_MF ADC_P01 // 中，横置
#define IND_LL ADC_P00 // 左，横置
#define IND_RR ADC_P06 // 右，横置
// MidSide extension
#define IND_LM ADC_P13 // 中左，竖置
#define IND_RM ADC_P14 // 中右，竖置
// MidRear extension
#define IND_MR ADC_P05 // 中后，横置
// 占位
#define IND_X0 ADC_P10
#define IND_X1 ADC_P11

/* E2PROM */
#define E2P_I2C IIC_4
#define E2P_SCL IIC4_SCL_P32
#define E2P_SDA IIC4_SDA_P33

/* 各种SPI设备 */
#define SD_SPIx SPI_CH3
#define SD_SCLK SPI_CH3_SCLK_P43
#define SD_MOSI SPI_CH3_MOSI_P40
#define SD_MISO SPI_CH3_MISO_P41
#define SD_CS0 P42
#define SD_CS1 P44
#define SD_CS2 P45

/* 胶水双核互联 */
#define IC_UARTx UART_2
#define IC_Rx UART2_RX_P46
#define IC_Tx UART2_TX_P47

/* 无线串口 */
// 定义在库文件中，这里仅占位
#define WirelessComm_UARTx UART_4
#define WirelessComm_Tx UART4_TX_P03
#define WirelessComm_Rx UART4_RX_P02
#define WirelessComm_RTS P07

/* 各种串口设备 */
#define UD_UARTx UART_3
#define UD_Rx UART3_RX_P50
#define UD_Tx UART3_TX_P51
#define UD_RTS P12



#endif