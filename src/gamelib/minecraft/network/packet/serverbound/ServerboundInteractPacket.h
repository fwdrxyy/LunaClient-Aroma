#pragma once

#include <utils/Types.h>

#include "../Packet.h"

#include "../../../utils/InteractionHand.h"

#include "../../../client/resource/shared_ptr.h"

namespace mc {
    class Entity;

    class ServerboundInteractPacket : public Packet {
    public:
        ServerboundInteractPacket(const mc_boost::shared_ptr<Entity> &entity);
        ~ServerboundInteractPacket();

        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t entityId;
        InteractionHand::EInteractionHand action;
        uint32_t field_0x20;
        uint32_t field_0x24;
    };
} // namespace mc