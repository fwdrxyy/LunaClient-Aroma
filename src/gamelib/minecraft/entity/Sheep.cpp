#include "Sheep.h"

#include <Link/Link.h>

namespace mc {
    Sheep::Sheep(Level* _level) {
        Link::Func<void, 0x0287f8b8, Sheep*, Level*>()(this, _level);
    }

    void Sheep::registerGoals() {
        Link::Func<void, 0x028802C0, Sheep*>()(this);
    }

    uint64_t Sheep::GetType() {
        return Link::Func<uint64_t, 0x028ce45c>()();
    }
}