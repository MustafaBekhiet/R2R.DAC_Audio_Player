/*
 * NVIC_program.c



 *
 *  Created on: May 28, 2023
 *      Author: Mustafa Mahmoud
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void NVIC_voidEnableIRQ(NVIC_interrupt_ID IRQ_Id){

	if(IRQ_Id <= INT_I2C1_EV)
	{
		NVIC_ISER0 = (1 << IRQ_Id);
	}
	else if (IRQ_Id > INT_I2C1_EV && IRQ_Id <= INT_DMA2_Channel4_5 )
	{
		IRQ_Id -= 32 ;
		NVIC_ISER1 = (1 << IRQ_Id);
	}
	else
	{

	}
}
void NVIC_voidDisableIRQ(NVIC_interrupt_ID IRQ_Id){

	if(IRQ_Id <= INT_I2C1_EV)
	{
		NVIC_ICER0 = 1 << IRQ_Id;
	}
	else if (IRQ_Id > INT_I2C1_EV && IRQ_Id <= INT_DMA2_Channel4_5 )
	{
		IRQ_Id -= 32 ;
		NVIC_ICER1 = 1 << IRQ_Id;
	}
	else
	{

	}
}
void NVIC_voidSetPendingIRQ(NVIC_interrupt_ID IRQ_Id){

	if(IRQ_Id <= INT_I2C1_EV)
	{
		NVIC_ISPR0 = 1 << IRQ_Id;
	}
	else if (IRQ_Id > INT_I2C1_EV && IRQ_Id <= INT_DMA2_Channel4_5 )
	{
		IRQ_Id -= 32 ;
		NVIC_ISPR1 = 1 << IRQ_Id;
	}
	else
	{

	}
}
void NVIC_voidClearPendingIRQ(NVIC_interrupt_ID IRQ_Id){

	if(IRQ_Id <= INT_I2C1_EV)
	{
		NVIC_ICPR0 = 1 << IRQ_Id ;
	}
	else if (IRQ_Id > INT_I2C1_EV && IRQ_Id <= INT_DMA2_Channel4_5 )
	{
		IRQ_Id -= 32 ;
		NVIC_ICPR1 =  1<< IRQ_Id;
	}
	else
	{

	}
}
u8 NVIC_u32GetPendingIRQ(NVIC_interrupt_ID IRQ_Id){
	u8 Boolean = 0;
	if(IRQ_Id <= INT_I2C1_EV)
	{
		Boolean = GET_BIT(NVIC_ICPR0,IRQ_Id);
	}
	else if (IRQ_Id > INT_I2C1_EV && IRQ_Id <= INT_DMA2_Channel4_5 )
	{
		IRQ_Id -= 32 ;
		Boolean = GET_BIT(NVIC_ICPR1,IRQ_Id);
	}
	else
	{

	}
	return Boolean ;
}
u8 NVIC_u32GetActiveIRQ(NVIC_interrupt_ID IRQ_Id){
	u8 Boolean  = 0;
	if(IRQ_Id <= INT_I2C1_EV)
	{
		Boolean = GET_BIT(NVIC_IABR0,IRQ_Id);
	}
	else if (IRQ_Id > INT_I2C1_EV && IRQ_Id <= INT_DMA2_Channel4_5 )
	{
		IRQ_Id -= 32 ;
		Boolean = GET_BIT(NVIC_IABR1,IRQ_Id);
	}
	else
	{

	}
	return Boolean ;
}

void NVIC_voidSetPriorityGrouping(Group_Priority_e priority_grouping){

	#define SCB_AIRCR   (*(volatile u32*)(0xE000E008+0x0C))

	switch(priority_grouping)
	{
	case GROUP_4_SUB_0 : SCB_AIRCR |= NVIC_GROUP_4_SUB_0 ; break;

	case GROUP_3_SUB_1 : SCB_AIRCR |= NVIC_GROUP_3_SUB_1 ; break;

	case GROUP_2_SUB_2 : SCB_AIRCR |= NVIC_GROUP_2_SUB_2 ; break;

	case GROUP_1_SUB_3 : SCB_AIRCR |= NVIC_GROUP_1_SUB_3 ; break;

	case GROUP_0_SUB_4 : SCB_AIRCR |= NVIC_GROUP_0_SUB_4 ; break;
	default : break ;
	}
}
void NVIC_voidSetPriority (NVIC_interrupt_ID IRQ_Id, u8 priority){

	if(IRQ_Id <= INT_DMA2_Channel4_5 )
	{
		NVIC_IPR[IRQ_Id] = priority ;
	}
	else
	{

	}
}
