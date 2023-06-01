/*
 * RCC_program.c

 *
 *  Created on: May 26, 2023
 *      Author:Mustafa Mahmmoud
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSystemClock(){


#if SYSCLK_SRC == RCC_HSI

	RCC_REGISTER->RCC_CR |= HSI_ON;
	while(GET_BIT(RCC_REGISTER->RCC_CR,HSIRDY) == 0);
	RCC_REGISTER->RCC_CFGR |= RCC_CFGR_SW_HSI;

#endif

#if SYSCLK_SRC == RCC_HSE_CRYSTAL
	/* Enable Clk Security */
	SET_BIT(RCC_REGISTER->RCC_CR,CSSON);
	RCC_REGISTER->RCC_CR |= HSE_CRYSTAL_ON ;
	while(GET_BIT(RCC_REGISTER->RCC_CR,HSERDY) == 0);
	RCC_REGISTER->RCC_CFGR |= RCC_CFGR_SW_HSE;
#endif

#if SYSCLK_SRC == RCC_HSE_RC
	/* Enable Clk Security */
	SET_BIT(RCC_REGISTER->RCC_CR,CSSON);
	RCC_REGISTER->RCC_CR |= HSE_RC_ON ;
	while(GET_BIT(RCC_REGISTER->RCC_CR,HSERDY) == 0);
	RCC_REGISTER->RCC_CFGR |= RCC_CFGR_SW_HSE;
#endif

#if SYSCLK_SRC == RCC_PLL

	while(GET_BIT(RCC_REGISTER->RCC_CR,PPLRDY) == 0);
	RCC_REGISTER->RCC_CFGR |= RCC_CFGR_SW_PLL;
#endif
}

void RCC_voidEnablePeripheralClock(u8 Copy_u8periheral, System_Bus_e Copy_u8Bus){

	if(Copy_u8periheral <= 31)
	{
		switch(Copy_u8Bus)
		{
		case System_Bus_AHB :  SET_BIT(RCC_REGISTER->RCC_AHBENR, Copy_u8periheral); break;
		case System_Bus_APB1:  SET_BIT(RCC_REGISTER->RCC_APB1ENR, Copy_u8periheral); break;
		case System_Bus_APB2:  SET_BIT(RCC_REGISTER->RCC_APB2ENR, Copy_u8periheral); break;
		}
	}
	else
	{

	}

}
void RCC_voidDisablePeripheralClock(u8 Copy_u8periheral, System_Bus_e Copy_u8Bus){
	if(Copy_u8periheral <= 31)
	{
		switch(Copy_u8Bus)
		{
		case System_Bus_AHB :  CLR_BIT(RCC_REGISTER->RCC_AHBENR, Copy_u8periheral); break;
		case System_Bus_APB1:  CLR_BIT(RCC_REGISTER->RCC_APB1ENR, Copy_u8periheral); break;
		case System_Bus_APB2: CLR_BIT(RCC_REGISTER->RCC_APB2ENR, Copy_u8periheral); break;
		}
	}
	else
	{

	}
}

