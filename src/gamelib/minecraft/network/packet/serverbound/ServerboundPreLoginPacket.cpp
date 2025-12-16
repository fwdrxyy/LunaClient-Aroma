#include "ServerboundPreLoginPacket.h"

#include <Link/Link.h>

namespace mc {
    ServerboundPreLoginPacket::ServerboundPreLoginPacket(const mstd::wstring &wstr) {
        Link::Func<void, 0x028AFC9C, ServerboundPreLoginPacket *, const mstd::wstring &>()(this, wstr);
    }
} // namespace mc