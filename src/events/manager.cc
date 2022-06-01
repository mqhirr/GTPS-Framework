#include "manager.h"
#include <fstream>
#include <string>
using namespace std;

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

    FRAMEWORK_EXPORT bool manager::call_event(const std::string& event_name, std::function<void(context&)>& fn)
    {
        if (auto it = m_events.find(event_name); it != m_events.end())
        {
            fn = it->second;
            return true;
        }

        return false;
    }
    int GetMessageTypeFromPacket(ENetPacket* packet)
    {
        int result;
        if (packet->dataLength > 3u)
        {
            result = *(packet->data);
        }
        else
        {
            cout << "Bad packet length, ignoring message" << endl;
            result = 0;
        }
        return result;
    }
    FRAMEWORK_EXPORT char* manager::GetTextPointerFromPacket(ENetPacket* packet) {
        char zero = 0;
        memcpy(packet->data + packet->dataLength - 1, &zero, 1);
        return (char*)(packet->data + 4);
    }
    //If you use this you should make a thread
    FRAMEWORK_EXPORT void manager::getAction(ENetEvent m_event) {
        switch(m_event.type) {
            int messageType = GetMessageTypeFromPacket(event.packet);
            switch(messageType) {
                while(true) {
                    std::string cch = manager::GetTextPointerFromPacket(m_event.packet)
                    // Halledin Su cchleri yemek yiyecegim


                }
            }


        }
    }
}