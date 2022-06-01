#ifndef __EVENTS__MANAGER_H__
#define __EVENTS__MANAGER_H__
#include "context.h"
#include <vector>

namespace framework
{
    class manager
    {
        public:
            FRAMEWORK_EXPORT void load_event(const std::string& event_name, std::function<void(context&)> fn);
            FRAMEWORK_EXPORT void load_event(const std::vector<std::string>& event_name, std::function<void(context&)> fn); // appends a list
            FRAMEWORK_EXPORT void remove_event(const std::string& event_name);

            FRAMEWORK_EXPORT bool call_event(const std::string& event_name, context& ctx);
            FRAMEWORK_EXPORT bool call_event(const std::string& event_name, std::function<void(context&)>& fn);

            FRAMEWORK_EXPORT size_t events_size() { return m_events.size(); }
        private:
            std::unordered_map<std::string, std::function<void(context&)>> m_events;
    };
}
#endif // __EVENTS__MANAGER_H__