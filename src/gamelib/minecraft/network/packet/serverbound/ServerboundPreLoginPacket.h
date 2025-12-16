#pragma once

#include <utils/Types.h>

#include "../../../client/resource/wstring.h"
#include "../Packet.h"

namespace mc {
    class ServerboundPreLoginPacket : public Packet {
    public:
        ServerboundPreLoginPacket(const mstd::wstring &wstr);

        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t gameVersion;
        mstd::wstring nnid;
    };
} // namespace mc