/*
 * bsp.h
 *
 *  Created on: 11 de ago. de 2016
 *      Author: LCSR-AF
 */

#ifndef BSP_BSP_H_
#define BSP_BSP_H_

#include "stdint.h"


enum{
	LED_VERDE = 0,
	LED_ROJO,
	LED_NARANJA,
	LED_AZUL
}leds;



void BSP_Init(void);
uint32_t Get_SW_State(void);
void BSP_SetBright(uint8_t led, uint8_t value);
uint8_t BSP_GetBrightness(void);

void BSP_Led_On(uint8_t led);
void BSP_Led_Off(uint8_t led);

#endif /* BSP_BSP_H_ */
