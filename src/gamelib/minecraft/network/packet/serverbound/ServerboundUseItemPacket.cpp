#include "ServerboundUseItemPacket.h"

#include <Link/Link.h>

namespace mc {
    ServerboundUseItemPacket::ServerboundUseItemPacket(InteractionHand::EInteractionHand hand) {
        Link::Func<void, 0x028B2B8C, ServerboundUseItemPacket *, InteractionHand::EInteractionHand>()(this, hand);
    }
} // namespace mc