#include "server.h"
#include <fmt/format.h>

namespace framework
{
    FRAMEWORK_EXPORT server::server(const ENetEvent& event, const std::string& name, const uint16_t& port, const size_t& max_players)
        : m_address({ ENET_HOST_ANY, port }), m_name(name), m_event(event)
    {
        m_address.host = ENET_HOST_ANY;
        m_address.port = port;
        m_logger->log(fmt::format("{} is now open on port {}\n", m_name, m_port));
        m_server = enet_host_create(&m_address, max_players, 2, 0, 0);
        if (!m_server)
        {
            m_logger->log("Failed to initialise ENet!\n", m_logger->log_types::ERR);
            return;
        }
        m_server->checksum = enet_crc32;
        enet_host_compress_with_range_coder(m_server);

        m_logger->log(fmt::format("{} is now open on port {} | version {} ({}) {}\n", m_name, m_port, FRAMEWORK_VERSION, FRAMEWORK_COMMIT, (FRAMEWORK_EXPERIMENTAL ? "Experimental" : "")));
    }

    FRAMEWORK_EXPORT server::~server()
    {
        delete m_server;
        delete m_logger;
    }

    FRAMEWORK_EXPORT void server::add_player(player* p_) 
    { 
        if (p_->m_raw_name.empty() || p_->get_uid() == NULL) return;
        m_players.insert_or_assign(p_->get_uid(), p_); 
    }

    FRAMEWORK_EXPORT void server::broadcast(const std::function<void(player*)>& f_)
    {
        for (auto& p_ : m_players)
            f_(p_.second);
    }
}