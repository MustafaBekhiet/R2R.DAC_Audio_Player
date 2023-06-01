/*
 * SysTick_interface.h

 *
 *  Created on: May 30, 2023
 *      Author: Mustafa Mahmoud
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_





void STK_voidInit(void);
void STK_voidDelay_ms(u32 Copy_u32value); /* Busy Waiting Function*/
void STK_voidSingleInterval(u32 Copy_u32value, ptrFun  _Func);
void STK_voidPeriodic(u32 Copy_u32value,ptrFun  _Func);
void STK_voidStop(void);
u32 STK_u32GetElapsedTime(void);
u32 STK_u32GetRemainingTime(void);



#endif /* SYSTICK_INTERFACE_H_ */
