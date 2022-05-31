#include "server.h"
#include <fmt/format.h>

namespace framework
{
    FRAMEWORK_EXPORT server::server(const std::string& name, const uint16_t& port, const size_t& max_players)
        : m_name(name)
    {
        m_address.host = ENET_HOST_ANY;
        m_address.port = port;
        m_logger->log(fmt::format("{} is now open on port {}\n", m_name, m_port));
    }
}