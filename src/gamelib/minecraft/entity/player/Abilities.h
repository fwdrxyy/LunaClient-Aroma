#pragma once

#include <utils/Types.h>

namespace mc {
    class Abilities {
    public:
        bool operator==(const Abilities &abilities);
        float getFlyingSpeed();
        void setFlyingSpeed(float newSpeed);
        float getWalkingSpeed();
        void setWalkingSpeed(float newSpeed);

        bool isInvulnerable;
        bool isFlying;
        bool canFly;
        bool canInstaBuild;
        float field_0x4;
        float flySpeed;
        float walkSpeed;
    };
} // namespace mc