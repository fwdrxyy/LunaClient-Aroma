#include "Slime.h"

#include <Link/Link.h>

namespace mc {
    Slime::Slime(Level* _level) {
        Link::Func<void, 0x02940310, Slime*, Level*>()(this, _level);
    }

    void Slime::setSize(int size, bool unk) {
        Link::Func<void, 0x029408a0, Slime*, int, bool>()(this, size, unk);
    }
}