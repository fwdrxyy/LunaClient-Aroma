#include "PrimedTnt.h"

#include <Link/Link.h>

namespace mc {
    PrimedTnt::PrimedTnt(Level* _level) {
        Link::Func<void, 0x027E80E0, PrimedTnt*, Level*>()(this, _level);
    }
        
    void PrimedTnt::setFuse(int fuse) {
        Link::Func<void, 0x027e826c, PrimedTnt*, int>()(this, fuse);
    }

    uint64_t PrimedTnt::GetType() {
        return Link::Func<uint64_t, 0x02864e98>()();
    }
}