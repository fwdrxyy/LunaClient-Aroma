#pragma once

#include <utils/Types.h>

namespace mstd {
    class wstring;
}

namespace mc {
    class TextureAtlas {
    public:
        void addIcon(bool unk, uint32_t x, uint32_t y, const mstd::wstring &iconName);
    };
} // namespace mc