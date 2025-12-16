#include "Mob.h"

#include <Link/Link.h>

namespace mc {
    void Mob::setNoAi(bool state) {
        Link::Func<void, 0x02651ec4, Mob*, bool>()(this, state);
    }
}