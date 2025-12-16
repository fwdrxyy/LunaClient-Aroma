#pragma once

#include <utils/Types.h>

#include <minecraft/client/resource/shared_ptr.h>
#include <minecraft/client/resource/vector.h>
#include <minecraft/network/packet/clientbound/ClientboundLoginPacket.h>

namespace mc {
    class Packet;
    class ServerPlayer;
    class MinecraftServer;
    class Connection;
    class ServerConnectionListener;

    class PlayerList {
    public:
        int32_t getMaxPlayers();
        int32_t getPlayerCount();
        void broadcastAll(const mc_boost::shared_ptr<Packet> &packet);
        void tick();
        int32_t addPlayerToReceiving(mc_boost::shared_ptr<ServerPlayer> player,
                                     bool unk1);
        void add(mc_boost::shared_ptr<ServerPlayer> player);
        void
        placeNewPlayer(Connection *connection,
                       mc_boost::shared_ptr<ServerPlayer> player,
                       mc_boost::shared_ptr<ClientboundLoginPacket> packet);
        void getPlayerForLogin(ServerConnectionListener *listener,
                               const mstd::wstring &unk1, PlayerUID uid1,
                               PlayerUID uid2);

        mstd::vector<mc_boost::shared_ptr<ServerPlayer>> players;
        MinecraftServer *server;
        uint32_t field_0x14;
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
    };
} // namespace mc