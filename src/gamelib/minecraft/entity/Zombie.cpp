#include "Zombie.h"

#include <Link/Link.h>

namespace mc {
    Zombie::Zombie(Level* _level) {
        Link::Func<void, 0x02a3a914, Zombie*, Level*>()(this, _level);
    }
}