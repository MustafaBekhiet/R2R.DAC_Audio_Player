/*
 * GPIO_private.h


 *
 *  Created on: May 27, 2023
 *      Author: Mustafa Mahmoud
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS  0X40010800
#define GPIOB_BASE_ADDRESS  0X40010C00
#define GPIOC_BASE_ADDRESS  0X40011000

#define CRL                 0X00
#define CRH                 0X04
#define IDR                 0X08
#define ODR                 0X0C
#define BSR                 0X10
#define BRR                 0X14
#define LCK                 0X18

/* GPIOA addresses*/
#define GPIOA_CRL           *((volatile u32 *)(GPIOA_BASE_ADDRESS + CRL))
#define GPIOA_CRH           *((volatile u32 *)(GPIOA_BASE_ADDRESS + CRH))
#define GPIOA_IDR           *((volatile u32 *)(GPIOA_BASE_ADDRESS + IDR))
#define GPIOA_ODR           *((volatile u32 *)(GPIOA_BASE_ADDRESS + ODR))
#define GPIOA_BSRR           *((volatile u32 *)(GPIOA_BASE_ADDRESS + BSR))
#define GPIOA_BRR           *((volatile u32 *)(GPIOA_BASE_ADDRESS + BRR))
#define GPIOA_LCK           *((volatile u32 *)(GPIOA_BASE_ADDRESS + LCK))
/* End of GPIOA */

/* GPIOB addresses*/
#define GPIOB_CRL           *((volatile u32 *)(GPIOB_BASE_ADDRESS + CRL))
#define GPIOB_CRH           *((volatile u32 *)(GPIOB_BASE_ADDRESS + CRH))
#define GPIOB_IDR           *((volatile u32 *)(GPIOB_BASE_ADDRESS + IDR))
#define GPIOB_ODR           *((volatile u32 *)(GPIOB_BASE_ADDRESS + ODR))
#define GPIOB_BSRR           *((volatile u32 *)(GPIOB_BASE_ADDRESS + BSR))
#define GPIOB_BRR           *((volatile u32 *)(GPIOB_BASE_ADDRESS + BRR))
#define GPIOB_LCK           *((volatile u32 *)(GPIOB_BASE_ADDRESS + LCK))
/* End of GPIOB */

/* GPIOC addresses*/
#define GPIOC_CRL           *((volatile u32 *)(GPIOC_BASE_ADDRESS + CRL))
#define GPIOC_CRH           *((volatile u32 *)(GPIOC_BASE_ADDRESS + CRH))
#define GPIOC_IDR           *((volatile u32 *)(GPIOC_BASE_ADDRESS + IDR))
#define GPIOC_ODR           *((volatile u32 *)(GPIOC_BASE_ADDRESS + ODR))
#define GPIOC_BSRR           *((volatile u32 *)(GPIOC_BASE_ADDRESS + BSR))
#define GPIOC_BRR           *((volatile u32 *)(GPIOC_BASE_ADDRESS + BRR))
#define GPIOC_LCK           *((volatile u32 *)(GPIOC_BASE_ADDRESS + LCK))
/* End of GPIOC */
#endif /* GPIO_PRIVATE_H_ */
