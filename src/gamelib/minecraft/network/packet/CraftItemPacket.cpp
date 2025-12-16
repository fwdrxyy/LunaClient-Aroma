#include "CraftItemPacket.h"

#include <Link/Link.h>

#include <minecraft/item/Item.h>
#include <minecraft/item/ItemInstance.h>

namespace mc {
    CraftItemPacket::CraftItemPacket(int a, int b, int c) { Link::Func<void, 0x0222DD24, CraftItemPacket *, int, int, int>()(this, a, b, c); }

    void CraftItemPacket::craft(ClientPacketListener *listener, Inventory *inventory, int32_t craftId, int32_t itemId, int32_t itemAmount, int32_t itemAux) {
        listener->send(new CraftItemPacket(craftId, 0, 0));
        inventory->add(new ItemInstance(Item::byId(itemId), itemAmount, itemAux));
    }
} // namespace mc