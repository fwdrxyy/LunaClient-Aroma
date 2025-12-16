#pragma once

#include <utils/Types.h>

#include <minecraft/network/packet/Packet.h>

namespace mc {
    class ServerboundSetCarriedItemPacket : public Packet {
    public:
        ServerboundSetCarriedItemPacket(int32_t slot);

        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
    };
} // namespace mc