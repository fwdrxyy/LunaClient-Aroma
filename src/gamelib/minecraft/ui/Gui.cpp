#include "Gui.h"

#include <Link/Link.h>

namespace mc {
    void Gui::addMessage(const mstd::wstring& wstr, int field_0x0, bool field_0x1, bool field_0x2, bool field_0x3, bool field_0x4) {
        Link::Func<void, 0x0313873C, Gui*, const mstd::wstring&, uint32_t, bool, bool, bool, bool>()(this, wstr, field_0x0, field_0x1, field_0x2, field_0x3, field_0x4);
    }

    void Gui::setSingleMessage(const mstd::wstring& wstr, int a, int b) {
        Link::Func<void, 0x031390f8, Gui*, const mstd::wstring&, int, int>()(this, wstr, a, b);
    }  
} 