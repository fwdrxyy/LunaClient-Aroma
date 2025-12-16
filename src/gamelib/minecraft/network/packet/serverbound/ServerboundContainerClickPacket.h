#pragma once

#include <utils/Types.h>

#include "../Packet.h"

#include "../../../client/resource/shared_ptr.h"
#include "../../../client/resource/vector.h"

#include "../../../utils/ClickType.h"

namespace mc {
    class ItemInstance;

    class ServerboundContainerClickPacket : public Packet {
    public:
        ServerboundContainerClickPacket(int a, int b, int c, ClickType::eClickType type, const mc_boost::shared_ptr<ItemInstance> &item, short s);

        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t containerId;
        uint32_t slotNum;
        uint32_t buttonNum;
        uint32_t uid;
        mstd::vector<mc_boost::shared_ptr<ItemInstance>> items;
        ClickType::eClickType clickType;
        uint32_t numSlots;
    };
} // namespace mc