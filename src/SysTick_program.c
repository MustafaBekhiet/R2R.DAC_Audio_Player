/*
 * SysTick_program.c

 *
 *  Created on: May 30, 2023
 *      Author: Mustafa Mahmoud
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SysTick_interface.h"
#include "SysTick_private.h"
#include "SysTick_config.h"

static ptrFun _CallBack = NULL ;

#define SYS_ENABLE_AHB_DIV_8   0x00000000u
#define SYS_ENABLE_AHB         0x00000004u

#define SINGLE_INTERVAL    0u
#define PERIODIC_INTERVAL  1u

static u8 STK_state = 3   ;

void STK_voidInit(void){

#if STK_SYS_CLK_SRC == STK_AHB_DIV_8

	STK_REGISTER->STK_CTRL = SYS_ENABLE_AHB_DIV_8 ;

#elif STK_SYS_CLK_SRC == STK_AHB
	STK_REGISTER->STK_CTRL = SYS_ENABLE_AHB ;
#endif

}
void STK_voidDelay_ms(u32 Copy_u32value){


	/* Load The Value */
	STK_REGISTER->STK_LOAD = ((1000 * Copy_u32value)-1) ;
	/* Enable SysTick */
	STK_REGISTER->STK_CTRL |= 0x1 ;
	while((GET_BIT(STK_REGISTER->STK_CTRL,STK_COUNT_FLAG)) == 0 );

	/* Disable SysTick */
	STK_REGISTER->STK_CTRL = 0x0 ;

	STK_REGISTER->STK_LOAD = 0 ;
	STK_REGISTER->STK_VAL = 0;


}

void STK_voidSingleInterval(u32 Copy_u32value, ptrFun _Func){

	/* Load The Value */
	STK_REGISTER->STK_LOAD = ((Copy_u32value -1)*1000) ;

	_CallBack = _Func ;
	STK_state = SINGLE_INTERVAL ;
	/* Enable SysTick, Enable Tick INT */
	STK_REGISTER->STK_CTRL |= 0x3 ;

}

void STK_voidPeriodic(u32 Copy_u32value,ptrFun _Func){

	/* Load The Value */

	STK_REGISTER->STK_LOAD = ((Copy_u32value -1)*1000) ;

	_CallBack = _Func ;
	STK_state = PERIODIC_INTERVAL ;
	/* Enable SysTick, Enable Tick INT */
	STK_REGISTER->STK_CTRL |= 0x3 ;
}
void STK_voidStop(void){

	/* Disable SysTick and Interrupt */
	STK_REGISTER->STK_CTRL = 0x0 ;
}
u32 STK_u32GetElapsedTime(void){

	u32 _elapsedTime = 0;

	_elapsedTime = (STK_REGISTER->STK_LOAD) - (STK_REGISTER->STK_VAL) ;

	return _elapsedTime ;
}

u32 STK_u32GetRemainingTime(void){

	u32 _remainingTime = 0 ;

	_remainingTime = STK_REGISTER->STK_VAL ;

	return _remainingTime ;
}


void SysTick_Handler(void)
{
	if( _CallBack != NULL )
	{
		_CallBack();
		if(STK_state == SINGLE_INTERVAL)
		{
			STK_REGISTER -> STK_LOAD =0;
		}

	}

}

