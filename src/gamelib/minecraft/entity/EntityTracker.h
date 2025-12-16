#pragma once

#include <utils/Types.h>

#include <minecraft/client/resource/shared_ptr.h>
#include <minecraft/entity/Entity.h>

namespace mc {
    class EntityTracker {
    public:
        void addEntity(mc_boost::shared_ptr<Entity> entity, int32_t unk1, int32_t unk2, bool unk3);

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
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
    };
} // namespace mc