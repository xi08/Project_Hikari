/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ790875685)
 * @version    		查看doc内version文件 版本说明
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC16F40K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-12-18
 ********************************************************************************************************************/

#include "misc.h"
#include "key.h"
#include "buzz.h"
#include "encoder.h"
#include "servo.h"
#include "motor.h"
#include "indNavi.h"
#include "ui.h"

//编码器数据
int16 encoder_data[2];
//电感数据
uint8 ind_data[indNum];
//电机占空比
int16 motor_duty[2];
//舵机占空比
uint16 servo_duty;

void main()
{
    //系统启动
    system_init();
    // setup
    lcd_showstr(0, 0, "Project Hikari");
    lcd_showstr(0, 1, "Batt:");
    lcd_showstr(0, 2, "Hall:");
    lcd_showstr(0, 3, "Key:");
    lcd_showstr(0, 4, "Enc:");
    lcd_showstr(0, 5, "Mtr:");
    lcd_showstr(0, 6, "SPD:");
    lcd_showstr(0, 7, "CNT:");
    lcd_showstr(0, 8, "IndC:");
#if (defined(IND_EXT_MidSide) || defined(IND_EXT_MidRear))
    lcd_showstr(0, 9, "IndX:");
#endif
    while (1)
    {
        // 核心轮询功能
        system_loop();
        // 处理5ms电机中断
        if (drvFlag)
        {
            drvFUNC();
            // 清除电机中断标记
            drvFlag = !drvFlag;
        }
    }
}
//驱动控制
void drvFUNC(void)
{
    if (uiState == Running)
    {
        // 数据上屏
        lcd_showstr(40, 2, (Hall ? "N" : "D"));
        lcd_showint32(40, 4, encoder_data[0], 4);
        lcd_showint32(80, 4, encoder_data[1], 4);
        lcd_showint32(48, 8, indFilteredData[0], 2);
        lcd_showint32(72, 8, indFilteredData[1], 2);
        lcd_showint32(96, 8, indFilteredData[2], 2);
#ifdef IND_EXT_MidSide
        lcd_showint32(48, 9, indFilteredData[3], 2);
        lcd_showint32(72, 9, indFilteredData[4], 2);
#endif
#ifdef IND_EXT_MidRear
        lcd_showint32(96, 9, indFilteredData[5], 2);
#endif
        // 同步编码器
        encoder_data[0] = getEncoder0Data();
        encoder_data[1] = -getEncoder1Data();
        // 同步电感
        getIndInfo(ind_data);
        // 计算

        // 同步舵机
        servoDirectCtrl(&servo_duty);
        // 同步电机
        motor0DirectCtrl(motor_duty[0]);
        motor1DirectCtrl(motor_duty[1]);
    }
}
//按键处理
void keyProg(void)
{
    //按键0
    switch (keyState[0])
    {
    //短按
    case S1:
        beepShort();
        printf("S0\n");
        lcd_showstr(40, 3, "S0");
        keyState[0] = S0;
        break;
    //长按
    case S3:
        beepShort();
        printf("L1\n");
        lcd_showstr(40, 3, "L0");
        keyState[0] = S0;
        break;
    default:
        break;
    }
    //按键2
    switch (keyState[1])
    {
    //短按
    case S1:
        beepShort();
        printf("S1\n");
        lcd_showstr(40, 3, "S1");
        keyState[1] = S0;
        break;
    //长按
    case S3:
        beepShort();
        printf("L1\n");
        lcd_showstr(40, 3, "L1");
        keyState[1] = S0;
        break;
    default:
        break;
    }
    //按键3
    switch (keyState[2])
    {
    //短按
    case S1:
        beepShort();
        printf("S2\n");
        lcd_showstr(40, 3, "S2");
        keyState[2] = S0;
        break;
    //长按
    case S3:
        beepShort();
        printf("L2\n");
        lcd_showstr(40, 3, "L2");
        keyState[2] = S0;
        break;
    default:
        break;
    }
    //按键4
    switch (keyState[3])
    {
    //短按
    case S1:
        beepShort();
        printf("S3\n");
        lcd_showstr(40, 3, "S3");
        keyState[3] = S0;
        break;
    //长按
    case S3:
        beepShort();
        printf("L3\n");
        lcd_showstr(40, 3, "L3");
        keyState[3] = S0;
        break;
    default:
        break;
    }
}
//拨码开关处理
void swProg(void)
{
    //拨码1
    //高
    if (Switch0)
    {
    }
    //低
    if (!Switch0)
    {
    }
    //拨码2
    //高
    if (Switch1)
    {
    }
    //低
    if (!Switch1)
    {
    }
}