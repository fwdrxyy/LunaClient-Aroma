#pragma once

#include <utils/Types.h>

#include "../../client/resource/shared_ptr.h"

namespace mc {
    class Packet;
    class ClientboundSoundPacket;

    class ClientPacketListener {
    public:
        void send(mc_boost::shared_ptr<Packet> packet);
        void sendCommand(uint32_t commandAddr = 0x10303000);
        void handleSoundEvent(const mc_boost::shared_ptr<ClientboundSoundPacket> &packet);
    };
} // namespace mc