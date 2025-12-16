#include "TippableArrow.h"

#include <Link/Link.h>

namespace mc {
    uint64_t TippableArrow::GetType() {
        return Link::Func<uint64_t, 0x02a131a4>()();
    }
}