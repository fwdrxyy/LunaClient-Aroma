#pragma once

#include <utils/Types.h>

#include "Entity.h"

#include "../client/resource/shared_ptr.h"

namespace mc {
    class Level;
    class LivingEntity;

    class EvocationFangs : public Entity {
    public:
        EvocationFangs(Level *_level);

        void setOwner(const mc_boost::shared_ptr<LivingEntity> &entity);
        static uint64_t GetType();

        uint32_t field_0x350;
        uint32_t field_0x354;
        uint32_t field_0x358;
        uint32_t field_0x35C;
        uint32_t field_0x360;
        uint32_t field_0x364;
        uint32_t field_0x368;
        uint32_t field_0x36C;
        uint32_t field_0x370;
        uint32_t field_0x374;
        uint32_t field_0x378;
        uint32_t field_0x37C;
        uint32_t field_0x380;
        uint32_t field_0x384;
    };
} // namespace mc