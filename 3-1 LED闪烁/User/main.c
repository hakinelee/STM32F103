#include "public.h"                  // Device header

int main(void) {
    // 1.开启GPIOA外设时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 3.定义GPIO Init结构体
    GPIO_InitTypeDef GPIO_InitStructure;

    // 4.配置GPIO参数
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;					// GPIO引脚
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	// 引脚的速度
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	// 引脚的工作模式

    // 2.初始化GPIO
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    while(1) {
        GPIO_ResetBits(GPIOA, GPIO_Pin_0);
        Delay_s(1);
        GPIO_SetBits(GPIOA, GPIO_Pin_0);
        Delay_s(1);
    }
}
