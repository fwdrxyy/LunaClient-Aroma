#pragma once

#include <utils/Types.h>

#include <minecraft/container/Inventory.h>
#include <minecraft/network/listener/ClientPacketListener.h>
#include <minecraft/network/listener/ServerGamePacketListenerImpl.h>
#include <minecraft/network/packet/Packet.h>

namespace mc {
    class CraftItemPacket : public Packet {
    public:
        CraftItemPacket(int a, int b, int c);

        static void craft(ClientPacketListener *listener, Inventory *inventory, int32_t craftId, int32_t itemId, int32_t itemAmount, int32_t itemAux);

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
    };
} // namespace mc