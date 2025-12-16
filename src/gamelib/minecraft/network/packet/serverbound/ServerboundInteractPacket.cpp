#include "ServerboundInteractPacket.h"

#include <Link/Link.h>

namespace mc {
    ServerboundInteractPacket::ServerboundInteractPacket(const mc_boost::shared_ptr<Entity> &entity) {
        Link::Func<void, 0x028AC244, ServerboundInteractPacket *, const mc_boost::shared_ptr<Entity> &>()(this, entity);
    }

    ServerboundInteractPacket::~ServerboundInteractPacket() { Link::Func<void, 0x028AC5A8, ServerboundInteractPacket *>()(this); }
} // namespace mc