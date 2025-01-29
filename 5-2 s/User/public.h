#ifndef __PUBLIC_H
#define __PUBLIC_H

#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "Key.h"
#include "LED.h"

uint8_t RxData;			//定义用于接收串口数据的变量
uint8_t KeyNum;		  //定义用于接收按键键码的变量
uint16_t Num;

#endif
