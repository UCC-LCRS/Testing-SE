#include "unity.h"
#include "bsp/bsp.h"
#include "../src/app.h"
#include <stdio.h>

extern char leds_out[8];
extern int counter;

void test_MS(void) {
	int i;
	TEST_ASSERT_MESSAGE(counter == 0, "El contador no esta en 0");
	APP_1ms();
	TEST_ASSERT_MESSAGE(counter == 0, "El contador no esta en 0 despues de 1");

	for (i = 0; i < 5001; i++) {
		APP_1ms();
	}
	TEST_ASSERT_MESSAGE(counter == 5, "El contador no esta en 5");
	//TEST_IGNORE_MESSAGE("Implement Me");
}
void test_Sec_Inicial(void) {
	BSP_Init();
	counter = 0;
	app();
	TEST_ASSERT_MESSAGE(leds_out[0] == 1, "El led 0 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[1] == 0, "El led 7 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[2] == 0, "El led 0 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[5] == 0, "El led 7 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[6] == 0, "El led 0 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[7] == 1, "El led 7 deberia estar prendido");
	//TEST_IGNORE_MESSAGE("Implement Me");
}

void test_Sec_5s(void) {
	BSP_Init();
	counter = 0;
	int i;
	for (i = 0; i < 5000; i++) {
		APP_1ms();
		app();
	}
	app();
	TEST_ASSERT_MESSAGE(leds_out[0] == 0, "El led 0 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[1] == 1, "El led 7 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[2] == 0, "El led 0 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[5] == 0, "El led 7 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[6] == 1, "El led 0 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[7] == 0, "El led 7 deberia estar prendido");
	//TEST_IGNORE_MESSAGE("Implement Me");
}
void test_Sec_6s(void) {
	BSP_Init();
	counter = 0;
	int i;
	for (i = 0; i <= 6000; i++) {
		APP_1ms();
		app();
	}
	app();
	TEST_ASSERT_MESSAGE(leds_out[0] == 0, "El led 0 deberia estar apagado");
	TEST_ASSERT_MESSAGE(leds_out[1] == 0, "El led 1 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[2] == 1, "El led 2 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[5] == 1, "El led 5 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[6] == 0, "El led 6 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[7] == 0, "El led 7 deberia estar prendido");
	//TEST_IGNORE_MESSAGE("Implement Me");
}
void test_Sec_11s(void) {
	BSP_Init();
	counter = 0;
	int i;
	for (i = 0; i < 11000; i++) {
		APP_1ms();
		app();
	}
	app();
	TEST_ASSERT_MESSAGE(leds_out[0] == 1, "El led 0 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[1] == 0, "El led 7 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[2] == 0, "El led 0 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[5] == 0, "El led 7 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[6] == 0, "El led 0 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[7] == 1, "El led 7 deberia estar prendido");
	//TEST_IGNORE_MESSAGE("Implement Me");
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_MS);
	RUN_TEST(test_Sec_Inicial);
	RUN_TEST(test_Sec_5s);
	RUN_TEST(test_Sec_6s);
	RUN_TEST(test_Sec_11s);
	return UNITY_END();
}
