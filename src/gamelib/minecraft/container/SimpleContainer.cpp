#include "SimpleContainer.h"

#include <Link/Link.h>

namespace mc {
    SimpleContainer::SimpleContainer(int field_0x0, int field_0x1, const mstd::wstring& str, int size) {
        Link::Func<void, 0x028f39dc, SimpleContainer*, int, int, const mstd::wstring&, int>()(this, field_0x0, field_0x1, str, size);
    }

    void SimpleContainer::toShared(const mc_boost::shared_ptr<SimpleContainer>& ret, SimpleContainer* src) {
        Link::Func<void, 0x3065EE0, const mc_boost::shared_ptr<SimpleContainer>&, SimpleContainer*>()(ret, src);
    }

    void SimpleContainer::getItem(uint32_t slot, const mc_boost::shared_ptr<ItemInstance>& item) {
        Link::Func<void, 0x028DCB78, SimpleContainer*, const mc_boost::shared_ptr<ItemInstance>&, uint32_t>()(this, item, slot);
    }

    void SimpleContainer::addItem(int slot, const mc_boost::shared_ptr<ItemInstance>& item) {
        Link::Func<void, 0x028f4200, SimpleContainer*, int, const mc_boost::shared_ptr<ItemInstance>&>()(this, slot, item);
    }

    void SimpleContainer::setItem(int slot, const mc_boost::shared_ptr<ItemInstance>& item) {
        Link::Func<void, 0x028DD3C8, SimpleContainer*, int, const mc_boost::shared_ptr<ItemInstance>&>()(this, slot, item);
    }

    void SimpleContainer::clearContent() {
        Link::Func<void, 0x028DD90C, SimpleContainer*>()(this);
    }
}