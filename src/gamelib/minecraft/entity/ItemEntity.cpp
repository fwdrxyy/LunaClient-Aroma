#include "ItemEntity.h"

#include <Link/Link.h>

namespace mc {
    ItemEntity::ItemEntity(Level* _level) {
        Link::Func<void, 0x024dc21c, ItemEntity*, Level*>()(this, _level);
    }

    ItemEntity::ItemEntity(Level* _level, double x, double y, double z) {
        Link::Func<void, 0x024dc0f8, ItemEntity*, Level*, double, double, double>()(this, _level, x, y, z);
    }

    ItemEntity::ItemEntity(Level* _level, double x, double y, double z, const mc_boost::shared_ptr<ItemInstance>& item) {
        Link::Func<void, 0x024d3b60, ItemEntity*, Level*, double, double, double, const mc_boost::shared_ptr<ItemInstance>&>()(this, _level, x, y, z, item);
    }

    void ItemEntity::setItem(const mc_boost::shared_ptr<ItemInstance>& item) {
        Link::Func<void, 0x024d3898, ItemEntity*, const mc_boost::shared_ptr<ItemInstance>&>()(this, item);
    }

    void ItemEntity::setPickUpDelay(int delay) {
        Link::Func<void, 0x024e113c, ItemEntity*, int>()(this, delay);
    }

    void ItemEntity::setNeverPickUp() {
        Link::Func<void, 0x024e1130, ItemEntity*>()(this);
    }

    void ItemEntity::setDefaultPickUpDelay() {
        Link::Func<void, 0x024d3d54, ItemEntity*>()(this);
    }

    void ItemEntity::playerTouch(const mc_boost::shared_ptr<Player>& player) {
        Link::Func<void, 0x024e0300, ItemEntity*, const mc_boost::shared_ptr<Player>&>()(this, player);
    }

    void ItemEntity::setShortLifeTime() {
        Link::Func<void, 0x024deb94, ItemEntity*>()(this);
    }

    uint64_t ItemEntity::GetType() {
        return Link::Func<uint64_t, 0x0252d668>()();
    }
}