#include "ItemInstance.h"

#include <Link/Link.h>

namespace mc {
    ItemInstance::ItemInstance(Item* item, int amount) {
        Link::Func<void, 0x024861BC, ItemInstance*, Item*, int>()(this, item, amount);
    }

    ItemInstance::ItemInstance(Item* item, int amount, int aux) {
        Link::Func<void, 0x024862d0, ItemInstance*, Item*, int, int>()(this, item, amount, aux);
    }
		
    void ItemInstance::toShared(const mc_boost::shared_ptr<ItemInstance>& ret, const ItemInstance* src) {
        Link::Func<void, 0x3065EE0, const mc_boost::shared_ptr<ItemInstance>&, const ItemInstance*>()(ret, src);
    }

    void ItemInstance::setAuxValue(int val) {
        Link::Func<void, 0x02488B2C, ItemInstance*, int>()(this, val);
    }

    CompoundTag* ItemInstance::getTag() {
        return Link::Func<CompoundTag*, 0x02488888, ItemInstance*>()(this);
    }

    void ItemInstance::setTag(CompoundTag* _tag) {
        Link::Func<void, 0x0248e080, ItemInstance*, CompoundTag*>()(this, _tag);
    }

    bool ItemInstance::hasTag() {
        return Link::Func<bool, 0x02488860, ItemInstance*>()(this);
    }

    int ItemInstance::getCount() {
        return Link::Func<int, 0x02479E14, ItemInstance*>()(this);
    }

    void ItemInstance::setCount(int c) {
        Link::Func<void, 0x02479e6c, ItemInstance*, int>()(this, c);
    }

    void ItemInstance::copy(mc_boost::shared_ptr<ItemInstance>& output) {
        Link::Func<void, 0X02486e20, ItemInstance*, mc_boost::shared_ptr<ItemInstance>&>()(this, output);
    }
}