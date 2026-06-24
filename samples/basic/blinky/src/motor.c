#include <zephyr/kernel.h>
#include <zephyr/drivers/pwm.h>
#include "motor.h"

/* Adjust these to your actual DTS PWM nodes */
static const struct pwm_dt_spec motor_left = {0};  // PWM_DT_SPEC_GET(DT_ALIAS(motor_left));
static const struct pwm_dt_spec motor_right = {0}; // PWM_DT_SPEC_GET(DT_ALIAS(motor_right));

#define PERIOD_NS 20000000U /* 50 Hz */
#define FULL_FWD  (PERIOD_NS)
#define FULL_REV  0
#define HALF      (PERIOD_NS / 2)

void motor_init(void)
{
	/* PWM devices are ready-checked in main */
}

static void set_motors(uint32_t left_pw, uint32_t right_pw)
{
	pwm_set_dt(&motor_left, PERIOD_NS, left_pw);
	pwm_set_dt(&motor_right, PERIOD_NS, right_pw);
}

void motor_forward(void)
{
	printf("Moving Forward\n");
}
void motor_backward(void)
{
	printf("Moving Back\n");
}
void motor_turn_left(void)
{
	printf("Moving Left\n");
}
void motor_turn_right(void)
{
	printf("Moving Right\n");
}
void motor_stop(void)
{
	printf("Moving Stopped\n");
}
