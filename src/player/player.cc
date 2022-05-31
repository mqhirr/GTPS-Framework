#include "player.h"

namespace framework
{
    player::player(ENetPeer* peer)
    {
        this->m_peer = peer;
        fmt::print("Player created!\n");
    }
}