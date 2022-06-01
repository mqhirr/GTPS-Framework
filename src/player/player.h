#ifndef __PLAYER__PLAYER_H__
#define __PLAYER__PLAYER_H__
#include <iostream>
#include <vector>
#include <unordered_map>

#include <fmt/core.h>
#include <enet/enet.h>

#include "config/macros.h"
#include "logger/logger.h"

#include "sdk/variant.h"
#include "sdk/update.h"
#include <vector>
using namespace std;
namespace framework
{
    class player
    {
        public:
            struct PlayerInfo {
                bool isIn = false;
	int netID;
	bool haveGrowId = false;
	string tankIDName = "";
	string tankIDPass = "";
	string requestedName = "";
	string rawName = "";
	string displayName = "";
	string country = "";
	int adminLevel = 0;
	string currentWorld = "EXIT";
	bool radio = true;
	int x;
	int y;
	int x1;
	int y1;
	bool isRotatedLeft = false;
	bool RotatedLeft = false;
	string charIP = "";
	bool isUpdating = false;
	bool joinClothesUpdated = false;

	bool hasLogon = false;

	bool taped = false;

	int cloth_hair = 0; // 0
	int cloth_shirt = 0; // 1
	int cloth_pants = 0; // 2
	int cloth_feet = 0; // 3
	int cloth_face = 0; // 4
	int cloth_hand = 0; // 5
	int cloth_back = 0; // 6
	int cloth_mask = 0; // 7
	int cloth_necklace = 0; // 8
	int cloth_ances = 0; // 9

	bool canWalkInBlocks = false; // 1
	bool canDoubleJump = false; // 2
	bool isInvisible = false; // 4
	bool noHands = false; // 8
	bool noEyes = false; // 16
	bool noBody = false; // 32
	bool devilHorns = false; // 64
	bool goldenHalo = false; // 128
	bool isFrozen = false; // 2048
	bool isCursed = false; // 4096
	bool isDuctaped = false; // 8192
	bool haveCigar = false; // 16384
	bool isShining = false; // 32768
	bool isZombie = false; // 65536
	bool isHitByLava = false; // 131072
	bool haveHauntedShadows = false; // 262144
	bool haveGeigerRadiation = false; // 524288
	bool haveReflector = false; // 1048576
	bool isEgged = false; // 2097152
	bool havePineappleFloag = false; // 4194304
	bool haveFlyingPineapple = false; // 8388608
	bool haveSuperSupporterName = false; // 16777216
	bool haveSupperPineapple = false; // 33554432
	bool isGhost = false;
	//bool 
	int skinColor = 0x8295C3FF; //normal SKin color like gt!

	PlayerInventory inventory;

	long long int lastSB = 0;

	//hacky dropped item stuff :(
	vector<ItemSharedUID> item_uids;
	int last_uid = 1;

            }
            FRAMEWORK_EXPORT player(ENetPeer* peer);
            FRAMEWORK_EXPORT player();
            FRAMEWORK_EXPORT ~player();

            FRAMEWORK_EXPORT void set_uid(const int& id) { m_uid = id; }
            FRAMEWORK_EXPORT int get_uid() { return m_uid; }

            FRAMEWORK_EXPORT void set_net_id(const int& id) { m_net_id = id; }
            FRAMEWORK_EXPORT int get_net_id() { return m_net_id; }

            FRAMEWORK_EXPORT void greet(); // TODO: implement greeting (which accepts login)
            FRAMEWORK_EXPORT void content(); // TODO: implement content (which sends cache data, etc.)

            FRAMEWORK_EXPORT void send_packet(const void* data = nullptr, const uintmax_t& data_size = 0, const uint32_t& flags = 0);
            FRAMEWORK_EXPORT void send_packet(const uint32_t& type, const void* data = nullptr, const uintmax_t& data_size = 0, const uint32_t& flags = 0);
            FRAMEWORK_EXPORT void variant(const variantlist& vlist, int net_id = -1, int delay = -1, uint32_t flags = ENET_PACKET_FLAG_RELIABLE);
            
        private:
            /* ENet Value */
            ENetPeer* m_peer; // Peer value

            /* Loggger */
            logger* m_logger; // Logger value

            /* Special Values */
            int m_uid; // Unique ID
            int m_net_id; // Network ID
            int m_hash; // Hash of the player
            int m_platform; // @m_platform is used to make a "special" update link for player

        
    };
}
#endif // __PLAYER__PLAYER_H__