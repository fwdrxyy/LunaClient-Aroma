#include "MobEffectInstance.h"

#include <Link/Link.h>

namespace mc {
    MobEffectInstance::MobEffectInstance(MobEffect* eff) {
        Link::Func<void, 0x02692ac4, MobEffectInstance*, MobEffect*>()(this, eff);
    }

    int MobEffectInstance::getDuration() {
        return Link::Func<int, 0x02691790, MobEffectInstance*>()(this);
    }

    int MobEffectInstance::getAmplifier() {
        return Link::Func<int, 0x02692df0, MobEffectInstance*>()(this);
    }
}