#pragma once

#include <utils/Types.h>

#include <Link/Link.h>

#include "Tag.h"

#include "../client/resource/wstring.h"

namespace mc {
    class StringTag : public Tag {
    public:
        StringTag(const mstd::wstring &str) { Link::Func<void, 0x02954a0c, StringTag *, const mstd::wstring &>()(this, str); }

        static constexpr int getId() { return 8; }

        mstd::wstring data;
    };
} // namespace mc