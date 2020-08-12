#ifndef _NETWORK_NET_H_
#define _NETWORK_NET_H_

#include <stdint.h>

enum
{
    NET_CHANNEL_RF,
    NET_CHANNEL_BLE,
    _NET_CHANNEL_LAST
};
typedef uint8_t net_channel_t;

typedef struct
{
    uint8_t cmd;
    uint8_t *data;
} net_package_t;

typedef void (*net_send_src_t)(uint8_t cmd, uint8_t *data, uint8_t len);
typedef void (*net_recv_cb_t)(net_package_t *package);
typedef void (*net_recv_src_t)(uint8_t *data, uint8_t len);

typedef struct
{
    net_channel_t channel;
    net_send_src_t send_src;
    net_recv_cb_t recv_cb;
    net_recv_src_t recv_src;
} net_config_t;

void net_config(net_config_t *config);
void net_send(uint8_t cmd, uint8_t *data, uint8_t len, net_channel_t channel);

#endif /*_NETWORK_NET_H_*/