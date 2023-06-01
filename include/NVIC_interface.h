/*
 * NVIC_interface.h

 *
 *  Created on: May 29, 2023
 *      Author: Mustafa Mahmoud
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

typedef enum{
	GROUP_4_SUB_0 = 0,  // -> 4Bit Group
	GROUP_3_SUB_1 ,     //-> 3 bits 1 sub
	GROUP_2_SUB_2 ,     //-> 2 bit 2 sub
	GROUP_1_SUB_3 ,     //-> 1 bit 3 sub
	GROUP_0_SUB_4 ,     //-> 0 bit 4 sub
}Group_Priority_e;

typedef enum{
	INT_WWDG = 0,
	INT_PVD,
	INT_TAMPER,
	INT_RTC,
	INT_FLASH,
	INT_RCC,
	INT_EXTI0,
	INT_EXTI1,
	INT_EXTI2,
	INT_EXTI3,
	INT_EXTI4,
	INT_DMA1_Channel1,
	INT_DMA1_Channel2,
	INT_DMA1_Channel3,
	INT_DMA1_Channel4,
	INT_DMA1_Channel5,
	INT_DMA1_Channel6,
	INT_DMA1_Channel7,
	INT_ADC1_2,
	INT_USB_HP_CAN_TX,
	INT_USB_LP_CAN_RX0,
	INT_CAN_RX1,
	INT_CAN_SCE,
	INT_EXTI9_5,
	INT_TIM1_BRK,
	INT_TIM1_UP,
	INT_TIM1_TRG_COM,
	INT_TIM1_CC,
	INT_TIM2,
	INT_TIM3,
	INT_TIM4,
	INT_I2C1_EV,
	INT_I2C1_ER,
	INT_I2C2_EV,
	INT_I2C2_ER,
	INT_SPI1,
	INT_SPI2,
	INT_USART1,
	INT_USART2,
	INT_USART3,
	INT_EXTI15_10,
	INT_RTCAlarm,
	INT_USBWakeup,
	INT_TIM8_BRK,
	INT_TIM8_UP,
	INT_TIM8_TRG_COM,
	INT_TIM8_CC,
	INT_ADC3,
	INT_FSMC,
	INT_SDIO,
	INT_TIM5,
	INT_SPI3,
	INT_UART4,
	INT_UART5,
	INT_TIM6,
	INT_TIM7,
	INT_DMA2_Channel1,
	INT_DMA2_Channel2,
	INT_DMA2_Channel3,
	INT_DMA2_Channel4_5 = 59,
}NVIC_interrupt_ID;

void NVIC_voidEnableIRQ(NVIC_interrupt_ID IRQ_Id);
void NVIC_voidDisableIRQ(NVIC_interrupt_ID IRQ_Id);
void NVIC_voidSetPendingIRQ(NVIC_interrupt_ID IRQ_Id);
void NVIC_voidClearPendingIRQ(NVIC_interrupt_ID IRQ_Id);
u8 NVIC_u32GetPendingIRQ(NVIC_interrupt_ID IRQ_Id);
u8 NVIC_u32GetActiveIRQ(NVIC_interrupt_ID IRQ_Id);
void NVIC_voidSetPriorityGrouping(Group_Priority_e priority_grouping);
void NVIC_voidSetPriority (NVIC_interrupt_ID IRQ_Id, u8 priority);

#endif /* NVIC_INTERFACE_H_ */
