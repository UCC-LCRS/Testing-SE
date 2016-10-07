#include "unity.h"
#include "bsp.h"
#include "../src/app.h"

extern char leds_out[8];

void test_Sec_Inicial(void) {
	app();
	TEST_ASSERT_MESSAGE(leds_out[0] == 1, "El led 0 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[7] == 0, "El led 7 deberia estar apagado");
	//TEST_IGNORE_MESSAGE("Implement Me");
}

void test_Sec_5s(void) {
	BSP_Init();
	for (int i = 0; i < 5; i++)
		app();
	TEST_ASSERT_MESSAGE(leds_out[0] == 0, "El led 0 deberia estar apagado");
	TEST_ASSERT_MESSAGE(leds_out[7] == 0, "El led 7 deberia estar apagado");
	TEST_ASSERT_MESSAGE(leds_out[1] == 1, "El led 1 deberia estar prendido");
	TEST_ASSERT_MESSAGE(leds_out[6] == 1, "El led 6 deberia estar prendido");
	//TEST_IGNORE_MESSAGE("Implement Me");
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_Sec_Inicial);
	RUN_TEST(test_Sec_5s);
	return UNITY_END();
}
