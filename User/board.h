#ifndef __BOARD_H__
#define __BOARD_H__

#include "stm32h7xx.h"

#include "bsp_led.h"


void rt_hw_board_init(void);
void SysTick_Handler(void);
#endif