#pragma once

#include <utils/Types.h>

#include "../Packet.h"

#include "../../../client/resource/shared_ptr.h"

namespace mc {
    class ItemInstance;

    class ServerboundSetCreativeModeSlotPacket : public Packet {
    public:
        ServerboundSetCreativeModeSlotPacket(int slot, const mc_boost::shared_ptr<ItemInstance> &item);

        uint32_t field_0x10;
        uint32_t field_0x14;
        int slotNum;
        mc_boost::shared_ptr<ItemInstance> iteminstance;
        uint32_t field_0x24;
    };
} // namespace mc