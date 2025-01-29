#ifndef _BUZZER_H
#define _BUZZER_H
#include "stm32f10x.h"                  // Device header

////////////////////////////////////////////
/// 以下蜂鸣器驱动函数针对的是：有源蜂鸣器
////////////////////////////////////////////

#define BuzzerIO   GPIOB									// 蜂鸣器对应IO口
#define BuzzerPIN  GPIO_Pin_12						// 蜂鸣器对应IO口
#define BuzzerRCC  RCC_APB2Periph_GPIOB	  // 蜂鸣器对应时钟线
#define BuzzerMode 0										  // 若低电平触发，设置为0
//#define BuzzerMode 1								    // 若高电平触发，设置为1

void Buzzer_Init(void);
void Buzzer_On(void);
void Buzzer_Off(void);
void Buzzer_Turn(void);

#endif
