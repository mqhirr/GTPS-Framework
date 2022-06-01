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
                        m_logger->log(fmt::format("A new client connected from {}\n", m_server->get_event().peer->address.host));
                        pl->greet();
                        pl->variant(variantlist{"OnConsoleMessage", "Welcome to the server!"});
                        break;
                    }
                    case ENET_EVENT_TYPE_RECEIVE:
                        m_logger->log(fmt::format("Got packet {}\n", m_server->get_event().packet->data));
                        break;
                    case ENET_EVENT_TYPE_DISCONNECT:
                        m_logger->log(fmt::format("A client disconnected from {}\n", m_server->get_event().peer->address.host));
                        break;
                    case ENET_EVENT_TYPE_NONE:
                        break;
                }
            }
        });
        t.detach(); // run as deamon
    }
}