#pragma once

#include <utils/Types.h>

#include "../Packet.h"

#include "../../../block/BlockPos.h"

namespace mc {
    class Direction;

    class ServerboundPlayerActionPacket : public Packet {
    public:
        enum Action : int { START_BREAKING, STOP_BREAKING, FINISH_BREAKING, DROP_ALL, DROP_SINGLE, RELEASE, SWAP_HANDS };

        ServerboundPlayerActionPacket(Action action, const BlockPos &pos, const Direction *dir, int arg5);
        ~ServerboundPlayerActionPacket();

        uint32_t field_0x10;
        uint32_t field_0x14;
        BlockPos position;
        Direction *direction;
        Action action;
        uint32_t field_0x2C;
    };
} // namespace mc