#include "manager.h"

namespace framework
{
    FRAMEWORK_EXPORT void manager::load_event(const std::string& event_name, std::function<void(context&)> fn)
    {
        m_events.insert_or_assign(event_name, fn);
    }

    FRAMEWORK_EXPORT void manager::load_event(const std::vector<std::string>& event_name, std::function<void(context&)> fn)
    {
        for (auto& name : event_name)
            m_events.insert_or_assign(name, fn);
    }

    FRAMEWORK_EXPORT void manager::remove_event(const std::string& event_name)
    {
        m_events.erase(event_name);
    }

    FRAMEWORK_EXPORT bool manager::call_event(const std::string& event_name, context& ctx)
    {
        if (auto it = m_events.find(event_name); it != m_events.end())
        {
            it->second(ctx);
            return true;
        }

        return false;
    }

    FRAMEWORK_EXPORT bool manager::call_event(const std::string& event_name, const std::function<void(context&)>& fn)
    {
        if (auto it = m_events.find(event_name); it != m_events.end())
        {
            fn = it->second;
            return true;
        }

        return false;
    }
}