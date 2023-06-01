/*
 * NVIC_private.h

 *
 *  Created on: May 29, 2023
 *      Author: Mustafa Mahmoud
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS  0xE000E100

#define NVIC_ISER0       (*(volatile u32*)(NVIC_BASE_ADDRESS + 0x000))
#define NVIC_ISER1       (*(volatile u32*)(NVIC_BASE_ADDRESS + 0x004))

#define NVIC_ICER0       (*(volatile u32*)(NVIC_BASE_ADDRESS + 0x080))
#define NVIC_ICER1       (*(volatile u32*)(NVIC_BASE_ADDRESS + 0x084))

#define NVIC_ISPR0       (*(volatile u32*)(NVIC_BASE_ADDRESS + 0x100))
#define NVIC_ISPR1       (*(volatile u32*)(NVIC_BASE_ADDRESS + 0x104))

#define NVIC_ICPR0       (*(volatile u32*)(NVIC_BASE_ADDRESS + 0x180))
#define NVIC_ICPR1       (*(volatile u32*)(NVIC_BASE_ADDRESS + 0x184))

#define NVIC_IABR0       (*(volatile u32*)(NVIC_BASE_ADDRESS + 0x200))
#define NVIC_IABR1       (*(volatile u32*)(NVIC_BASE_ADDRESS + 0x204))

#define NVIC_IPR         ( (volatile  u8* const)(NVIC_BASE_ADDRESS + 0x300))



#define NVIC_GROUP_4_SUB_0  0x05FA0300
#define NVIC_GROUP_3_SUB_1  0x05FA0400
#define NVIC_GROUP_2_SUB_2  0x05FA0500
#define NVIC_GROUP_1_SUB_3  0x05FA0600
#define NVIC_GROUP_0_SUB_4  0x05FA0700


#endif /* NVIC_PRIVATE_H_ */
