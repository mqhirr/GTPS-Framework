#ifndef __SERVER__RUN_H__
#define __SERVER__RUN_H__

#include "server/server.h"
#include "player/player.h"
#include "events/manager.h"
#include "logger/logger.h"

#include "config/macros.h"
#include "sdk/variant.h"

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

        private:
            server* m_server;
            logger* m_logger;
    };
}
#endif // __SERVER__RUN_H__