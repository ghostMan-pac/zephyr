/*
 * Copyright (c) 2026, Muhammed Asif P
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/pinctrl.h>
#include <zephyr/drivers/clock_control.h>
#include <zephyr/drivers/clock_control/mchp_clock_control.h>

#define DT_DRV_COMPAT microchip_evsys_g1

LOG_MODULE_REGISTER(mchp_evsys_g1, CONFIG_MCHP_EVSYS_LOG_LEVEL);

struct evsys_mchp_clock {
	const struct device *clk_dev;
	clock_control_subsys_t clk_mclk;
	clock_control_subsys_t clk_gclk[EVSYS_SYNCH_NUM];
};

struct evsys_mchp_config {
	evsys_registers_t *regs;
	struct evsys_mchp_clock evsys_clock;
	void (*irq_config_func)(const struct device *dev);
	// 	void (*irq_enable_func)(void);
	// 	void (*irq_disable_func)(void);
};

struct evsys_mchp_data {
	struct k_mutex lock;
};

static void evsys_mchp_isr(const struct device *dev)
{
	const struct evsys_mchp_config *config = dev->config;
	struct evsys_mchp_data *data = dev->data;
}

static int evsys_mchp_init(const struct device *dev)
{
	const struct evsys_mchp_config *config = dev->config;
	struct evsys_mchp_data *data = dev->data;
	evsys_registers_t *regs = config->regs;
	int ret_val;

	k_mutex_init(&data->lock);
	/* turn on the mclk*/
	ret_val = clock_control_on(config->evsys_clock.clk_dev, (config->evsys_clock.clk_mclk));
	LOG_ERR("mclock on retval = %d", ret_val);
	/* turn on all the gclock. could decide later on whether to turn on only if required by
	 * respective peripherals*/
	for (int i = 0; i < EVSYS_SYNCH_NUM; i++) {
		ret_val = clock_control_on(config->evsys_clock.clk_dev,
					   (config->evsys_clock.clk_gclk[i]));
		LOG_ERR("gclock[%d] on retval = %d", i, ret_val);
	}
	// need to remove if not working.this guy is supposed to be
	// called only after disabling all other event generators
	regs->EVSYS_CTRLA = EVSYS_CTRLA_SWRST_Msk;
	config->irq_config_func(dev);

	return 0;
}

int evsys_mchp_request_channel(const struct device *dev, uint8_t *channel_num)
{
	/* Request for channel. and provide the non-assigned channels to the requestor
	 * If no channel available return -EBUSY*/
	LOG_ERR("called %s", __func__);

	channel_num = 0;
	return 0;
}

/* connect channel to generator */
int evsys_mchp_connect_channel_to_evgen(const struct device *dev, uint8_t channel_num, int ev_gen)
{
	const struct evsys_mchp_config *config = dev->config;
	evsys_registers_t *regs = config->regs;

	regs->CHANNEL[channel_num].EVSYS_CHANNEL =
		EVSYS_CHANNEL_EVGEN(ev_gen) |
		EVSYS_CHANNEL_PATH(EVSYS_CHANNEL_PATH_ASYNCHRONOUS_Val) |
		EVSYS_CHANNEL_EDGSEL(EVSYS_CHANNEL_EDGSEL_NO_EVT_OUTPUT_Val);

	LOG_ERR("called %s", __func__);
	// check whether channel busy?
	// check whether event generator connected?
	// connect evgen to channel
}

/* connect channel to users*/
int evsys_mchp_connect_user_to_channel(const struct device *dev, uint8_t channel_num,
				       int user_offset)
{
	const struct evsys_mchp_config *config = dev->config;
	evsys_registers_t *regs = config->regs;
	int user_idx;

	/* reverse calculated based on the register offset from the datasheet */
	user_idx = (user_offset - EVSYS_USER_REG_OFST) / 4;
	LOG_ERR("called %s user_idx = %d", __func__, user_idx);
	if (user_idx < 66) {
		regs->EVSYS_USER[user_idx] = EVSYS_USER_CHANNEL(channel_num + 1);
	} else {
		return -EINVAL;
	}
	// check whether channel has generator?
	// connect channel number to user
}

// todo: to use listify later
/* clang-format off */
#define EVSYS_MCHP_CLOCK_ASSIGN(n)                                                                 \
	.evsys_clock.clk_dev = DEVICE_DT_GET(DT_NODELABEL(clock)),                                 \
	.evsys_clock.clk_mclk = (void *)(DT_INST_CLOCKS_CELL_BY_NAME(n, mclk_evsys, subsystem)),   \
	.evsys_clock.clk_gclk[0] = (void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys0, subsystem), \
	.evsys_clock.clk_gclk[1] = (void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys1, subsystem), \
	.evsys_clock.clk_gclk[2] = (void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys2, subsystem), \
	.evsys_clock.clk_gclk[3] = (void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys3, subsystem), \
	.evsys_clock.clk_gclk[4] = (void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys4, subsystem), \
	.evsys_clock.clk_gclk[5] = (void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys5, subsystem), \
	.evsys_clock.clk_gclk[6] = (void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys6, subsystem), \
	.evsys_clock.clk_gclk[7] = (void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys7, subsystem), \
	.evsys_clock.clk_gclk[8] = (void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys8, subsystem), \
	.evsys_clock.clk_gclk[9] = (void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys9, subsystem), \
	.evsys_clock.clk_gclk[10] =                                                                \
		(void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys10, subsystem),                   \
	.evsys_clock.clk_gclk[11] =                                                                \
		(void *)DT_INST_CLOCKS_CELL_BY_NAME(n, gclk_evsys11, subsystem),

#define EVSYS_MCHP_INIT(n)                                                                         \
	static void evsys_mchp_irq_config_func_##n(const struct device *dev);                      \
	static struct evsys_mchp_data evsys_mchp_data_##n = {};                                    \
                                                                                                   \
	static const struct evsys_mchp_config evsys_mchp_config_##n = {                            \
		.regs = (evsys_registers_t *)DT_INST_REG_ADDR(n),                                  \
		EVSYS_MCHP_CLOCK_ASSIGN(n)							   \
		.irq_config_func = evsys_mchp_irq_config_func_##n,      			   \
	};                                                                                         \
                                                                                                   \
	DEVICE_DT_INST_DEFINE(n, &evsys_mchp_init, NULL, &evsys_mchp_data_##n,                    \
			      &evsys_mchp_config_##n, POST_KERNEL,                                \
			      CONFIG_MCHP_EVSYS_INIT_PRIORITY, NULL);                             \
                                                                                                  \
	static void evsys_mchp_irq_config_func_##n(const struct device *dev)                      \
	{                                                                                         \
		IRQ_CONNECT(DT_INST_IRQN(n), DT_INST_IRQ(n, priority), evsys_mchp_isr,            \
			    DEVICE_DT_INST_GET(n), 0);                                            \
		irq_enable(DT_INST_IRQN(n));                                                      \
	}                                                                                          
                                                                                                   
	
/* clang-format on*/
DT_INST_FOREACH_STATUS_OKAY(EVSYS_MCHP_INIT)
