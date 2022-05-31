#ifndef __GTPSFRAMEWORK__SERVER__SERVER_H__
#define __GTPSFRAMEWORK__SERVER__SERVER_H__
#include <iostream>
#include <vector>
#include <unordered_map>

#include "macros.h"

#include <enet/enet.h>

namespace framework
{
    FRAMEWORK_EXPORT class server
    {
        public:
            server(std::string name, uint16_t port, size_t max_players);
            ~server();

        private:
            ENetHost* m_server;
            ENetAddress m_address;
            /* Special Values */
            int m_sid; // Server identifier
            std::string m_name; // Server name

            /* ENet Values */
            uint16_t m_port; // Server port
            size_t m_max_players; // Max players
    };
}
#endif // __GTPSFRAMEWORK__SERVER__SERVER_H__