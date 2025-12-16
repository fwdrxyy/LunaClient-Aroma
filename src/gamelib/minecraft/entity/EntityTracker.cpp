#include "EntityTracker.h"

#include <Link/Link.h>

namespace mc {
    void EntityTracker::addEntity(mc_boost::shared_ptr<Entity> entity, int32_t unk1, int32_t unk2, bool unk3) {
        Link::Func<void, 0x0312C630, EntityTracker *, mc_boost::shared_ptr<Entity>, int32_t, int32_t, bool>()(this, entity, unk1, unk2, unk3);
    }
} // namespace mc