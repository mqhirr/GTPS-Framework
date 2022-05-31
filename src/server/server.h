#ifndef __GTPSFRAMEWORK__SERVER__SERVER_H__
#define __GTPSFRAMEWORK__SERVER__SERVER_H__
#include <iostream>
#include <vector>
#include <unordered_map>

#include "logger/logger.h"
#include "macros.h"

#include <enet/enet.h>

namespace framework
{
    FRAMEWORK_EXPORT class server
    {
        public:
            server(const std::string& name, const uint16_t& port, const size_t& max_players);
            ~server();

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