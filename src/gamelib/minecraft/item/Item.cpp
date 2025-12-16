#include "Item.h"

#include <Link/Link.h>

namespace mc {
    Item::Item() {
        Link::Func<void, 0x024B65D8, Item*>()(this);
    }

    void Item::HandEquipped() {
        Link::Func<void, 0x024B6904, Item*>()(this);
    }

    void Item::setMaxDamage(uint32_t arg1) {
        Link::Func<void, 0x024B6910, Item*, uint32_t>()(this, arg1);
    }

    void Item::setCraftingRemainingItem(uint32_t arg1) {
        Link::Func<void, 0x024B6C40, Item*, uint32_t>()(this, arg1);
    }

    void Item::setStackedByData(bool arg1) {
        Link::Func<void, 0x024B6C48, Item*, uint8_t>()(this, arg1);
    }

    void Item::setMaxStackSize(int size) {
        Link::Func<void, 0x024b2bd8, Item*, int>()(this, size);
    }

    bool Item::isItemABlock(int id) {
        return Link::Func<bool, 0x024cf838, int>()(id);
    }

    uint32_t Item::getBaseItemType() {
        return Link::Func<uint32_t, 0x024CFD24, Item*>()(this);
    }

    uint32_t Item::getMaxStackSize() {
        return Link::Func<uint32_t, 0x024CFFC4, Item*>()(this);
    }

    void Item::setIconName(const mstd::wstring& name) {
        Link::Func<void, 0x024b2b90, Item*, const mstd::wstring&>()(this, name);
    }

    void Item::setAllowOffhand(bool allow) {
        Link::Func<void, 0x024b63bc, Item*, bool>()(this, allow);
    }

    bool Item::isHandEquipped() {
        return Link::Func<uint8_t, 0x024D0030, Item*>()(this);
    }

    Item* Item::byId(int id) {
        return Link::Func<Item*, 0x02486698, int>()(id);
    }

    void Item::registerItem(int id, const ResourceLocation& loc, Item* item) {
        Link::Func<void, 0x24B3D60, int, const ResourceLocation&, Item*>()(id, loc, item);
    }

    int Item::getId() {
        return Link::Func<int, 0x02492100, Item*>()(this);
    }
}