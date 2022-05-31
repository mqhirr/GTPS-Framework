#include "player.h"

namespace framework
{
    player::player(ENetPeer* peer)
    {
        m_peer = peer;
        fmt::print("Player created!\n");
    }
    player::player()
    {
        fmt::print("Player created!\n");
    }

    void player::greet()
    {
        m_logger->log("Not implemented yet.", m_logger->log_types::WARNING);
    }
    void player::content()
    {
        m_logger->log("Not implemented yet.", m_logger->log_types::WARNING);
    }
}