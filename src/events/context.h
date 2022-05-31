#ifndef __GTPSFRAMEWORK__CONTEXT__CONTEXT_H__
#define __GTPSFRAMEWORK__CONTEXT__CONTEXT_H__
#include "player/player.h"
#include "server/server.h"
#include "logger/logger.h"

namespace framework
{
    class context
    {
        public:
            player* m_player;
            server* m_server;
            logger* m_logger;
    }
}
#endif // __GTPSFRAMEWORK__CONTEXT__CONTEXT_H__