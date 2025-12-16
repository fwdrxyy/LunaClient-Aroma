#pragma once

#include "../client/resource/wstring.h"
#include "../client/resource/shared_ptr.h"
#include "../client/resource/vector.h"

#include "Container.h"

namespace mc {
    class ItemInstance;
    class net_minecraft_ContainerListener;

    class SimpleContainer {
    public:
        SimpleContainer(int field_0x0, int field_0x1, const mstd::wstring& str, int size);

        static void toShared(const mc_boost::shared_ptr<SimpleContainer>& ret, SimpleContainer* src);
        
        void getItem(uint32_t slot, const mc_boost::shared_ptr<ItemInstance>& item);
        void addItem(int slot, const mc_boost::shared_ptr<ItemInstance>& item);
        void setItem(int slot, const mc_boost::shared_ptr<ItemInstance>& item);
        void clearContent();

        uint32_t field_0x0;
        mstd::wstring field_0x4;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t maxSlots; // I think
        uint32_t field_0x30;
        uint32_t field_0x34;
        mstd::vector<net_minecraft_ContainerListener*> listeners;
        uint32_t field_0x48;
        uint32_t field_0x4C;
        uint32_t field_0x50;
        uint32_t field_0x54;
        uint32_t field_0x58;
        Container container;
    };
}