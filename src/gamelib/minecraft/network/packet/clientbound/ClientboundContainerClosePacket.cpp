#include "ClientboundContainerClosePacket.h"

#include <Link/Link.h>

namespace mc {
    ClientboundContainerClosePacket::ClientboundContainerClosePacket(int32_t unk1) {
        Link::Func<void, 0x021D449C, ClientboundContainerClosePacket *, int32_t>()(this, unk1);
    }
} // namespace mc
