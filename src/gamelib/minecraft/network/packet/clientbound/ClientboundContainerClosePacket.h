#pragma once

#include <minecraft/network/packet/Packet.h>

namespace mc {
    class ClientboundContainerClosePacket : public Packet {
    public:
        ClientboundContainerClosePacket(int32_t unk1);

        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
        uint32_t field_0x20;
    };
} // namespace mc
