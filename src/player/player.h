#ifndef __PLAYER__PLAYER_H__
#define __PLAYER__PLAYER_H__
#include <iostream>
#include <vector>
#include <unordered_map>

#include <fmt/core.h>
#include <enet/enet.h>

#include "config/macros.h"
#include "logger/logger.h"

#include "sdk/variant.h"
#include "sdk/update.h"

namespace framework
{
    class player
    {
        public:
            FRAMEWORK_EXPORT player(ENetPeer* peer);
            FRAMEWORK_EXPORT player();
            FRAMEWORK_EXPORT ~player();

            FRAMEWORK_EXPORT void set_uid(const int& id) { m_uid = id; }
            FRAMEWORK_EXPORT int get_uid() { return m_uid; }

            FRAMEWORK_EXPORT void set_net_id(const int& id) { m_net_id = id; }
            FRAMEWORK_EXPORT int get_net_id() { return m_net_id; }

            FRAMEWORK_EXPORT void greet(); // TODO: implement greeting (which accepts login)
            FRAMEWORK_EXPORT void content(); // TODO: implement content (which sends cache data, etc.)

            FRAMEWORK_EXPORT void send_packet(const void* data = nullptr, const uintmax_t& data_size = 0, const uint32_t& flags = 0);
            FRAMEWORK_EXPORT void send_packet(const uint32_t& type, const void* data = nullptr, const uintmax_t& data_size = 0, const uint32_t& flags = 0);
            FRAMEWORK_EXPORT void variant(const variantlist& vlist, int net_id = -1, int delay = -1, uint32_t flags = ENET_PACKET_FLAG_RELIABLE);
            
        private:
            /* ENet Value */
            ENetPeer* m_peer; // Peer value

            /* Loggger */
            logger* m_logger; // Logger value

            /* Special Values */
            int m_uid; // Unique ID
            int m_net_id; // Network ID
            int m_hash; // Hash of the player
            int m_platform; // @m_platform is used to make a "special" update link for player.

		public:
            std::string m_raw_name = ""; // The value we get from login info
            std::string m_password = ""; // The value we get from login info #2
            std::string m_display_name = ""; // Used in-game        
    };
}
#endif // __PLAYER__PLAYER_H__