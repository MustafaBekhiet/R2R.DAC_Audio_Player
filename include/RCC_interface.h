/*
 * RCC_interface.h

 *
 *  Created on: May 26, 2023
 *      Author: Mustafa Mahmmoud
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

typedef enum{
	System_Bus_AHB =0 ,
	System_Bus_APB1 = 1 ,
	System_Bus_APB2 = 2
}System_Bus_e;


void RCC_voidInitSystemClock();

void RCC_voidEnablePeripheralClock(u8 Copy_u8periheral,
									System_Bus_e Copy_u8Bus);
void RCC_voidDisablePeripheralClock(u8 Copy_u8periheral,
		                           System_Bus_e Copy_u8Bus);





/* CLock Types */
#define RCC_HSI             0
#define RCC_HSE_CRYSTAL     1
#define RCC_HSE_RC          2
#define RCC_PLL             3

//peripheral id bits for AHP
#define DMA1     0
#define DMA2     1
#define SRAM     2
#define FLITF    4
#define CRCE     6
#define FSMC     8
#define SDIO     10

//peripheral id bits for APB2
#define AFIO      0
#define GPIOA     2
#define GPIOB     3
#define GPIOC     4
#define GPIOD     5
#define GPIOE     6
#define GPIOF     7
#define GPIOG     8
#define ADC1      9
#define ADC2      10
#define TIM1      11
#define SPI1      12
#define TIM8      13
#define USART1    14
#define ADC3      15
#define TIM9      19
#define TIM10     20
#define TIM11     21

//periphera id bits for APB1
#define TIM2      0
#define TIM3      1
#define TIM4      2
#define TIM5      3
#define TIM6      4
#define TIM7      5
#define TIM12     6
#define TIM13     7
#define TIM14     8
#define WWD       11
#define SPI2      14
#define SPI3      15
#define USART2    17
#define USART3    18
#define USART4    19
#define USART5    20
#define I2C1      21
#define I2C2      22
#define USB       23
#define CAN       25
#define BKP       27
#define PWR       28
#define DAC       29



#endif /* RCC_INTERFACE_H_ */
