#include "EmptyMapItem.h"

#include <Link/Link.h>

namespace mc {
    EmptyMapItem::EmptyMapItem() {
        Link::Func<void, 0x022cb770, EmptyMapItem*>()(this);
    }
}