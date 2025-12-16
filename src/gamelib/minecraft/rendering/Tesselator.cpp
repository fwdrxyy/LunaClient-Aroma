#include "Tesselator.h"

#include <Link/Link.h>

namespace mc {
    Tesselator* Tesselator::getInstance() {
        return Link::Func<Tesselator*, 0x3337EF0>()();
    }

    BufferBuilder* Tesselator::getBuilder() {
        return Link::Func<BufferBuilder*, 0x3337EE8, Tesselator*>()(this);
    }
}