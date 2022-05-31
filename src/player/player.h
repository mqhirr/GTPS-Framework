#ifndef __GTPSFRAMEWORK__PLAYER__PLAYER_H__
#define __GTPSFRAMEWORK__PLAYER__PLAYER_H__
#include <iostream>
#include <vector>
#include <unordered_map>

#include <fmt/core.h>
#include <enet/enet.h>

#include "macros.h"
#include "logger/logger.h"

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
        private:
            /* ENet Value */
            ENetPeer* m_peer; // Peer value

            /* Loggger */
            logger* m_logger; // Logger value

            /* Special Values */
            int m_uid; // Unique ID
            int m_net_id; // Network ID
            int m_hash; // Hash of the player
            int m_platform; // @m_platform is used to make a "special" update link for player
    };
}
#endif // __GTPSFRAMEWORK__PLAYER__PLAYER_H__