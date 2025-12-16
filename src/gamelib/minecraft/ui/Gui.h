#pragma once

#include <utils/Types.h>

#include "../client/resource/wstring.h"

namespace mc {
    class Gui {
    public:
        void addMessage(const mstd::wstring &wstr, int field_0x0, bool field_0x1, bool field_0x2, bool field_0x3, bool field_0x4);
        void setSingleMessage(const mstd::wstring &wstr, int a, int b);
    };
}; // namespace mc