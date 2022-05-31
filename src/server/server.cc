#include "server.h"

namespace framework
{
    server::server(const std::string& name, const uint16_t& port, const size_t& max_players)
        : m_address.host(ENET_HOST_ANY), m_address.port(port), m_name(name)
    {
        m_logger->log("Initialised server!\n");
    }
}