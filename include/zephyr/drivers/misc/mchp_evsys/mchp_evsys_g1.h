/*
 * Copyright (c) 2026 Muhammed Asif P
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#ifndef ZEPHYR_DRIVERS_MISC_MCHP_EVSYS_MCHP_EVSYS_G1_H_
#define ZEPHYR_DRIVERS_MISC_MCHP_EVSYS_MCHP_EVSYS_G1_H_

#include <zephyr/device.h>

/* This function will connect the provided 
 * channel number to the respective event generator provided 
 */
int evsys_mchp_connect_channel_to_evgen(int channel_num, int ev_gen);

/* This function will connect the channel to the user provided*/
int evsys_mchp_connect_user_to_channel(int user, int channel);

#endif /* ZEPHYR_DRIVERS_MISC_MCHP_EVSYS_MCHP_EVSYS_G1_H_ */
