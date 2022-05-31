#include "player.h"

namespace framework
{
    FRAMEWORK_EXPORT player::player(ENetPeer* peer)
    {
        m_peer = peer;
        fmt::print("Player created!\n");
    }
    FRAMEWORK_EXPORT player::player()
    {
        fmt::print("Player created!\n");
    }

    FRAMEWORK_EXPORT void player::greet()
    {
        m_logger->log("Not implemented yet.", m_logger->log_types::WARNING);
    }
    FRAMEWORK_EXPORT void player::content()
    {
        m_logger->log("Not implemented yet.", m_logger->log_types::WARNING);
    }
}