#pragma once

#include <utils/Types.h>

#include "Tag.h"

#include "../client/resource/vector.h"

namespace mstd {
    class wstring;
}

namespace mc {
    class ListTag : public Tag {
    public:
        ListTag(int i);

        void add(Tag *tag);
        void getString(int index, const mstd::wstring &str);
        int size();
        void toString(const mstd::wstring &output_str);
        static constexpr int getId() { return 9; }

        mstd::vector<Tag *> tags;
        uint32_t maxSize; // I think
    };
} // namespace mc