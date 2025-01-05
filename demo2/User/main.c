#include "public.h"

int main(void)
{
	/*模块初始化*/
	Key_Init();
	LED_Init();
	OLED_Init();		//OLED初始化
	
	char String[] = "Now: ";
	char state[] = "Init";
	/*显示静态字符串*/
	OLED_ShowString(1, 1, String);
	OLED_ShowString(1, 6, state);
	
	/*串口初始化*/
	Serial_Init();		//串口初始化
	
	while (1)
	{
//		while(0) {
//			if (Serial_GetRxFlag() == 1)			//检查串口接收数据的标志位
//			{
//				RxData = Serial_GetRxData();		//获取串口接收的数据
//				Serial_SendByte(RxData);			//串口将收到的数据回传回去，用于测试
//				OLED_ShowHexNum(1, 8, RxData, 2);	//显示串口接收的数据
//			}
//		}
		KeyNum = Key_GetNum();		//获取按键键码
		
		if (KeyNum == 1)			//按键1按下
		{
			LED1_Turn();			//LED1翻转
			Num = 2;
			OLED_ShowString(1, 6, "    ");
			OLED_ShowNum(1, 6, Num, 1);
		}
		
		if (KeyNum == 2)			//按键2按下
		{
			LED2_Turn();			//LED2翻转
			Num++;
			OLED_ShowString(1, 6, "    ");
			OLED_ShowNum(1, 6, Num, 1);
		}
	}
}
