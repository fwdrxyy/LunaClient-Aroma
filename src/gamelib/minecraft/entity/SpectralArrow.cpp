#include "SpectralArrow.h"

#include <Link/Link.h>

namespace mc {
    uint64_t SpectralArrow::GetType() {
        return Link::Func<uint64_t, 0x0297dbd0>()();
    }
}