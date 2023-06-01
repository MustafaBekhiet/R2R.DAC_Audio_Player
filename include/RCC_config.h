/*
 * RCC_config.h

 *
 *  Created on: May 26, 2023
 *      Author: Mustafa Mahmmoud
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* RCC_HSI = 8 MHZ
 * RCC_HSE_CRYSTAL
 * RCC_HSE_RC
 * RCC_PLL  */

#define SYSCLK_SRC    RCC_HSI

/* PLL CLK Entry Source
 * RCC_PLL_IN_HSI_DIV_BY_2
 * RCC_PLL_IN_HSE */
#if SYSCLK_SRC== RCC_PLL

#define PLLCLK_SRC

#endif

#endif /* RCC_CONFIG_H_ */
