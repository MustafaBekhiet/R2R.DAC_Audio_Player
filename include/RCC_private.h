/*
 * RCC_private.h

 *
 *  Created on: May 26, 2023
 *      Author: Mustafa Mahmmoud
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

typedef struct{

	volatile u32  RCC_CR ;     /* Clock control Register */
	volatile u32  RCC_CFGR ;   /* Clock configuration Register */
	volatile u32  RCC_CIR ;
	volatile u32  RCC_APB2RSTR ;
	volatile u32  RCC_APB1RSTR ;
	volatile u32  RCC_AHBENR ;
	volatile u32  RCC_APB2ENR ;
	volatile u32  RCC_APB1ENR ;
	volatile u32  RCC_BDCR ;
	volatile u32  RCC_CSR ;
}Rcc_Register_st;

#define RCC_BASE_ADDRESS    0x40021000
#define RCC_REGISTER   ((volatile Rcc_Register_st * const)RCC_BASE_ADDRESS)


/* RCC_CR Register Bits */
#define PPLRDY 25
#define PLLON  24
#define CSSON  19
#define HSEBYP 18
#define HSERDY 17
#define HSEON  16
#define HSICAL  8
#define HSITRIM 3
#define HSIRDY  1
#define HSION   0
/* End of RCC_CR*/
#if 0
/*RCC_CFGR Register Bits*/
#define SW                            0
#define SWS                           2
#define HPRE                          4
#define PPRE1                         8
#define PPRE2                         11
#define ADCPRE                        14
#define PLLSRC                        16
#define PLLXTPRE                      17
#define PLLMUL                        18
#define USBPRE                        22
#define MCO                           24
/* End of RCC_CFGR*/
#endif



#define HSI_ON            0x00000001U
#define HSE_RC_ON         0x00050000U
#define HSE_CRYSTAL_ON    0x00010000U /* With Bypass*/
#define PLL_ON            0x01000000U

#define  RCC_CFGR_SW_HSI             0x00000000U        /*!< HSI selected as system clock */
#define  RCC_CFGR_SW_HSE             0x00000001U        /*!< HSE selected as system clock */
#define  RCC_CFGR_SW_PLL             0x00000002U          /*!< PLL selected as system clock */



#endif /* RCC_PRIVATE_H_ */
