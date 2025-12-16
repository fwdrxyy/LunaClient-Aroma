#include "TextureAtlas.h"

#include <Link/Link.h>

namespace mc {
    void TextureAtlas::addIcon(bool unk, uint32_t x, uint32_t y, const mstd::wstring& iconName) {
        Link::Func<void, 0x03366AD4, TextureAtlas*, bool, uint32_t, uint32_t, const mstd::wstring&>()(this, unk, y, x, iconName);
    }
}