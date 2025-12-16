#include "ArmorStand.h"

#include <Link/Link.h>

namespace mc {
    ArmorStand::ArmorStand(Level* _level) {
        Link::Func<void, 0x0208bad4, ArmorStand*, Level*>()(this, _level);
    }
    
    void ArmorStand::setShortArms(bool state)  {
        Link::Func<void, 0x0202ece8, ArmorStand*, bool>()(this, state);
    }
    
    void ArmorStand::setItemSlot(EquipmentSlot* slot, const mc_boost::shared_ptr<ItemInstance>& item) {
        Link::Func<void, 0x0208c018, ArmorStand*, EquipmentSlot*, const mc_boost::shared_ptr<ItemInstance>&>()(this, slot, item);
    }
    
    uint64_t ArmorStand::GetType() {
        return Link::Func<uint64_t, 0x020b3dbc>()();
    }
}