#ifndef __LOGGER__LOGGER_H__
#define __LOGGER__LOGGER_H__
#include <fmt/core.h>

#include "config/macros.h"

namespace framework
{
    class logger
    {
        public:
            enum log_types
            {
                INFO,
                WARNING,
                ERR,
                DEBUG
            };
            FRAMEWORK_EXPORT void log(std::string message, int type = log_types::INFO);
    };
}
#endif // __LOGGER__LOGGER_H__