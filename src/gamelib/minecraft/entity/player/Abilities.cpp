#include "Abilities.h"

#include <Link/Link.h>

namespace mc {
    bool Abilities::operator==(const Abilities& abilities) {
        return Link::Func<bool, 0x0200e1f4, Abilities*, const Abilities&>()(this, abilities);
    }

    float Abilities::getFlyingSpeed() {
        return Link::Func<float, 0x0200ed38, Abilities*>()(this);
    }

    void Abilities::setFlyingSpeed(float newSpeed) {
        Link::Func<void, 0x0200ed40, Abilities*, float>()(this, newSpeed);
    }

    float Abilities::getWalkingSpeed() {
        return Link::Func<float, 0x0200ed48, Abilities*>()(this);
    }

    void Abilities::setWalkingSpeed(float newSpeed) {
        Link::Func<void, 0x0200ed50, Abilities*, float>()(this, newSpeed);
    }
}