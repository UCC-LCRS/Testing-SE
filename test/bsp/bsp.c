#include "stdint.h"

#ifndef BSP_BSP_TEST_H_
#define BSP_BSP_TEST_H_

enum {
	LED_VERDE = 0, LED_ROJO, LED_NARANJA, LED_AZUL
} leds;

char leds_out[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

void BSP_Led_On(uint8_t led) {
	leds_out[led] = 1;
}

void BSP_Led_Off(uint8_t led) {
	leds_out[led] = 0;
}

void BSP_Init(void) {
	for (int i = 0; i < 8; i++)
		leds_out[8] = 0;
}

#endif
