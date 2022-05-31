#ifndef __GTPSFRAMEWORK__SERVER__SERVER_H__
#define __GTPSFRAMEWORK__SERVER__SERVER_H__
#include <iostream>
#include <vector>
#include <unordered_map>

#include "logger/logger.h"
#include "config/macros.h"

#include <enet/enet.h>

namespace framework
{
    class server
    {
        public:
            FRAMEWORK_EXPORT server(const std::string& name, const uint16_t& port, const size_t& max_players);
            FRAMEWORK_EXPORT ~server();

        private:
            /* Special Values */
            int m_sid; // Server identifier
            std::string m_name; // Server name

            /* Logger */
            logger* m_logger; // Logger value

            /* ENet Values */
            ENetHost* m_server; // ENetHost
            ENetAddress m_address; // ENetAddress
            uint16_t m_port; // Server port
            size_t m_max_players; // Max players
    };
}
#endif // __GTPSFRAMEWORK__SERVER__SERVER_H__