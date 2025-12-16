#include "Tag.h"

#include <Link/Link.h>

namespace mc {
    Tag::Tag() { Link::Func<void, 0x02994730, Tag *>()(this); }
} // namespace mc