#include <stdint.h>
#include "bsp/bsp.h"
#include "app.h"


uint8_t brightness = 0;

int main(void) {

	BSP_Init();

	while (1)
		app();
}
