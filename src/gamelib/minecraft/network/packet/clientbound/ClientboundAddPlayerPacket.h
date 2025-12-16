#pragma once

#include <utils/Types.h>

#include <minecraft/client/resource/shared_ptr.h>
#include <minecraft/entity/player/Player.h>
#include <minecraft/entity/player/PlayerUID.h>
#include <minecraft/network/packet/Packet.h>

namespace mc {
    class ClientboundAddPlayerPacket : public Packet {
    public:
        ClientboundAddPlayerPacket(mc_boost::shared_ptr<Player> player,
                                   PlayerUID _uid1, PlayerUID _uid2, int32_t _x,
                                   int32_t _y, int32_t _z, int16_t _yaw,
                                   int16_t _pitch, int32_t unk1);

        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t entityId;
        PlayerUID uid1;
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
        int32_t x;
        int32_t y;
        int32_t z;
        int16_t yaw;
        int16_t pitch;
        PlayerUID uid2;
        uint32_t field_0x64;
        uint32_t field_0x68;
        uint32_t field_0x6C;
        uint32_t field_0x70;
        uint32_t field_0x74;
        uint32_t field_0x78;
        uint32_t field_0x7C;
        uint32_t field_0x80;
        uint32_t field_0x84; // unk1
        uint32_t field_0x88;
        uint32_t field_0x8C;
        uint32_t field_0x90;
        uint32_t field_0x94;
        uint32_t field_0x98;
    };
} // namespace mc