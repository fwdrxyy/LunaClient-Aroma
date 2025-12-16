#pragma once

#include <utils/Types.h>

#include "../../../client/resource/vector.h"
#include "../../../client/resource/wstring.h"

#include "../Packet.h"

namespace mc {
    class ClientboundChatPacket : public Packet {
    public:
        ClientboundChatPacket(const mstd::wstring &str);

        template<typename... T>
        static ClientboundChatPacket *format(const wchar_t *str, T... t) {
            wchar_t temp[0x100];
            mc_swprintf(temp, 0x100, str, t...);
            return new ClientboundChatPacket(temp);
        }

        mstd::vector<mstd::wstring> str_v;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t field_0x2C;
        uint32_t field_0x30;
        uint32_t field_0x34;
        uint32_t field_0x38;
        uint32_t field_0x3C;
        uint32_t field_0x40;
        uint32_t field_0x44;
        uint32_t field_0x48;
        uint32_t field_0x4C;
        uint32_t field_0x50;
        uint32_t field_0x54;
        uint32_t field_0x58;
        uint32_t field_0x5C;
        uint32_t field_0x60;
        uint32_t field_0x64;
    };
} // namespace mc