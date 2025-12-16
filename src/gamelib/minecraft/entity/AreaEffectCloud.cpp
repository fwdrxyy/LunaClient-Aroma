#include "AreaEffectCloud.h"

#include <Link/Link.h>

namespace mc {
    AreaEffectCloud::AreaEffectCloud(Level* _level) {
        Link::Func<void, 0x02085B3C, AreaEffectCloud*, Level*>()(this, _level);
    }

    int AreaEffectCloud::getDuration() {
        return Link::Func<int, 0x02086C14, AreaEffectCloud*>()(this);
    }

    void AreaEffectCloud::setDuration(int dur) {
        Link::Func<void, 0x02086C1C, AreaEffectCloud*, int>()(this, dur);
    }

    void AreaEffectCloud::setParticle(ParticleType* type) {
        Link::Func<void, 0x02086658, AreaEffectCloud*, ParticleType*>()(this, type);
    }

    void AreaEffectCloud::setRadius(float r) {
        Link::Func<void, 0x02082644, AreaEffectCloud*, float>()(this, r);
    }

    void AreaEffectCloud::particleSpawnRateOnTick(int rate) {
        Link::Func<void, 0x020869cc, AreaEffectCloud*, int>()(this, rate);
    }

    void AreaEffectCloud::setPotion(Potion* potion) {
        Link::Func<void, 0x020864b0, AreaEffectCloud*, Potion*>()(this, potion);
    }

    void AreaEffectCloud::setRadiusPerTick(float r) {
        Link::Func<void, 0x02086ea0, AreaEffectCloud*, float>()(this, r);
    }

    void AreaEffectCloud::setRadiusOnUse(float r) {
        Link::Func<void, 0x02086e98, AreaEffectCloud*, float>()(this, r);
    }

    uint64_t AreaEffectCloud::GetType() {
        return Link::Func<uint64_t, 0x020b3cdc>()();
    }
}