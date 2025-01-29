#ifndef _BUZZER_H
#define _BUZZER_H
#include "stm32f10x.h"                  // Device header

////////////////////////////////////////////
/// ���·���������������Ե��ǣ���Դ������
////////////////////////////////////////////

#define BuzzerIO   GPIOB									// ��������ӦIO��
#define BuzzerPIN  GPIO_Pin_12						// ��������ӦIO��
#define BuzzerRCC  RCC_APB2Periph_GPIOB	  // ��������Ӧʱ����
#define BuzzerMode 0										  // ���͵�ƽ����������Ϊ0
//#define BuzzerMode 1								    // ���ߵ�ƽ����������Ϊ1

void Buzzer_Init(void);
void Buzzer_On(void);
void Buzzer_Off(void);
void Buzzer_Turn(void);

#endif
