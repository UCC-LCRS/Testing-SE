#include "bsp/bsp.h"

int counter = 0;

void APP_1ms(void) {
	static int ms = 0;
	ms++;
	if (ms >= 1000) {
		ms = 0;
		counter++;
	}
}

void app(void) {
	static int flag = 1;
	static int counter_ant = 0;

	if(counter != counter_ant){
		flag =1;
		counter_ant = counter;
	}

	if (counter >= 10)
		counter = 0;

	if (flag) {
		flag = 0;
		switch (counter) {
		case 0:
			BSP_Led_On(0);
			BSP_Led_On(7);
			BSP_Led_Off(2);
			BSP_Led_Off(5);
			BSP_Led_Off(1);
			BSP_Led_Off(6);
			break;
		case 5:
			BSP_Led_On(1);
			BSP_Led_On(6);
			BSP_Led_Off(0);
			BSP_Led_Off(7);
			BSP_Led_Off(2);
			BSP_Led_Off(5);
			break;
		case 6:
			BSP_Led_On(2);
			BSP_Led_On(5);
			BSP_Led_Off(1);
			BSP_Led_Off(6);
			BSP_Led_Off(0);
			BSP_Led_Off(7);
			break;
		}
	}
}
