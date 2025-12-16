#pragma once

#include <utils/Types.h>

namespace mc {
    class MobEffect {
    public:
        enum EffectId {
            NOTHING,
            SPEED,
            SLOWNESS,
            HASTE,
            MINING_FATIGUE,
            STRENGTH,
            INSTANT_HEALTH,
            INSTANT_DAMAGE,
            JUMP_BOOST,
            NAUSEA,
            REGENERATION,
            RESISTANCE,
            FIRE_RESISTANCE,
            WATER_BREATHING,
            INVISIBILITY,
            BLINDNESS,
            NIGHT_VISION,
            HUNGER,
            WEAKNESS,
            POISON,
            WITHER,
            HEALTH_BOOST,
            ABSORPTION,
            SATURATION,
            GLOWING,
            LEVITATION,
            LUCK,
            BAD_LUCK
        };

        static MobEffect *byId(int id);
        int getId();
    };
} // namespace mc