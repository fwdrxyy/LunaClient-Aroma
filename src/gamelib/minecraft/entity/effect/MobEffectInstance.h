#pragma once

#include <utils/Types.h>

namespace mc {
    class MobEffect;

    class MobEffectInstance {
    public:
        MobEffectInstance(MobEffect *eff);

        int getDuration();
        int getAmplifier();

        MobEffect *effect;
        int duration;
        int amplifier;
        bool field_0xC;
        bool field_0xD;
        bool ambient;
        bool visible;
        uint32_t field_0x10;
    };
} // namespace mc