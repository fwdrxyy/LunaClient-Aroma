#include "ClientbooundSetEntityMotionPacket.h"

#include <Link/Link.h>

namespace mc {
    ClientboundSetEntityMotionPacket::ClientboundSetEntityMotionPacket(int id, double x, double y, double z) {
        Link::Func<void, 0x0221e214, ClientboundSetEntityMotionPacket*, int, double, double, double>()(this, id, x, y, z);
    }
}