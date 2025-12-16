#include "ServerboundUseItemOnPacket.h"

#include <Link/Link.h>

namespace mc {
    ServerboundUseItemOnPacket::ServerboundUseItemOnPacket(const BlockPos &pos, const Direction *dir, InteractionHand::EInteractionHand hand, float unk1, float unk2,
                                                           float unk3) {
        Link::Func<void, 0x28B25B8, ServerboundUseItemOnPacket *, const BlockPos &, const Direction *, InteractionHand::EInteractionHand, float, float, float>()(
                this, pos, dir, hand, unk1, unk2, unk3);
    }

    ServerboundUseItemOnPacket::~ServerboundUseItemOnPacket() { Link::Func<void, 0x028D0B18, ServerboundUseItemOnPacket *>()(this); }
} // namespace mc