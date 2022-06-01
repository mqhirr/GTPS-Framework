#ifndef __SERVER__RUN_H__
#define __SERVER__RUN_H__

#include "server/server.h"
#include "player/player.h"
#include "events/manager.h"
#include "logger/logger.h"

#include "events/context.h"
#include "events/manager.h"

#include "config/macros.h"
#include "sdk/variant.h"
#include "sdk/packet.h"

#include <fmt/format.h>

#include <thread>

namespace framework
{
    class runner
    {
        public:
            FRAMEWORK_EXPORT runner(server* srv);
            FRAMEWORK_EXPORT ~runner();

            FRAMEWORK_EXPORT void run();

            FRAMEWORK_EXPORT uint32_t get_type(ENetPacket* packet) { return static_cast<uint32_t>(packet->data); }
            FRAMEWORK_EXPORT bool get_str_from_packet(ENetPacket* packet, std::string& str);

        private:
            server* m_server;
            player* m_player;
            logger* m_logger;

            manager* m_manager;
            context* m_context;
    };
}
#endif // __SERVER__RUN_H__