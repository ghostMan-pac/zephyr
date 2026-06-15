/*
 * Copyright (c) 2016 Open-RnD Sp. z o.o.
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/util.h>
#include <zephyr/sys/printk.h>
#include <inttypes.h>

// #define SLEEP_TIME_MS 1

// /*
//  * Get button configuration from the devicetree sw0 alias. This is mandatory.
//  */
// #define SW0_NODE DT_ALIAS(sw1)
// #if !DT_NODE_HAS_STATUS_OKAY(SW0_NODE)
// #error "Unsupported board: sw0 devicetree alias is not defined"
// #endif
// static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(SW0_NODE, gpios);
// #define SW1_NODE DT_ALIAS(sw2)
// #if !DT_NODE_HAS_STATUS_OKAY(SW0_NODE)
// #error "Unsupported board: sw0 devicetree alias is not defined"
// #endif
// static const struct gpio_dt_spec button2 = GPIO_DT_SPEC_GET(SW1_NODE, gpios);

// static struct gpio_callback button_cb_data;

// /*
//  * The led0 devicetree alias is optional. If present, we'll use it
//  * to turn on the LED whenever the button is pressed.
//  */
// static struct gpio_dt_spec led = GPIO_DT_SPEC_GET_OR(DT_ALIAS(led0), gpios, {0});

// void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
// {
// 	// printk("Button pressed at %" PRIu32 "\n", k_cycle_get_32());
// }
#include <zephyr/input/input.h>

static void input_cb(struct input_event *evt, void *user_data)
{
	if (evt->code == INPUT_REL_WHEEL) {
		printk("Encoder: %d\n", evt->value);
	}
}
INPUT_CALLBACK_DEFINE(NULL, input_cb, NULL);

int main(void)
{
	// int ret;

	// if (!gpio_is_ready_dt(&button)) {
	// 	printk("Error: button device %s is not ready\n", button.port->name);
	// 	return 0;
	// }

	// ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
	// if (ret != 0) {
	// 	printk("Error %d: failed to configure %s pin %d\n", ret, button.port->name,
	// 	       button.pin);
	// 	return 0;
	// }

	// ret = gpio_pin_configure_dt(&button2, GPIO_INPUT);
	// if (ret != 0) {
	// 	printk("Error %d: failed to configure %s pin %d\n", ret, button.port->name,
	// 	       button.pin);
	// 	return 0;
	// }
	// int val, val2;
	printk("thodngeekk tta\n");
	while (1) {
		// val = gpio_pin_get_dt(&button);
		// val2 = gpio_pin_get_dt(&button2);
		// printk("%d \n", (val<<1)| val2);
		k_msleep(100);
	}
	return 0;
}
