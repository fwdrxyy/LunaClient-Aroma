#include "Inventory.h"

#include <Link/Link.h>

namespace mc {
    void Inventory::dropAll() { Link::Func<void, 0x024a1878, Inventory *>()(this); }

    void Inventory::clearContent() { Link::Func<void, 0x024A2C94, Inventory *>()(this); }

    void Inventory::setItem(uint32_t index, const mc_boost::shared_ptr<ItemInstance> &item) {
        Link::Func<void, 0x0249efac, Inventory *, uint32_t, const mc_boost::shared_ptr<ItemInstance> &>()(this, index, item);
    }

    void Inventory::save(ListTag *listTag) { Link::Func<void, 0x0249f5fc, Inventory *, ListTag *>()(this, listTag); }

    void Inventory::load(ListTag *listTag) { Link::Func<void, 0x0249fb30, Inventory *, ListTag *>()(this, listTag); }

    void Inventory::setChanged() { Link::Func<void, 0x024a20e8, Inventory *>()(this); }

    const mc_boost::shared_ptr<ItemInstance> &Inventory::getSelected() { return Link::Func<const mc_boost::shared_ptr<ItemInstance> &, 0x02497F7C, Inventory *>()(this); }

    void Inventory::add(int slot, const mc_boost::shared_ptr<ItemInstance> &item) {
        Link::Func<void, 0x0249C0D4, Inventory *, int, const mc_boost::shared_ptr<ItemInstance> &>()(this, slot, item);
    }

    bool Inventory::add(const mc_boost::shared_ptr<ItemInstance> &item) {
        return Link::Func<bool, 0x0249d300, Inventory *, const mc_boost::shared_ptr<ItemInstance> &>()(this, item);
    }

    void Inventory::getItem(uint32_t slot, const mc_boost::shared_ptr<ItemInstance> &item) {
        Link::Func<void, 0x024a0b9c, Inventory *, const mc_boost::shared_ptr<ItemInstance> &, uint32_t>()(this, item, slot);
    }

    int Inventory::findSlotMatchingItem(const mc_boost::shared_ptr<ItemInstance> &item, bool idk) {
        return Link::Func<int, 0x02498a34, Inventory *, const mc_boost::shared_ptr<ItemInstance> &, bool>()(this, item, idk);
    }
} // namespace mc