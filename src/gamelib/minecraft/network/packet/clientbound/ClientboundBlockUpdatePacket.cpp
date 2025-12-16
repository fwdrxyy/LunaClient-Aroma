#include "ClientboundBlockUpdatePacket.h"

#include <Link/Link.h>

namespace mc {
    ClientboundBlockUpdatePacket::ClientboundBlockUpdatePacket(Level* level, const BlockPos& pos) {
        Link::Func<void, 0x021DF3C8, ClientboundBlockUpdatePacket*, Level*, const BlockPos&>()(this, level, pos);
    }
}