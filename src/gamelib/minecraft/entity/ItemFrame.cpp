#include "ItemFrame.h"

#include <Link/Link.h>

namespace mc {
    uint64_t ItemFrame::GetType() {
        return Link::Func<uint64_t, 0x0252cc3c>()();
    }
}