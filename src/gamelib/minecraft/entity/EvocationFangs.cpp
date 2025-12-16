#include "EvocationFangs.h"

#include <Link/Link.h>

namespace mc {
    EvocationFangs::EvocationFangs(Level* _level) {
        Link::Func<void, 0x023ab89c, EvocationFangs*, Level*>()(this, _level);
    }

    void EvocationFangs::setOwner(const mc_boost::shared_ptr<LivingEntity>& entity) {
        Link::Func<void, 0x023ba764, EvocationFangs*, const mc_boost::shared_ptr<LivingEntity>&>()(this, entity);
    }

    uint64_t EvocationFangs::GetType() {
        return Link::Func<uint64_t, 0x023e6fd8>()();
    }
}