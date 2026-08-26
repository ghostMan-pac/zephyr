/*
 * Copyright (c) 2026 Muhammed Asif P
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_MISC_MCHP_EVSYS_MCHP_EVSYS_G1_H_
#define ZEPHYR_DRIVERS_MISC_MCHP_EVSYS_MCHP_EVSYS_G1_H_
#include <zephyr/device.h>
#include <zephyr/dt-bindings/misc/mchp_evsys_g1.h>

int evsys_mchp_request_channel(const struct device *dev, uint8_t *channel_num);
/* This function will connect the provided
 * channel number to the respective event generator provided
 */
int evsys_mchp_connect_channel_to_evgen(const struct device *dev, uint8_t channel_num, int ev_gen);

/* This function will connect the channel to the user provided*/
int evsys_mchp_connect_user_to_channel(const struct device *dev, uint8_t channel_num,
				       int user_offset);

//TODO: add an api for manually triggering an event for a channel

#endif /* ZEPHYR_DRIVERS_MISC_MCHP_EVSYS_MCHP_EVSYS_G1_H_ */
