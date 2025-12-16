#pragma once

#include <utils/Types.h>

#include "../Packet.h"

#include "../../../client/resource/ArrayWithLength.h"
#include "../../../client/resource/vector.h"

namespace mc {
    class ClientboundMapItemDataPacket : public Packet {
    public:
        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t mapId;
        uint32_t field_0x1C;
        mstd::vector<void *> mapDecorations;
        uint32_t field_0x30;
        uint32_t field_0x34;
        uint32_t field_0x38;
        uint32_t field_0x3C;
        ArrayWithLength<uint8_t> mapData;
    };
} // namespace mc
