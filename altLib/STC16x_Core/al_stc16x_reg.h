// code = utf-8

#ifndef __al_stc16x_reg_h
#define __al_stc16x_reg_h

/* SFR */

// GPIO0
sfr P0 = 0x80;     // 按寄存器访问GPIO0
sbit P00 = P0 ^ 0; // 按位访问P0.0
sbit P01 = P0 ^ 1; // 按位访问P0.1
sbit P02 = P0 ^ 2; // 按位访问P0.2
sbit P03 = P0 ^ 3; // 按位访问P0.3
sbit P04 = P0 ^ 4; // 按位访问P0.4
sbit P05 = P0 ^ 5; // 按位访问P0.5
sbit P06 = P0 ^ 6; // 按位访问P0.6
sbit P07 = P0 ^ 7; // 按位访问P0.7
sfr P0M1 = 0xf1;   // GPIO0引脚模式配置寄存器1
sfr P0M0 = 0xf2;   // GPIO0引脚模式配置寄存器0

// GPIO1
sfr P1 = 0x90;     // 按寄存器访问GPIO1
sbit P10 = P1 ^ 0; // 按位访问P1.0
sbit P11 = P1 ^ 1; // 按位访问P1.1
sbit P12 = P1 ^ 2; // 按位访问P1.2
sbit P13 = P1 ^ 3; // 按位访问P1.3
sbit P14 = P1 ^ 4; // 按位访问P1.4
sbit P15 = P1 ^ 5; // 按位访问P1.5
sbit P16 = P1 ^ 6; // 按位访问P1.6
sbit P17 = P1 ^ 7; // 按位访问P1.7
sfr P1M1 = 0xf3;   // GPIO1引脚模式配置寄存器1
sfr P1M0 = 0xf4;   // GPIO1引脚模式配置寄存器0

// GPIO2
sfr P2 = 0xa0;     // 按寄存器访问GPIO2
sbit P20 = P2 ^ 0; // 按位访问P2.0
sbit P21 = P2 ^ 1; // 按位访问P2.1
sbit P22 = P2 ^ 2; // 按位访问P2.2
sbit P23 = P2 ^ 3; // 按位访问P2.3
sbit P24 = P2 ^ 4; // 按位访问P2.4
sbit P25 = P2 ^ 5; // 按位访问P2.5
sbit P26 = P2 ^ 6; // 按位访问P2.6
sbit P27 = P2 ^ 7; // 按位访问P2.7
sfr P2M1 = 0xf5;   // GPIO2引脚模式配置寄存器1
sfr P2M0 = 0xf6;   // GPIO2引脚模式配置寄存器0

// GPIO3
sfr P3 = 0xb0;     // 按寄存器访问GPIO3
sbit P30 = P3 ^ 0; // 按位访问P3.0
sbit P31 = P3 ^ 1; // 按位访问P3.1
sbit P32 = P3 ^ 2; // 按位访问P3.2
sbit P33 = P3 ^ 3; // 按位访问P3.3
sbit P34 = P3 ^ 4; // 按位访问P3.4
sbit P35 = P3 ^ 5; // 按位访问P3.5
sbit P36 = P3 ^ 6; // 按位访问P3.6
sbit P37 = P3 ^ 7; // 按位访问P3.7
sfr P3M1 = 0xf9;   // GPIO3引脚模式配置寄存器1
sfr P3M0 = 0xfa;   // GPIO3引脚模式配置寄存器0

// GPIO4
sfr P4 = 0xc0;     // 按寄存器访问GPIO4
sbit P40 = P4 ^ 0; // 按位访问P4.0
sbit P41 = P4 ^ 1; // 按位访问P4.1
sbit P42 = P4 ^ 2; // 按位访问P4.2
sbit P43 = P4 ^ 3; // 按位访问P4.3
sbit P44 = P4 ^ 4; // 按位访问P4.4
sbit P45 = P4 ^ 5; // 按位访问P4.5
sbit P46 = P4 ^ 6; // 按位访问P4.6
sbit P47 = P4 ^ 7; // 按位访问P4.7
sfr P4M1 = 0xfb;   // GPIO4引脚模式配置寄存器1
sfr P4M0 = 0xfc;   // GPIO4引脚模式配置寄存器0

// GPIO5
sfr P5 = 0xc8;     // 按寄存器访问GPIO5
sbit P50 = P5 ^ 0; // 按位访问P5.0
sbit P51 = P5 ^ 1; // 按位访问P5.1
sbit P52 = P5 ^ 2; // 按位访问P5.2
sbit P53 = P5 ^ 3; // 按位访问P5.3
sbit P54 = P5 ^ 4; // 按位访问P5.4
sfr P5M1 = 0xec;   // GPIO5引脚模式配置寄存器1
sfr P5M0 = 0xed;   // GPIO5引脚模式配置寄存器0

// GPIO6
sfr P6 = 0xe8;     // 按寄存器访问GPIO6
sbit P60 = P6 ^ 0; // 按位访问P6.0
sbit P61 = P6 ^ 1; // 按位访问P6.1
sbit P62 = P6 ^ 2; // 按位访问P6.2
sbit P63 = P6 ^ 3; // 按位访问P6.3
sbit P64 = P6 ^ 4; // 按位访问P6.4
sbit P65 = P6 ^ 5; // 按位访问P6.5
sbit P66 = P6 ^ 6; // 按位访问P6.6
sbit P67 = P6 ^ 7; // 按位访问P6.7
sfr P6M1 = 0xee;   // GPIO6引脚模式配置寄存器1
sfr P6M0 = 0xef;   // GPIO6引脚模式配置寄存器0

// GPIO7
sfr P7 = 0xf8;     // 按寄存器访问GPIO7
sbit P70 = P7 ^ 0; // 按位访问P7.0
sbit P71 = P7 ^ 1; // 按位访问P7.1
sbit P72 = P7 ^ 2; // 按位访问P7.2
sbit P73 = P7 ^ 3; // 按位访问P7.3
sbit P74 = P7 ^ 4; // 按位访问P7.4
sbit P75 = P7 ^ 5; // 按位访问P7.5
sbit P76 = P7 ^ 6; // 按位访问P7.6
sbit P77 = P7 ^ 7; // 按位访问P7.7
sfr P7M1 = 0xd2;   // GPIO7引脚模式配置寄存器1
sfr P7M0 = 0xd3;   // GPIO7引脚模式配置寄存器0

//  NVIC
sfr IE = 0xa8;      // 中断使能寄存器
sbit EX0 = IE ^ 0;  // INT0中断允许位
sbit ET0 = IE ^ 1;  // TIM0溢出中断允许位
sbit EX1 = IE ^ 2;  // INT1中断允许位
sbit ET1 = IE ^ 3;  // TIM1溢出中断允许位
sbit ES = IE ^ 4;   // UART1中断允许位
sbit EADC = IE ^ 5; // ADC中断允许位
sbit ELVD = IE ^ 6; // 低压检测中断允许位
sbit EA = IE ^ 7;   // 嵌套中断控制位
sfr IE2 = 0xe7;     // 中断使能寄存器2
//  EXTI

// TIM

// UART

// CMP

// IAP

// ADC

// SPI

// CAN

// LIN

/* XFR */



#endif