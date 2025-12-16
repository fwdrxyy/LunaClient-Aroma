#pragma once

#include <utils/Types.h>

#include "../client/resource/wstring.h"

namespace mc {
    class ResourceLocation;
    class VTable_Item;

    class Item {
    public:
        Item();

        void HandEquipped();
        void setMaxDamage(uint32_t arg1);
        void setCraftingRemainingItem(uint32_t arg1);
        void setStackedByData(bool arg1);
        void setMaxStackSize(int size);
        static bool isItemABlock(int id);
        uint32_t getBaseItemType();
        uint32_t getMaxStackSize();
        void setIconName(const mstd::wstring &name);
        void setAllowOffhand(bool allow);
        bool isHandEquipped();
        static Item *byId(int id);
        static void registerItem(int id, const ResourceLocation &loc, Item *item);
        int getId();

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t maxStackSize;
        uint32_t maxDamage;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
        uint32_t field_0x20;
        uint32_t field_0x24;
        mstd::wstring unk_str;
        uint32_t field_0x48;
        uint32_t field_0x4C;
        mstd::wstring iconName;
        uint32_t field_0x70;
        VTable_Item *vtbl;
    };
} // namespace mc