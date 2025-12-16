#include "ServerboundSetCreativeModeSlotPacket.h"

#include <Link/Link.h>

namespace mc {
    ServerboundSetCreativeModeSlotPacket::ServerboundSetCreativeModeSlotPacket(int slot, const mc_boost::shared_ptr<ItemInstance>& item) {
        Link::Func<void, 0x028B09F8, ServerboundSetCreativeModeSlotPacket*, int, const mc_boost::shared_ptr<ItemInstance>&>()(this, slot, item);
    }
}