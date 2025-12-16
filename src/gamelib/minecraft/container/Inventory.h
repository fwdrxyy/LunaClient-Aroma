#pragma once

#include <utils/Types.h>

#include "Container.h"

#include "../client/resource/NonNullList.h"
#include "../client/resource/shared_ptr.h"

namespace mc {
    class ItemInstance;
    class ListTag;

    class Inventory : public Container {
    public:
        void dropAll();
        void clearContent();
        void setItem(uint32_t index, const mc_boost::shared_ptr<ItemInstance> &item);
        void save(ListTag *listTag);
        void load(ListTag *listTag);
        void setChanged();
        const mc_boost::shared_ptr<ItemInstance> &getSelected();
        void add(int slot, const mc_boost::shared_ptr<ItemInstance> &item);
        bool add(const mc_boost::shared_ptr<ItemInstance> &item);
        void getItem(uint32_t slot, const mc_boost::shared_ptr<ItemInstance> &item);
        int findSlotMatchingItem(const mc_boost::shared_ptr<ItemInstance> &item, bool idk);

        uint32_t field_0xC;
        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28; // unk
        uint32_t field_0x2C;
        uint32_t field_0x30;
        uint32_t field_0x34;
        NonNullList<mc_boost::shared_ptr<ItemInstance>> list;
        uint32_t field_0x48;
        uint32_t field_0x4C;
        uint32_t field_0x50;
        uint32_t field_0x54;
        uint32_t field_0x58;
        uint32_t field_0x5C;
        uint32_t field_0x60;
        uint32_t field_0x64;
        uint32_t field_0x68;
        int selectedSlot; // from 0 - 8
        uint32_t field_0x70;
        uint32_t field_0x74;
        uint32_t field_0x78;
        uint32_t field_0x7C;
        uint32_t field_0x80;
        uint32_t field_0x84;
        uint32_t field_0x88;
    };
} // namespace mc