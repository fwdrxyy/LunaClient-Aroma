#include "ServerboundSetCarriedItemPacket.h"

#include <Link/Link.h>

namespace mc {
    ServerboundSetCarriedItemPacket::ServerboundSetCarriedItemPacket(int32_t slot) {
        Link::Func<void, 0x028B0550, ServerboundSetCarriedItemPacket *, int32_t>()(this, slot);
    }
} // namespace mc