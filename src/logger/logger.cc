#include "logger.h"

namespace framework
{
    FRAMEWORK_EXPORT void logger::log(std::string message, int type)
    {
        std::string type_string =
            type == log_types::INFO ? "[INFO]" :
            type == log_types::WARNING ? "[WARNING]" :
            type == log_types::ERR ? "[ERROR]" :
            type == log_types::DEBUG ? "[DEBUG]" : "[UNKNOWN]";
        fmt::print("{} -> {}\n", type_string, message);
    }
}