/*
 * main.c

 *
 *  Created on: May 26, 2023
 *      Author: Mustafa Mahmmoud
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "GPIO_interface.h"
#include "SysTick_interface.h"
#include "file.h"

void System_Init(void);

void DAC_OUT(void);


int main(void){

	System_Init();
	RCC_voidEnablePeripheralClock(GPIOA,System_Bus_APB2);

	GPIO_voidSetPinDirection(PORTA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA,PIN1,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA,PIN2,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA,PIN3,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA,PIN4,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA,PIN5,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA,PIN6,OUTPUT_SPEED_2MHZ_PP);
	GPIO_voidSetPinDirection(PORTA,PIN7,OUTPUT_SPEED_2MHZ_PP);

	/* Sample every 125 microsecond*/
	STK_voidPeriodic(125,DAC_OUT);

	while(1)
	{


	}
	return 0;
}
void System_Init(void){
	RCC_voidInitSystemClock();
	STK_voidInit();
}
void DAC_OUT(void){
	volatile u16 _iter =0 ;
	u16 _Sample_size =0;
	for(; _iter < 8;_iter++)
	{
		GPIO_voidSetPinValue(PORTA,_iter,GET_BIT(ama_raw[_Sample_size],_iter));
	}
	_Sample_size++;
	if(_Sample_size == 31858)
		_Sample_size =0;
}
