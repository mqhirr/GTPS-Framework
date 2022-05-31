#include "logger.h"

namespace framework
{
    void logger::log(std::string message, log_types type)
    {
        std::string type_string = "";
        switch(type)
        {
            case log_types::INFO:
                type_string.append("[INFO]");
                break;
            case log_types::WARNING:
                type_string.append("[WARNING]");
                break;
            case log_types::ERROR:
                type_string.append("[ERROR]");
                break;
            case log_types::DEBUG:
                type_string.append("[DEBUG]");
                break;
            default:
                type_string.append("[UNKNOWN]");
                break;
        }
        fmt::print("{} > {}\n", type_string, message);
    }
}