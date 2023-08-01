/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Deepanshu Tanwar
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>


int main(void)
{
	uint32_t *pClkCtrlReg = (uint32_t*)0x40023830;
	uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutReg =(uint32_t*)0x40020C14;

	//1. enable the clock for GPIOD peripheral in the AHB1ENR
	*pClkCtrlReg |= (1<<3);

	//2. configure the mode of the IO pin as output
	//a. clear the 24th and 25th bit position (CLEAR)
	*pPortDModeReg &= ~(3<<24);

	//b. make 24th as 1 and 25th bit position as 0 (SET)
	*pPortDModeReg |= (1<<24);

	//3. SET 12th bit of the output data register to make I/O pin-12 as HIGH
	//*pPortDOutReg |= (1<<12);

	while(1)
	{
		*pPortDOutReg |= (1<<12);

		for(int i=0;i<1100000;i++);

		*pPortDOutReg &= ~(1<<12);

		for(int i=0;i<1100000;i++);


	}
}
