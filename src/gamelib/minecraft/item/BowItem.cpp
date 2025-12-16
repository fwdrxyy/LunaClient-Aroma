#include "BowItem.h"

#include <Link/Link.h>

namespace mc {
    BowItem::BowItem() {
        Link::Func<void, 0x02162460, BowItem*>()(this);
    }

    Item* BowItem::releaseUsing(const mc_boost::shared_ptr<ItemInstance>& instance, Level* level, const mc_boost::shared_ptr<LivingEntity>& entity, int idk) {
        return Link::Func<Item*, 0x02164810, BowItem*, const mc_boost::shared_ptr<ItemInstance>&, Level*, const mc_boost::shared_ptr<LivingEntity>&, int>()(this, instance, level, entity, idk);
    }
}