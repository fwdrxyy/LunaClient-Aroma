#include "TrackedEntity.h"

#include <Link/Link.h>

namespace mc {
    TrackedEntity::TrackedEntity(mc_boost::shared_ptr<Entity> entity, int32_t unk1, int32_t unk2, int32_t unk3, bool unk4) {
        Link::Func<void, 0x033A7204, TrackedEntity*, mc_boost::shared_ptr<Entity>, int32_t, int32_t, int32_t, bool>()(this, entity, unk1, unk2, unk3, unk4);
    }
}