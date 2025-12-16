#include "MobEffect.h"

#include <Link/Link.h>

namespace mc {
    MobEffect* MobEffect::byId(int id) {
        return Link::Func<MobEffect*, 0x026907a4, int>()(id);
    }

    int MobEffect::getId() {
        return Link::Func<int, 0x026907c0, MobEffect*>()(this);
    }
}