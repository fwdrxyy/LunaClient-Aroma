#include "ServerboundMovePlayerPacket.h"

#include <Link/Link.h>

namespace mc {
    ServerboundMovePlayerPacket::ServerboundMovePlayerPacket(double x, double y, double z, bool isOnGround, bool isFlying) {
        Link::Func<void, 0x028AD6C4, ServerboundMovePlayerPacket *, bool, bool, double, double, double, double>()(this, isOnGround, isFlying, x, y, 0.0f, z);
    }

    ServerboundMovePlayerPacket::ServerboundMovePlayerPacket(double x, double y, double z, float yaw, float pitch, bool isOnGround, bool isFlying) {
        Link::Func<void, 0x028ad398, ServerboundMovePlayerPacket *, bool, bool, double, double, double, float, float>()(this, isOnGround, isFlying, x, y, z, yaw, pitch);
    }

    ServerboundMovePlayerPacket::ServerboundMovePlayerPacket(float yaw, float pitch, bool isOnGround, bool isFlying) {
        Link::Func<void, 0x028ad954, ServerboundMovePlayerPacket *, bool, bool, float, float>()(this, isOnGround, isFlying, yaw, pitch);
    }

    ServerboundMovePlayerPacket::~ServerboundMovePlayerPacket() { Link::Func<void, 0x028D007C, ServerboundMovePlayerPacket *>()(this); }
} // namespace mc