#pragma once

#include <utils/Types.h>

#include "../Packet.h"

#include "../../../block/BlockPos.h"

namespace mc {
    class Block;

    class ClientboundBlockEventPacket : public Packet {
    public:
        ClientboundBlockEventPacket();

        uint32_t field_0x10;
        uint32_t field_0x14;
        BlockPos pos;
        uint32_t B0;
        uint32_t B1;
        Block *block;
    };
} // namespace mc