#pragma once

#include <utils/Types.h>

#include "../Packet.h"

#include "../../../block/BlockPos.h"
#include "../../../utils/InteractionHand.h"

namespace mc {
    class Direction;

    class ServerboundUseItemOnPacket : public Packet {
    public:
        ServerboundUseItemOnPacket(const BlockPos &pos, const Direction *dir, InteractionHand::EInteractionHand hand, float unk1, float unk2, float unk3);
        ~ServerboundUseItemOnPacket();

        uint32_t field_0x10;
        uint32_t field_0x14;
        BlockPos position;
        Direction *direction;
        InteractionHand::EInteractionHand e_hand;
        float clickX;
        float clickY;
        float clickZ;
    };
} // namespace mc