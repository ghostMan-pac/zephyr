/*
 * Copyright (c) 2016 Intel Corporation
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file Sample app to demonstrate PWM.
 */

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/misc/mchp_evsys/mchp_evsys_g1.h>

#define SW0_NODE DT_ALIAS(sw0)

static const struct pwm_dt_spec pwm_led0 = PWM_DT_SPEC_GET(DT_ALIAS(pwm_led0));
const struct device *evsys_dev = DEVICE_DT_GET(DT_ALIAS(evsys0));
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0});

#define MIN_PERIOD PWM_SEC(1U) / 128U
#define MAX_PERIOD PWM_SEC(1U)

int main(void)
{
	uint32_t max_period;
	uint32_t period;
	uint8_t dir = 0U;
	int ret;

	if (!gpio_is_ready_dt(&button)) {
		printk("Error: button device %s is not ready\n", button.port->name);
		return 0;
	}

	ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n", ret, button.port->name,
		       button.pin);
		return 0;
	}

	ret = gpio_pin_interrupt_configure_dt(&button, GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n", ret,
		       button.port->name, button.pin);
		return 0;
	}

	printk("PWM-based blinky\n");

	if (!pwm_is_ready_dt(&pwm_led0)) {
		printk("Error: PWM device %s is not ready\n", pwm_led0.dev->name);
		return 0;
	}

	/*
	 * In case the default MAX_PERIOD value cannot be set for
	 * some PWM hardware, decrease its value until it can.
	 *
	 * Keep its value at least MIN_PERIOD * 4 to make sure
	 * the sample changes frequency at least once.
	 */
	printk("Calibrating for channel %d...\n", pwm_led0.channel);
	max_period = MAX_PERIOD;
	while (pwm_set_dt(&pwm_led0, max_period, max_period / 2U)) {
		max_period /= 2U;
		if (max_period < (4U * MIN_PERIOD)) {
			printk("Error: PWM device "
			       "does not support a period at least %lu\n",
			       4U * MIN_PERIOD);
			return 0;
		}
	}

	printk("Done calibrating; maximum/minimum periods %u/%lu nsec\n", max_period, MIN_PERIOD);

	period = max_period;
	ret = pwm_set_dt(&pwm_led0, period, period / 4U);
	if (ret) {
		printk("Error %d: failed to set pulse width\n", ret);
		return 0;
	}
	uint8_t channel_num = 1; // channel number should be requested in pilkaalam
	evsys_mchp_connect_user_to_channel(evsys_dev, channel_num, EVSYS_MCHP_EVUSER_TC1_EVU);
	evsys_mchp_connect_channel_to_evgen(evsys_dev, channel_num, EVSYS_MCHP_EVGEN_EIC_EXTINT4);

	while (1) {
		printk("Using period %d\n", period);
		k_sleep(K_SECONDS(4U));
	}
	return 0;
}
