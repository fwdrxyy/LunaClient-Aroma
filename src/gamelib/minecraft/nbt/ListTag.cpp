#include "ListTag.h"

#include <Link/Link.h>

namespace mc {
    ListTag::ListTag(int i) {
        Link::Func<void, 0x02573958, ListTag*, int>()(this, i);
    }

    void ListTag::add(Tag* tag) {
        Link::Func<void, 0x02573F8C, ListTag*, Tag*>()(this, tag);
    }

    void ListTag::getString(int index, const mstd::wstring& str) {
        Link::Func<void, 0x02590594, ListTag*, int, const mstd::wstring&>()(this, index, str);
    }

    int ListTag::size() {
        return Link::Func<int, 0x02574f24, ListTag*>()(this);
    }

    void ListTag::toString(const mstd::wstring& output_str) {
        Link::Func<void, 0x0258eee4, ListTag*, const mstd::wstring&>()(this, output_str);
    }
}