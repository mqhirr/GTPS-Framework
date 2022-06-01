#include "run.h"

namespace framework
{
    FRAMEWORK_EXPORT runner::runner(server* srv)
    {
        m_server = srv;
        run();
    }

    FRAMEWORK_EXPORT runner::~runner()
    {
        delete m_server;
    }

    FRAMEWORK_EXPORT bool runner::get_str_from_packet(ENetPacket* packet, std::string& str) 
    {
        packet->data[packet->dataLength - 1] = 0;
        str = reinterpret_cast<char*>(packet->data + 4);
        return !(packet->dataLength < 5 || packet->dataLength > 512);
    }

    FRAMEWORK_EXPORT void runner::run()
    {
        m_logger->log(fmt::format("{} is now open on port {} | version {} ({}) {}\n", m_server->get_name(), m_server->get_port(), FRAMEWORK_VERSION, FRAMEWORK_COMMIT, (FRAMEWORK_EXPERIMENTAL ? "Experimental" : "")));
        std::thread t([&]
        {
            while (m_server->service(16))
            {
                switch (m_server->get_event().type)
                {
                    case ENET_EVENT_TYPE_CONNECT:
                    {
                        player* pl = new player(m_server->get_event().peer);
                        m_player = pl;
                        m_logger->log(fmt::format("A new client connected from {}\n", (char*)m_server->get_event().peer->address.host));
                        pl->greet();
                        pl->variant(variantlist{"OnConsoleMessage", "Welcome to the server!"});
                        break;
                    }
                    case ENET_EVENT_TYPE_RECEIVE:
                    {
                        m_logger->log(fmt::format("Got packet {}\n", (char*)m_server->get_event().packet->data));
                        uint32_t type = m_server->get_type(m_server->get_event().packet);
                        switch (type)
                        {
                            case NET_MESSAGE_GENERIC_TEXT:
                            case NET_MESSAGE_GAME_MESSAGE:
                            {
                                std::string str;
                                if (get_str_from_packet(m_server->get_type(m_server->get_event().packet, str))
                                {
                                    m_context.m_player = m_player;
                                    m_context.m_server = m_server;
                                    
                                    std::string event = str.substr(0, str.find('|'));

                                    if (!m_manager->call(m_server->get_event(), m_context))
                                        m_logger->log(fmt::format("Could not find event {}\n", event));
                                }
                                break;
                            }
                            default:
                                m_logger->log(fmt::format("Unhandled packet type {}\n", type));
                                break;
                        }
                        break;
                    }
                    case ENET_EVENT_TYPE_DISCONNECT:
                        m_logger->log(fmt::format("A client disconnected from {}\n", (char*)m_server->get_event().peer->address.host));
                        break;
                    case ENET_EVENT_TYPE_NONE:
                        break;
                }
            }
        });
        t.detach(); // run as deamon
    }
}