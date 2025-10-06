/*
 * Copyright (c) 2018 PHYTEC Messtechnik GmbH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/display/cfb.h>
#include <stdio.h>
#include <zephyr/drivers/gpio.h>

typedef enum{
	CMD_TYPE_1 = 0,
	CMD_TYPE_2,
	CMD_TYPE_3,
	CMD_TYPE_4,
	CMD_TYPE_MAX,
} cmd_type_t;

typedef enum{
	RET_FAILED=-1,
	RET_SUCCESS=0,
} ret_type_t;

static int get_the_status(uint8_t msg_type, char* status){
	int ret_status = RET_FAILED;
	int len = 0;
	switch (msg_type) {
		case 0:
			sprintf(status, "Available");
			break;
		case 1:
			sprintf(status, "Do Not Disturb");
			break;
		case 2:
			sprintf(status, "Gone 4 Coffee");
			break;
		case 3:
			sprintf(status, "In a Meeting");
			break;
		case 4:
			sprintf(status, "Out of Office");
			break;
		default:
			ret_status = RET_FAILED;
			break;
	}
	return ret_status;
}
	volatile uint8_t cmd_type = 0;
	volatile bool update_enable = true;

#define SW0_NODE DT_ALIAS(sw0)
	static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios, {0});
	void button_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
	{
		printk("Button pressed at %" PRIu32 "\n", k_cycle_get_32());
		cmd_type++;
	
		update_enable = true;
}
static struct gpio_callback button_cb_data;

int main(void)
{
	const struct device *dev;
	uint16_t x_res;
	uint16_t y_res;
	uint16_t rows;
	uint8_t ppt;
	uint8_t font_width;
	uint8_t font_height;

	dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(dev)) {
		printf("Device %s not ready\n", dev->name);
		return 0;
	}
	
	if (!gpio_is_ready_dt(&button)) {
		printk("Error: button device %s is not ready\n",
		       button.port->name);
		return 0;
	}

	int ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (ret != 0) {
		printk("Error %d: failed to configure %s pin %d\n",
		       ret, button.port->name, button.pin);
		return 0;
	}

	ret = gpio_pin_interrupt_configure_dt(&button,
					      GPIO_INT_EDGE_TO_ACTIVE);
	if (ret != 0) {
		printk("Error %d: failed to configure interrupt on %s pin %d\n",
			ret, button.port->name, button.pin);
		return 0;
	}

	gpio_init_callback(&button_cb_data, button_pressed, BIT(button.pin));
	gpio_add_callback(button.port, &button_cb_data);


	if (display_set_pixel_format(dev, PIXEL_FORMAT_MONO10) != 0) {
		if (display_set_pixel_format(dev, PIXEL_FORMAT_MONO01) != 0) {
			printf("Failed to set required pixel format");
			return 0;
		}
	}

	printf("Initialized %s\n", dev->name);

	if (cfb_framebuffer_init(dev)) {
		printf("Framebuffer initialization failed!\n");
		return 0;
	}

	cfb_framebuffer_clear(dev, true);

	display_blanking_off(dev);

	x_res = cfb_get_display_parameter(dev, CFB_DISPLAY_WIDTH);
	y_res = cfb_get_display_parameter(dev, CFB_DISPLAY_HEIGHT);
	rows = cfb_get_display_parameter(dev, CFB_DISPLAY_ROWS);
	ppt = cfb_get_display_parameter(dev, CFB_DISPLAY_PPT);

	for (int idx = 0; idx < 42; idx++) {
		if (cfb_get_font_size(dev, idx, &font_width, &font_height)) {
			break;
		}
		cfb_framebuffer_set_font(dev, idx);
		printf("font width %d, font height %d\n",
	 font_width, font_height);
	}

	printf("x_res %d, y_res %d, ppt %d, rows %d, cols %d\n",
	x_res,
	y_res,
	ppt,
	rows,
	cfb_get_display_parameter(dev, CFB_DISPLAY_COLS));

	cfb_framebuffer_invert(dev);

	cfb_set_kerning(dev, 3);
	// used to denote the different types of message type
	
	char *status = (char *)k_calloc(50, 1);
	while (1) {
		if(update_enable == true){
			/*find the status that is to be printed as per the cmd_type*/
			cfb_framebuffer_set_font(dev, 1);

			get_the_status(cmd_type, status);

			cfb_framebuffer_clear(dev, false);
			if (cfb_print(dev, status, 0, 45)) {
				printf("Failed to print a string\n");
			}
			cfb_framebuffer_finalize(dev);
				
			if(cmd_type>CMD_TYPE_MAX){

			cmd_type = 0;
		}
			update_enable = false;
		}
	}
	return 0;
}
