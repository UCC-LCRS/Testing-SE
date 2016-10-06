#include "stdint.h"


#ifndef BSP_BSP_TEST_H_
#define BSP_BSP_TEST_H_


enum{
	LED_VERDE = 0,
	LED_ROJO,
	LED_NARANJA,
	LED_AZUL
}leds;



void BSP_Init(void);
uint32_t Get_SW_State(void);
void led_setBright(uint8_t led, uint8_t value);
void BSP_ADC_Init(void);
uint8_t BSP_GetBrightness(void);

#endif
