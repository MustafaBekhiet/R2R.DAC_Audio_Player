/*
 * GPIO_program.c

 *
 *  Created on: May 27, 2023
 *      Author: Mustafa Mahmoud
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

#define CLR_MASK  0xF
void GPIO_voidSetPinDirection(GPIO_PortId_enuT Port_Id,GPIO_PinId_enuT Pin_Id
		, u8 Copy_u8mode){

	if(Pin_Id <= PIN7)
	{

		switch(Port_Id)
		{
		case PORTA : GPIOA_CRL &= ~(CLR_MASK <<(Pin_Id * 4));
		GPIOA_CRL |= Copy_u8mode << (Pin_Id * 4);
		break ;
		case PORTB : GPIOB_CRL &= ~(CLR_MASK <<(Pin_Id * 4));
		GPIOB_CRL |= Copy_u8mode << (Pin_Id * 4);
		break ;
		case PORTC :
			GPIOC_CRL &= ~(CLR_MASK <<(Pin_Id * 4));
			GPIOC_CRL |= Copy_u8mode << (Pin_Id * 4);
			break ;
		default :
			break;
		}
	}
	else if ( Pin_Id >= PIN8  && Pin_Id <= PIN15){
		switch(Port_Id)
		{
		case PORTA : GPIOA_CRH &= ~(CLR_MASK <<((Pin_Id-8) * 4));
		GPIOA_CRH |= Copy_u8mode << ((Pin_Id-8) * 4);
		break ;
		case PORTB : GPIOB_CRH &= ~(CLR_MASK <<((Pin_Id-8) * 4));
		GPIOB_CRH |= Copy_u8mode << ((Pin_Id-8)* 4);
		break ;
		case PORTC : GPIOC_CRH &= ~(CLR_MASK <<((Pin_Id-8) * 4));
		GPIOC_CRH |= Copy_u8mode << ((Pin_Id-8)* 4);
		break ;
		default :
			break;
		}
	}
	else
	{

	}
}
void GPIO_voidSetPinValue(GPIO_PortId_enuT Port_Id,GPIO_PinId_enuT Pin_Id
		, PinState_enuT PinState){
	if(Pin_Id <= PIN15)
	{
		if(PinState == GPIO_PIN_SET)
		{
			switch(Port_Id)
			{
			case PORTA : GPIOA_ODR |= PinState << Pin_Id ;
			break ;
			case PORTB : GPIOB_ODR |= PinState << Pin_Id ;
			break ;
			case PORTC : GPIOC_ODR |= PinState << Pin_Id ;
			break ;
			default :
				break;
			}
		}
		else if (PinState == GPIO_PIN_RESET)
		{
			switch(Port_Id)
			{
			case PORTA : CLR_BIT(GPIOA_ODR,Pin_Id) ;
			break ;
			case PORTB : CLR_BIT(GPIOB_ODR,Pin_Id) ;
			break ;
			case PORTC : CLR_BIT(GPIOC_ODR,Pin_Id) ;
			break ;
			default :
				break;
			}
		}

	}
	else
	{

	}

}
u8 GPIO_u8ReadPin(GPIO_PortId_enuT Port_Id,GPIO_PinId_enuT Pin_Id){
	u8 PinState ;
	if(Pin_Id <= PIN15)
	{
		switch(Port_Id)
		{
		case PORTA : PinState = GET_BIT(GPIOA_IDR,Pin_Id);
		break ;
		case PORTB : PinState = GET_BIT(GPIOB_IDR,Pin_Id);
		break ;
		case PORTC : PinState = GET_BIT(GPIOA_IDR,Pin_Id);
		break ;
		default :
			break;
		}
	}
	else
	{

	}
	return PinState ;
}

void GPIO_voidAtmoicSetPinValue(GPIO_PortId_enuT Port_Id,
		GPIO_PinId_enuT Pin_Id){
	if(Pin_Id <= PIN15)
	{
		switch(Port_Id)
		{
		case PORTA : GPIOA_BSRR = (0x1 << Pin_Id) ;

		break ;
		case PORTB : GPIOB_BSRR = (0x1 << Pin_Id) ;

		break ;
		case PORTC : GPIOC_BSRR =  (0x1 << Pin_Id) ;

		break ;
		default :
			break;
		}
	}
	else
	{

	}
}

void GPIO_voidAtmoicReSetPinValue(GPIO_PortId_enuT Port_Id,
		GPIO_PinId_enuT Pin_Id){
	if(Pin_Id <= PIN15)
	{
		switch(Port_Id)
		{
		case PORTA : GPIOA_BRR = (0x1 << Pin_Id) ;

		break ;
		case PORTB : GPIOB_BRR = (0x1 << Pin_Id) ;

		break ;
		case PORTC : GPIOC_BRR = (0x1 << Pin_Id) ;

		break ;
		default :
			break;
		}
	}
	else
	{

	}
}
/*
u8 GPIO_LCKPin(GPIO_PortId_enuT Port_Id,GPIO_PinId_enuT Pin_Id){

	 u8 LCK_value ;
	 u8 LCKD_Pin =0;
	if(Pin_Id <= PIN15)
	{
		switch (Port_Id)
		{
		case PORTA : CLR_BIT(GPIOA_LCK,16);
		SET_BIT(GPIOA_LCK,Pin_Id);

		// Locking key sequence
		SET_BIT(GPIOA_LCK,16);
		CLR_BIT(GPIOA_LCK,16);
		SET_BIT(GPIOA_LCK,16);
		LCK_value=  GET_BIT(GPIOA_LCK,16);
		LCK_value = GET_BIT(GPIOA_LCK,16);

		LCKD_Pin = GET_BIT(GPIOA_LCK,Pin_Id);
		break;
		case PORTB :
			CLR_BIT(GPIOB_LCK,16);
			SET_BIT(GPIOB_LCK,Pin_Id);

			// Locking key sequence
			SET_BIT(GPIOB_LCK,16);
			CLR_BIT(GPIOB_LCK,16);
			SET_BIT(GPIOB_LCK,16);
			LCK_value=  GET_BIT(GPIOB_LCK,16);
			LCK_value = GET_BIT(GPIOB_LCK,16);
			break;
		case PORTC :
			CLR_BIT(GPIOC_LCK,16);
			SET_BIT(GPIOC_LCK,Pin_Id);

			// Locking key sequence
			SET_BIT(GPIOC_LCK,16);
			CLR_BIT(GPIOC_LCK,16);
			SET_BIT(GPIOC_LCK,16);
			LCK_value =  GET_BIT(GPIOC_LCK,16);
			LCK_value = GET_BIT(GPIOC_LCK,16);
			break;
		default :
			break ;
		}
	}
	return LCKD_Pin;
}*/
