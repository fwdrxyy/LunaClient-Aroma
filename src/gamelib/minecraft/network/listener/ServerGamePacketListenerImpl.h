#pragma once

#include <utils/Types.h>

#include "../../client/resource/shared_ptr.h"

#include "../packet/DisconnectPacket.h"

namespace mc {
    class Packet;
    class ServerboundMovePlayerPacket;
    class ServerboundPlayerActionPacket;
    class ServerboundUseItemOnPacket;
    class ServerboundContainerClickPacket;
    class ClientboundSoundPacket;
    class ClientboundChatPacket;
    class Connection;
    class MinecraftServer;
    class ServerPlayer;

    class ServerGamePacketListenerImpl {
    public:
        ServerGamePacketListenerImpl(MinecraftServer *_server, Connection *_connection, mc_boost::shared_ptr<ServerPlayer> _player);

        void send(mc_boost::shared_ptr<Packet> packet);
        void disconnect(DisconnectPacket::eDisconnectReason reason);

        void teleport(double x, double y, double z, float yaw, float pitch, bool unk1, bool unk2);
        void handleMovePlayer(const mc_boost::shared_ptr<ServerboundMovePlayerPacket> &packet);
        void handlePlayerAction(const mc_boost::shared_ptr<ServerboundPlayerActionPacket> &packet);
        void handleUseItemOn(const mc_boost::shared_ptr<ServerboundUseItemOnPacket> &packet);
        void handleContainerClick(const mc_boost::shared_ptr<ServerboundContainerClickPacket> &packet);
        void handleSoundEvent(const mc_boost::shared_ptr<ClientboundSoundPacket> &packet);
        void handleChat(const mc_boost::shared_ptr<ClientboundChatPacket> &packet);

        uint32_t field_0x0;
        uint32_t field_0x4;
        Connection *connection;
        uint32_t field_0xC;
        uint32_t field_0x10;
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
        MinecraftServer *server;
        mc_boost::shared_ptr<ServerPlayer> player;
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
        uint32_t field_0x14C;
        uint32_t field_0x150;
        uint32_t field_0x154;
    };
} // namespace mc