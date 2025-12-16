#pragma once

#include <utils/Types.h>

#include "Entity.h"

namespace mc {
    class Level;
    class ParticleType;
    class Potion;

    class AreaEffectCloud : public Entity {
    public:
        AreaEffectCloud(Level *_level);

        int getDuration();
        void setDuration(int dur);
        void setParticle(ParticleType *type);
        void setRadius(float r);
        void particleSpawnRateOnTick(int rate);
        void setPotion(Potion *potion);
        void setRadiusPerTick(float r);
        void setRadiusOnUse(float r);
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
        uint32_t field_0x388;
        uint32_t field_0x38C;
        uint32_t field_0x390;
        uint32_t field_0x394;
        uint32_t field_0x398;
        uint32_t field_0x39C;
        uint32_t field_0x3A0;
        uint32_t field_0x3A4;
        uint32_t field_0x3A8;
        uint32_t field_0x3AC;
        uint32_t field_0x3B0;
        uint32_t field_0x3B4;
        uint32_t field_0x3B8;
        uint32_t field_0x3BC;
    };
} // namespace mc