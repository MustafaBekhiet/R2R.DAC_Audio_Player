/*
 * GPIO_interface.h

 *
 *  Created on: May 27, 2023
 *      Author: Mustafa Mahmoud
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

//For Speed 10
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

//For Speed 2
#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

//For Speed 50
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111

typedef enum{
	PORTA =0,
	PORTB ,
	PORTC ,
}GPIO_PortId_enuT;
typedef enum{
	/* Start of PortA*/
	PIN0 =0,
	PIN1 ,
	PIN2 ,
	PIN3 ,
	PIN4 ,
	PIN5 ,
	PIN6 ,
	PIN7 ,
	PIN8 ,
	PIN9 ,
	PIN10 ,
	PIN11 ,
	PIN12 ,
	PIN13 ,
	PIN14 ,
	PIN15 ,
	/* End of PortA*/
}GPIO_PinId_enuT;

typedef enum{
	GPIO_PIN_RESET = 0u ,
	GPIO_PIN_SET = 1u,
}PinState_enuT;
void GPIO_voidSetPinDirection(GPIO_PortId_enuT Port_Id,GPIO_PinId_enuT Pin_Id
		                                                  , u8 Copy_u8mode);
void GPIO_voidSetPinValue(GPIO_PortId_enuT Port_Id,GPIO_PinId_enuT Pin_Id
		                                      , PinState_enuT PinState);
u8 GPIO_u8ReadPin(GPIO_PortId_enuT Port_Id,GPIO_PinId_enuT Pin_Id);

void GPIO_voidAtmoicSetPinValue(GPIO_PortId_enuT Port_Id,GPIO_PinId_enuT Pin_Id);
void GPIO_voidAtmoicReSetPinValue(GPIO_PortId_enuT Port_Id,GPIO_PinId_enuT Pin_Id);
/*
u8 GPIO_LCKPin(GPIO_PortId_enuT Port_Id,GPIO_PinId_enuT Pin_Id);
*/
#endif /* GPIO_INTERFACE_H_ */
