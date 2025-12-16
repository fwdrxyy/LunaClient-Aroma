#include "System.h"

#include <Link/Link.h>

namespace mc {
    uint64_t System::processTimeInMilliSecs() {
        return Link::Func<uint64_t, 0x02994408>()();
    }
}