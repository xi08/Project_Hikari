Project Hikari
使用STC16F40K128@30MHz构造

注意事项：
0. pincfg为引脚配置，allcfg为全局配置，pidcfg为PID参数配置
1. 电池默认2s锂电池，有效范围7.4-8.4V
2. 前瞻电感必须先配置LM/RM，后配置MR
3. 电感滤波为10次均值
4. 胶水双核为软件流控
X. 建议包含STC数学库和STC浮点库，加速运算
