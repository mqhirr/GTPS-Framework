#ifndef __GTPSFRAMEWORK__LOGGER__LOGGER_H__
#define __GTPSFRAMEWORK__LOGGER__LOGGER_H__
#include <fmt/core.h>

#include "macros.h"

namespace framework
{
    FRAMEWORK_EXPORT class logger
    {
        public:
            FRAMEWORK_EXPORT enum log_types
            {
                INFO,
                WARNING,
                ERROR,
                DEBUG
            };
            FRAMEWORK_EXPORT void log(std::string message, int type = log_types::INFO);
    };
}
#endif // __GTPSFRAMEWORK__LOGGER__LOGGER_H__