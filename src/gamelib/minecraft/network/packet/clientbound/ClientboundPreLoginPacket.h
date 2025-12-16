#ifndef CLIENTBOUNDPRELOGINPACKET_H
#define CLIENTBOUNDPRELOGINPACKET_H

#include <utils/Types.h>

#include <minecraft/client/resource/wstring.h>
#include <minecraft/entity/player/PlayerUID.h>
#include <minecraft/network/packet/Packet.h>

namespace mc {
    class ClientboundPreLoginPacket : public Packet {
    public:
        ClientboundPreLoginPacket(mstd::wstring hostName, PlayerUID *uid1, uint32_t index, uint8_t unk2, uint32_t unk3, char *unk4,
                                  uint32_t unk5, uint32_t unk6, uint8_t unk7, uint32_t unk8, bool unk9, uint32_t eMinigameId);

        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
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
        uint32_t field_0x68;
        uint32_t field_0x6C;
        uint32_t field_0x70;
    };
} // namespace mc

#endif //CLIENTBOUNDPRELOGINPACKET_H
