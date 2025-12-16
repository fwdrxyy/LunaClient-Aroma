#include "ServerboundContainerClickPacket.h"

#include <Link/Link.h>

namespace mc {
    ServerboundContainerClickPacket::ServerboundContainerClickPacket(int a, int b, int c, ClickType::eClickType type, const mc_boost::shared_ptr<ItemInstance>& item, short s) {
        Link::Func<void, 0x028aaafc, ServerboundContainerClickPacket*, int, int, int, ClickType::eClickType, const mc_boost::shared_ptr<ItemInstance>&, short>()(this, a, b, c, type, item, s);
    }
}