#define FRAMEWORK_EXPORT __declspec(dllexport)
#ifndef __GTPSFRAMEWORK__PLAYER__PLAYER_H__
#define __GTPSFRAMEWORK__PLAYER__PLAYER_H__
#include <iostream>
#include <vector>
#include <unordered_map>

namespace framework
{
    FRAMEWORK_EXPORT class player
    {
        public:
            player(/*ENetPeer* peer*/);
            ~player();

            FRAMEWORK_EXPORT void set_uid(int id) { this->m_uid = id; }
            FRAMEWORK_EXPORT int get_uid() { return this->m_uid; }

            FRAMEWORK_EXPORT void set_net_id(int id) { this->m_net_id = id; }
            FRAMEWORK_EXPORT int get_net_id() { return this->m_uid; }

            FRAMEWORK_EXPORT void greet(); // TODO: implement greeting (which accepts login)
            FRAMEWORK_EXPORT void content(); // TODO: implement content (which sends cache data, etc.)
        private:
            // ENetPeer* m_peer; // TODO: Add and link ENet
            int m_uid; // Unique ID
            int m_net_id; // Network ID
            int m_hash; // Hash of the player
            int m_platform; // @m_platform is used to make a "special" update link for player
    };
}
#endif // __GTPSFRAMEWORK__PLAYER__PLAYER_H__