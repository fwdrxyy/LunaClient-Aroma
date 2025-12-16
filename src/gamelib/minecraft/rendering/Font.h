#pragma once

#include <utils/Types.h>

#include "../client/resource/wstring.h"

#define FONT_CHAR_HEIGHT 8

namespace mc {
    class Font {
    public:
        int width(const mstd::wstring &wstr);
        void drawShadow(const mstd::wstring &wstr, uint32_t arg1, uint32_t arg2, uint32_t arg3);
        void draw(const mstd::wstring &wstr, uint32_t arg1, uint32_t arg2, uint32_t arg3);
    };
} // namespace mc