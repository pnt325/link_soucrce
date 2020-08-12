#include "net.h"

net_config_t *net_configs[_NET_CHANNEL_LAST];

void net_config(net_config_t *config)
{
    if (config->channel > _NET_CHANNEL_LAST)
    {
        return;
    }

    net_configs[config->channel] = config;
}

void net_send(uint8_t cmd,
              uint8_t *data,
              uint8_t len,
              net_channel_t channel)
{
    if (channel > _NET_CHANNEL_LAST)
    {
        return;
    }

    net_configs[channel]->send_src(cmd, data, len);
}