#pragma once

#include <utils/Types.h>

#include <minecraft/network/server/PlayerList.h>
#include <minecraft/world/ServerLevel.h>
#include <minecraft/world/gamemode/MasterGameMode.h>

namespace mc {
    class MinecraftServer {
    public:
        static MinecraftServer *getInstance();
        struct ServerLevel *getLevel(int32_t i);
        struct PlayerList *getPlayers();

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        uint32_t field_0x10;
        PlayerList *playerList;
        uint32_t field_0x18;
        uint32_t field_0x1C;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t field_0x2C;
        uint32_t field_0x30;
        uint32_t field_0x34;
        uint32_t field_0x38;
        uint32_t field_0x3C;
        uint32_t field_0x40;
        uint32_t field_0x44;
        uint32_t field_0x48;
        uint32_t field_0x4C;
        uint32_t field_0x50;
        uint32_t field_0x54;
        uint32_t field_0x58;
        uint32_t field_0x5C;
        uint32_t field_0x60;
        uint32_t field_0x64;
        uint32_t field_0x68;
        uint32_t field_0x6C;
        uint32_t field_0x70;
        uint32_t field_0x74;
        uint32_t field_0x78;
        uint32_t field_0x7C;
        uint32_t field_0x80;
        uint32_t field_0x84;
        uint32_t field_0x88;
        uint32_t field_0x8C;
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
        uint32_t field_0x110;
        uint32_t field_0x114;
        uint32_t field_0x118;
        uint32_t field_0x11C;
        uint32_t field_0x120;
        uint32_t field_0x124;
        uint32_t field_0x128;
        uint32_t field_0x12C;
        uint32_t field_0x130;
        uint32_t field_0x134;
        uint32_t field_0x138;
        uint32_t field_0x13C;
        uint32_t field_0x140;
        uint32_t field_0x144;
        uint32_t field_0x148;
        MasterGameMode *masterGamemode;
        uint32_t field_0x150;
    };
} // namespace mc