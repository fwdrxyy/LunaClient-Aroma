#pragma once

#include <utils/Types.h>

#include "../Packet.h"

namespace mc {
    class ServerboundMovePlayerPacket : public Packet {
    public:
        ServerboundMovePlayerPacket(double x, double y, double z, bool isOnGround, bool isFlying);
        ServerboundMovePlayerPacket(double x, double y, double z, float yaw, float pitch, bool isOnGround, bool isFlying);
        ServerboundMovePlayerPacket(float yaw, float pitch, bool isOnGround, bool isFlying);
        ~ServerboundMovePlayerPacket();

        uint32_t field_0x10;
        uint32_t field_0x14;
        double x;
        double y;
        double Z;
        float yaw;
        float pitch;
        bool isOnGround;
        uint8_t field_0x39;
        uint8_t field_0x3A;
        bool isFlying;
        uint32_t field_0x3C;
    };
} // namespace mc