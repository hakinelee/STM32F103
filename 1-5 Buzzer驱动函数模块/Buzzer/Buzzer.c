#include "Buzzer.h"

////////////////////////////////////////////
/// 以下蜂鸣器驱动函数针对的是：有源蜂鸣器
////////////////////////////////////////////

/**
 * 函  数：蜂鸣器初始化
 * 参  数：无
 * 返回值：无
 */
void Buzzer_Init(void) {
    /* 开启时钟 */
    RCC_APB2PeriphClockCmd(BuzzerRCC, ENABLE);

    /* GPIO初始化 */
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = BuzzerPIN;			// 将BuzzerPIN引脚初始化为推挽输出
    GPIO_Init(BuzzerIO, &GPIO_InitStructure);

    /* 设置GPIO初始化后的默认电平 */
//    if(!BuzzerMode)
//        GPIO_SetBits(BuzzerIO, BuzzerPIN);			// 设置PB12引脚为高电平
//    else
//        GPIO_ResetBits(BuzzerIO, BuzzerPIN);		// 设置PB12引脚为低电平
    Buzzer_Off();
}

/**
 * 函  数：蜂鸣器开启
 * 参  数：无
 * 返回值：无
 */
void Buzzer_On(void) {
    if(!BuzzerMode)
        GPIO_ResetBits(BuzzerIO, BuzzerPIN);			// 设置PB12引脚为低电平
    else
        GPIO_SetBits(BuzzerIO, BuzzerPIN);				// 设置PB12引脚为高电平
}

/**
 * 函  数：蜂鸣器关闭
 * 参  数：无
 * 返回值：无
 */
void Buzzer_Off(void) {
    if(!BuzzerMode)
        GPIO_SetBits(BuzzerIO, BuzzerPIN);			// 设置PB12引脚为高电平
    else
        GPIO_ResetBits(BuzzerIO, BuzzerPIN);		// 设置PB12引脚为低电平
}

/**
 * 函  数：蜂鸣器状态翻转
 * 参  数：无
 * 返回值：无
 */
void Buzzer_Turn(void) {
    if(GPIO_ReadOutputDataBit(BuzzerIO, BuzzerPIN) == 0) // 获取输出寄存器的状态，如果当前引脚输出低电平
        GPIO_SetBits(BuzzerIO, BuzzerPIN);			// 设置PB12引脚为高电平
    else			// 否则，即当前引脚输出高电平
        GPIO_ResetBits(BuzzerIO, BuzzerPIN);		// 设置PB12引脚为低电平
}
