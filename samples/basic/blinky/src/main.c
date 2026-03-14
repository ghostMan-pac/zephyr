/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/misc/mchp_evsys/mchp_evsys_g1.h>
#include <soc.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS 1000

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)
#define SW0_NODE  DT_ALIAS(sw0)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
const struct device *evsys_dev = DEVICE_DT_GET(DT_ALIAS(evsys0));
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(SW0_NODE, gpios);

int main()
{

	int ret;
	bool led_state = true;

	if (!gpio_is_ready_dt(&button)) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (ret < 0) {
		return 0;
	}
	ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n", ret,
		       button.port->name, button.pin);
		return 0;
	}

	if (!gpio_is_ready_dt(&led)) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

	uint8_t channel_num = 0; // channel number should be requested in pilkaalam
	evsys_mchp_connect_user_to_channel(evsys_dev, channel_num, EVSYS_MCHP_EVUSER_PORT_EV0);
	evsys_mchp_connect_channel_to_evgen(evsys_dev, channel_num, EVSYS_MCHP_EVGEN_EIC_EXTINT15);

	while (1)
		;
	return 0;
}
