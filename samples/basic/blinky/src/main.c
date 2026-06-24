#include <zephyr/kernel.h>
#include "motor.h"
#include "ble_service.h"

int main(void)
{
	motor_init();
	ble_service_init();
	/* Everything is interrupt/callback driven from here */
	return 0;
}
