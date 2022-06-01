#include "player.h"

namespace framework
{
    FRAMEWORK_EXPORT player::player(ENetPeer* peer)
    {
        m_peer = peer;
        fmt::print("Player created!\n");
    }
    FRAMEWORK_EXPORT player::player()
    {
        fmt::print("Player created!\n");
    }

    FRAMEWORK_EXPORT void player::greet()
    {
        send_packet(1, nullptr, 0, ENET_PACKET_FLAG_RELIABLE | ENET_PACKET_FLAG_NO_ALLOCATE);
    }

    FRAMEWORK_EXPORT void player::content()
    {
        m_logger->log("Not implemented yet.", m_logger->log_types::WARNING);
    }

    FRAMEWORK_EXPORT void player::send_packet(const void* data, const uintmax_t& data_size, const uint32_t& flags)
    {
        ENetPacket* packet = enet_packet_create(data, data_size, flags);
        if (!packet)
            return;

        if (enet_peer_send(m_peer, 0, packet) != 0)
            enet_packet_destroy(packet);
    }

    FRAMEWORK_EXPORT void player::send_packet(const uint32_t& type, const void* data, const uintmax_t& data_size, const uint32_t& flags)
    {
        ENetPacket* packet = enet_packet_create(nullptr, 5 + data_size, flags);
        if (!packet)
            return;

        memcpy(packet->data, &type, 4);
        packet->data[data_size + 4] = 0;

        if (data)
            memcpy(packet->data + 4, data, data_size);

        if (enet_peer_send(m_peer, 0, packet) != 0)
            enet_packet_destroy(packet);
    }

    FRAMEWORK_EXPORT void player::variant(const variantlist& vlist, int net_id, int delay, uint32_t flags)
    {
        gameupdatepacket_t* packet = vlist.pack();

        packet->m_net_id = net_id;
        packet->m_delay = delay;

        send_packet(4, packet, packet->m_data_size + sizeof(gameupdatepacket_t), flags);
        delete packet;
    }
}