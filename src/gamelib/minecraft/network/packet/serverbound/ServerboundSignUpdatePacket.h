#pragma once

#include <utils/Types.h>

#include "../Packet.h"

#include "../../../block/BlockPos.h"

namespace mstd {
    class wstring;
}

namespace mc {
    class ServerboundSignUpdatePacket : public Packet {
    public:
        uint32_t field_0x10;
        uint32_t field_0x14;
        BlockPos pos;
        mstd::wstring *lines;
        uint32_t field_0x28;
        uint32_t field_0x2C;
    };
} // namespace mc