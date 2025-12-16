#pragma once

#include <utils/Types.h>

#include <minecraft/network/packet/Packet.h>
#include <minecraft/utils/InteractionHand.h>

namespace mc {
    class ServerboundUseItemPacket : public Packet {
    public:
        ServerboundUseItemPacket(InteractionHand::EInteractionHand hand);

        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
    };
} // namespace mc