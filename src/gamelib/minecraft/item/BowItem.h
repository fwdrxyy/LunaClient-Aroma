#pragma once

#include <utils/Types.h>

#include "Item.h"

#include "../client/resource/shared_ptr.h"

#include "../utils/Common.h"

namespace mc {
    class ItemInstance;
    class Level;
    class LivingEntity;
    class VTable_Item;

    class BowItem : public Item {
    public:
        BowItem();

        Item *releaseUsing(const mc_boost::shared_ptr<ItemInstance> &instance, Level *level, const mc_boost::shared_ptr<LivingEntity> &entity,
                           int idk);

        DEFINE_STATIC_DEF_VAR(VTable_Item *, vtbl, 0x10061554);
        DEFINE_STATIC_DEF_VAR(int, itemId, 261);

        uint32_t field_0x78;
        uint32_t field_0x7C;
        uint32_t field_0x80;
    };
} // namespace mc