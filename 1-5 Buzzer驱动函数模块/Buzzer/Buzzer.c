#include "Buzzer.h"

////////////////////////////////////////////
/// ���·���������������Ե��ǣ���Դ������
////////////////////////////////////////////

/**
 * ��  ������������ʼ��
 * ��  ������
 * ����ֵ����
 */
void Buzzer_Init(void) {
    /* ����ʱ�� */
    RCC_APB2PeriphClockCmd(BuzzerRCC, ENABLE);

    /* GPIO��ʼ�� */
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = BuzzerPIN;			// ��BuzzerPIN���ų�ʼ��Ϊ�������
    GPIO_Init(BuzzerIO, &GPIO_InitStructure);

    /* ����GPIO��ʼ�����Ĭ�ϵ�ƽ */
//    if(!BuzzerMode)
//        GPIO_SetBits(BuzzerIO, BuzzerPIN);			// ����PB12����Ϊ�ߵ�ƽ
//    else
//        GPIO_ResetBits(BuzzerIO, BuzzerPIN);		// ����PB12����Ϊ�͵�ƽ
    Buzzer_Off();
}

/**
 * ��  ��������������
 * ��  ������
 * ����ֵ����
 */
void Buzzer_On(void) {
    if(!BuzzerMode)
        GPIO_ResetBits(BuzzerIO, BuzzerPIN);			// ����PB12����Ϊ�͵�ƽ
    else
        GPIO_SetBits(BuzzerIO, BuzzerPIN);				// ����PB12����Ϊ�ߵ�ƽ
}

/**
 * ��  �����������ر�
 * ��  ������
 * ����ֵ����
 */
void Buzzer_Off(void) {
    if(!BuzzerMode)
        GPIO_SetBits(BuzzerIO, BuzzerPIN);			// ����PB12����Ϊ�ߵ�ƽ
    else
        GPIO_ResetBits(BuzzerIO, BuzzerPIN);		// ����PB12����Ϊ�͵�ƽ
}

/**
 * ��  ����������״̬��ת
 * ��  ������
 * ����ֵ����
 */
void Buzzer_Turn(void) {
    if(GPIO_ReadOutputDataBit(BuzzerIO, BuzzerPIN) == 0) // ��ȡ����Ĵ�����״̬�������ǰ��������͵�ƽ
        GPIO_SetBits(BuzzerIO, BuzzerPIN);			// ����PB12����Ϊ�ߵ�ƽ
    else			// ���򣬼���ǰ��������ߵ�ƽ
        GPIO_ResetBits(BuzzerIO, BuzzerPIN);		// ����PB12����Ϊ�͵�ƽ
}
