/*
 * Copyright (c) 2026 Muhammed Asif P
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_MISC_MCHP_EVSYS_MCHP_EVSYS_G1_H_
#define ZEPHYR_DRIVERS_MISC_MCHP_EVSYS_MCHP_EVSYS_G1_H_
#include <zephyr/device.h>

#ifdef CONFIG_SOC_FAMILY_MICROCHIP_SAM_D5X_E5X
#include <zephyr/dt-bindings/misc/mchp_evsys_g1_sam_d5x_e5x.h>
#endif /* CONFIG_SOC_FAMILY_MICROCHIP_SAM_D5X_E5X */

int evsys_mchp_request_channel(const struct device *dev, uint8_t *channel_num);
/* This function will connect the provided
 * channel number to the respective event generator provided
 */
int evsys_mchp_connect_channel_to_evgen(const struct device *dev, uint8_t channel_num, int ev_gen);

/* This function will connect the channel to the user provided*/
int evsys_mchp_connect_user_to_channel(const struct device *dev, uint8_t channel_num,
				       int user_offset);

#endif /* ZEPHYR_DRIVERS_MISC_MCHP_EVSYS_MCHP_EVSYS_G1_H_ */
