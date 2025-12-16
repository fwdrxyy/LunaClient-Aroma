#include "Painting.h"

#include <Link/Link.h>

namespace mc {
    uint64_t Painting::GetType() {
        return Link::Func<uint64_t, 0x027ce9bc>()();
    }
}