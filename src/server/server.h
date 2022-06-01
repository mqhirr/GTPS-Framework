#ifndef __SERVER__SERVER_H__
#define __SERVER__SERVER_H__
#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

#include "config/macros.h"
#include "config/config.h"

#include "logger/logger.h"
#include "player/player.h"

#include <enet/enet.h>


namespace framework
{
    class server
    {
        public:
            FRAMEWORK_EXPORT server(const ENetEvent& event, const std::string& name, const uint16_t& port, const size_t& max_players);
            FRAMEWORK_EXPORT ~server();

            FRAMEWORK_EXPORT void add_player(player* p_);
            FRAMEWORK_EXPORT void broadcast(const std::function<void(player*)>& f_);

            FRAMEWORK_EXPORT ENetHost* get_host() { return m_server; }
            FRAMEWORK_EXPORT ENetEvent get_event() { return m_event; }

            FRAMEWORK_EXPORT uint16_t get_port() { return m_port; }
            FRAMEWORK_EXPORT std::string get_name() { return m_name; }

            FRAMEWORK_EXPORT size_t get_max_players() { return m_max_players; }
            FRAMEWORK_EXPORT size_t get_players() { return m_players.size(); }

            FRAMEWORK_EXPORT int service(uint32_t timeout) { return enet_host_service(m_server, &m_event, timeout); }
        
        private:

            /* Special Values */
            ENetEvent m_event; 
            int m_sid; // Server identifier
            std::string m_name; // Server name
            std::unordered_map<int, player*> m_players; // Player map

            /* Logger */
            logger* m_logger; // Logger value

            /* ENet Values */
            ENetHost* m_server; // ENetHost
            ENetAddress m_address; // ENetAddress
            // ENetEvent
            uint16_t m_port; // Server port
            size_t m_max_players; // Max players
    };
}
#endif // __SERVER__SERVER_H__