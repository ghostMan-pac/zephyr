/*
 * Copyright (c) 2025-2026 Microchip Technology Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Devicetree GPIO flag definitions for Microchip PORT (G1).
 *
 * Provides Microchip-specific GPIO DT flags used in addition to standard Zephyr
 * GPIO binding flags.
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_GPIO_MICROCHIP_PORT_G1_GPIO_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_GPIO_MICROCHIP_PORT_G1_GPIO_H_

/**
 * @def MCHP_GPIO_DEBOUNCE
 * @brief Enable hardware debouncing for a GPIO pin.
 *
 * Zephyr-specific devicetree flag for Microchip SoCs. When set in GPIO DT flags, the
 * driver enables the SoC's debounce feature for the configured pin/interrupt line.
 */
#define MCHP_GPIO_DEBOUNCE (1U << 8)

/**
 * @def MCHP_GPIO_EVGEN_ENABLE
 * @brief Enable the gpio to generate event
 *
 * Zephyr-specific devicetree flag for Microchip SoCs. When set in GPIO DT flags, the
 * driver enables the pin to be an event generator.
 */
#define MCHP_GPIO_EVGEN_ENABLE (1U << 7)
// todo: could mask these bits with the kconfig symbol
/*these flags are to be used when the pin is to be used in user mode. it chooses what action happens
 * when an event is received
 */
#define MCHP_GPIO_SET_ON_EVENT (1U << 6)
#define MCHP_GPIO_OUT_ON_EVENT (1U << 5)
#define MCHP_GPIO_CLR_ON_EVENT (1U << 4)
#define MCHP_GPIO_TGL_ON_EVENT (1U << 3)

#endif /* INCLUDE_ZEPHYR_DT_BINDINGS_GPIO_MICROCHIP_PORT_G1_GPIO_H_ */
