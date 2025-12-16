#include "UIString.h"

#include <Link/Link.h>

namespace mc {
    UIString::UIString(const wchar_t *str) {
        Link::Func<void, 0x02F47938, UIString*, const wchar_t*>()(this, str);
    }

    UIString::~UIString() {
        Link::Func<void, 0x02F47FB4, UIString*, uint32_t>()(this, 2);
    }
}