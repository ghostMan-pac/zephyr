#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/gap.h>
#include <zephyr/logging/log.h>
#include "motor.h"

LOG_MODULE_REGISTER(ble_svc);

#define BT_UUID_MOTOR_SVC_VAL BT_UUID_128_ENCODE(0x12345678, 0x1234, 0x5678, 0x1234, 0x56789abcdef0)
#define BT_UUID_MOTOR_CMD_VAL BT_UUID_128_ENCODE(0x12345678, 0x1234, 0x5678, 0x1234, 0x56789abcdef1)

static struct bt_uuid_128 motor_svc_uuid = BT_UUID_INIT_128(BT_UUID_MOTOR_SVC_VAL);
static struct bt_uuid_128 motor_cmd_uuid = BT_UUID_INIT_128(BT_UUID_MOTOR_CMD_VAL);

static ssize_t write_motor_cmd(struct bt_conn *conn, const struct bt_gatt_attr *attr,
			       const void *buf, uint16_t len, uint16_t offset, uint8_t flags)
{
	if (len != 1) {
		return BT_GATT_ERR(BT_ATT_ERR_INVALID_ATTRIBUTE_LEN);
	}

	uint8_t cmd = ((uint8_t *)buf)[0];
	LOG_INF("Motor cmd: 0x%02X", cmd);

	switch (cmd) {
	case 0x01:
		motor_forward();
		break;
	case 0x02:
		motor_backward();
		break;
	case 0x03:
		motor_turn_left();
		break;
	case 0x04:
		motor_turn_right();
		break;
	default:
		motor_stop();
		break;
	}
	return len;
}

BT_GATT_SERVICE_DEFINE(motor_svc, BT_GATT_PRIMARY_SERVICE(&motor_svc_uuid),
		       BT_GATT_CHARACTERISTIC(&motor_cmd_uuid.uuid, BT_GATT_CHRC_WRITE_WITHOUT_RESP,
					      BT_GATT_PERM_WRITE, NULL, write_motor_cmd, NULL), );

static const struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	BT_DATA(BT_DATA_NAME_COMPLETE, CONFIG_BT_DEVICE_NAME, sizeof(CONFIG_BT_DEVICE_NAME) - 1),
};

static void connected(struct bt_conn *conn, uint8_t err)
{
	if (err) {
		LOG_ERR("Connection failed, err 0x%02X", err);
	} else {
		LOG_INF("Connected");
	}
}

static void disconnected(struct bt_conn *conn, uint8_t reason)
{
	LOG_INF("Disconnected, reason 0x%02X", reason);
	bt_le_adv_start(BT_LE_ADV_CONN_FAST_2, ad, ARRAY_SIZE(ad), NULL, 0);
}

BT_CONN_CB_DEFINE(conn_callbacks) = {
	.connected = connected,
	.disconnected = disconnected,
};

void ble_service_init(void)
{
	int err;

	err = bt_enable(NULL);
	if (err) {
		LOG_ERR("Bluetooth init failed: %d", err);
		return;
	}

	err = bt_le_adv_start(BT_LE_ADV_CONN_FAST_2, ad, ARRAY_SIZE(ad), NULL, 0);
	if (err) {
		LOG_ERR("Advertising failed to start: %d", err);
		return;
	}

	LOG_INF("BLE advertising started as '%s'", CONFIG_BT_DEVICE_NAME);
}
