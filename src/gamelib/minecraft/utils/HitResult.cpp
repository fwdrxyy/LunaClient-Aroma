#include "HitResult.h"

#include <Link/Link.h>

namespace mc {
    HitResult::HitResult(const mc_boost::shared_ptr<Entity>& entity) {
        Link::Func<void, 0x024F3DAC, HitResult*, const mc_boost::shared_ptr<Entity>&>()(this, entity);
    }
}