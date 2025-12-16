#pragma once

#include <utils/Types.h>

#include <minecraft/client/resource/wstring.h>
#include <minecraft/entity/player/PlayerUID.h>
#include <minecraft/network/packet/Packet.h>

namespace mc {
    class ClientboundLoginPacket : public Packet {
    public:
        ClientboundLoginPacket(const mstd::wstring &wstr, int32_t unk1, PlayerUID uid1, PlayerUID uid2, bool unk2, uint32_t unk3,
                               uint32_t skinId, uint32_t capeId, bool unk4, bool unk5);

        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        mstd::wstring wstr;
        uint32_t field_0x30;
        uint32_t field_0x34;
        uint32_t field_0x38;
        uint32_t field_0x3C;
        uint32_t field_0x40;
        uint32_t field_0x44;
        uint32_t field_0x48;
        PlayerUID uid1;
        PlayerUID uid2;
        uint32_t field_0x74;
        uint32_t field_0x78;
        uint32_t field_0x7C;
        uint32_t field_0x80;
        uint32_t field_0x84;
        uint32_t field_0x88; // unk8
        uint32_t field_0x8C;
        uint32_t field_0x90;
        uint32_t field_0x94;
        uint32_t field_0x98;
        uint32_t field_0x9C;
        uint32_t field_0xA0;
        uint32_t field_0xA4;
        uint32_t field_0xA8;
        uint32_t field_0xAC;
        uint32_t field_0xB0;
        uint32_t field_0xB4;
        uint32_t field_0xB8;
        uint32_t field_0xBC;
        uint32_t field_0xC0;
        uint32_t field_0xC4;
        uint32_t field_0xC8;
    };
} // namespace mc