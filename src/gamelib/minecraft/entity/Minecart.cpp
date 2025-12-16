#include "Minecart.h"

#include <Link/Link.h>

namespace mc {
    Minecart::Minecart(Level* _level) {
        Link::Func<void, 0x0265261c, Minecart*, Level*>()(this, _level);
    }

    double Minecart::getMaxSpeed() {
        return Link::Func<double, 0x02658a1c>()();
    }
    
    uint64_t Minecart::GetType() {
        return Link::Func<uint64_t, 0x026c4348>()();
    }
}