#pragma once

#include <utils/Types.h>

#include "../client/resource/shared_ptr.h"

namespace mc {
    class Item;
    class CompoundTag;

    class ItemInstance {
    public:
        ItemInstance(Item *item, int amount);
        ItemInstance(Item *item, int amount, int aux);

        static void toShared(const mc_boost::shared_ptr<ItemInstance> &ret, const ItemInstance *src);
        void setAuxValue(int val);
        CompoundTag *getTag();
        void setTag(CompoundTag *_tag);
        bool hasTag();
        int getCount();
        void setCount(int c);
        void copy(mc_boost::shared_ptr<ItemInstance> &output);

        uint32_t field_0x0;
        uint32_t field_0x4;
        int count; // i think
        uint32_t field_0xC;
        Item *item;
        CompoundTag *tag;
        uint32_t field_0x18;
        int aux;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t field_0x2C;
        uint32_t field_0x30;
        uint32_t field_0x34;
        uint32_t field_0x38;
        uint32_t field_0x3C;
        uint32_t field_0x40;
    };
} // namespace mc
