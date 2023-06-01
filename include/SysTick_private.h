/*
 * SysTick_private.h

 *
 *  Created on: May 30, 2023
 *      Author: Mustafa Mahmoud
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_



#define STK_BASE_ADDRESS  0xE000E010

typedef struct {
	volatile u32 STK_CTRL ;
	volatile u32 STK_LOAD ;
	volatile u32 STK_VAL  ;
	volatile u32 STK_CALIB ;
}STK_t;

#define STK_REGISTER   ((volatile STK_t *)(STK_BASE_ADDRESS))

/* STK_CTRL Bits */
#define STK_ENABLE        0u
#define STK_TICK_INT      1u
#define STK_CLK_SRC       2u
#define STK_COUNT_FLAG    16u
/* End of STK_CTRL Bits */

#define STK_AHB_DIV_8    0u
#define STK_AHB          1u

#endif /* SYSTICK_PRIVATE_H_ */
