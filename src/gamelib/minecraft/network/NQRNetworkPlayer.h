#pragma once

#include <utils/Types.h>

#include <minecraft/entity/player/Player.h>
#include <minecraft/entity/player/PlayerUID.h>
#include <minecraft/network/NQRNetworkManager_WiiU.h>
#include <minecraft/network/server/MinecraftServer.h>

namespace mc {
    class NQRNetworkPlayer {
    public:
        wchar_t *getMiiName(); // Has to be used since using field->0x34 crashes?

        static uint32_t getPrincipalIdByPlayer(const Player *player) {
            if (!player) return 0;

            const auto &playerUid  = player->uuid;
            const auto &netPlayers = NQRNetworkManager_WiiU::getInstance()->players;

            for (NQRNetworkPlayer *netPlayer : netPlayers)
                if (netPlayer && netPlayer->uid == playerUid) return netPlayer->principalId;

            return 0;
        }

        static int32_t getNetPlayerIndex(const Player *player) {
            if (!player) return -1;

            const auto &playerUid  = player->uuid;
            const auto &netPlayers = NQRNetworkManager_WiiU::getInstance()->players;

            for (int32_t i = 0; i < (int32_t) netPlayers.size(); i++)
                if (netPlayers[i] && netPlayers[i]->uid == playerUid) return i;

            return -1;
        }

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t localPlayerIndex;
        uint32_t field_0x10;
        uint32_t principalId;
        uint32_t smallId;
        PlayerUID uid;
        uint32_t field_0x30;
        uint32_t field_0x34; // miiName ?
        uint32_t field_0x38;
        uint32_t field_0x3C;
        uint32_t field_0x40;
        uint32_t field_0x44;
        uint8_t field_0x48;
        uint8_t field_0x49;
        char networkName[0x15];
        wchar_t networkNameW[0x15];
        NQRNetworkPlayer *customDataValue;
        uint32_t field_0x90;
        uint32_t field_0x94;
        uint32_t field_0x98;
        uint32_t field_0x9C;
        uint32_t field_0xA0;
        uint32_t field_0xA4;
        uint32_t field_0xA8;
        uint32_t field_0xAC;
        uint32_t field_0xB0;
        uint32_t field_0xB4;
        uint32_t field_0xB8;
        uint32_t field_0xBC;
        uint32_t field_0xC0;
        uint32_t field_0xC4;
        uint32_t field_0xC8;
        uint32_t field_0xCC;
        uint32_t field_0xD0;
        uint32_t field_0xD4;
        uint32_t field_0xD8;
        uint32_t field_0xDC;
        uint32_t field_0xE0;
        uint32_t field_0xE4;
        uint32_t field_0xE8;
        uint32_t field_0xEC;
        uint32_t field_0xF0;
        uint32_t field_0xF4;
        uint32_t field_0xF8;
        uint32_t field_0xFC;
        uint32_t field_0x100;
        uint32_t field_0x104;
        uint32_t field_0x108;
        uint32_t field_0x10C;
    };
} // namespace mc
