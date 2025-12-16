#include "ClientboundChatPacket.h"

#include <Link/Link.h>

namespace mc {
    ClientboundChatPacket::ClientboundChatPacket(const mstd::wstring& str) {
        uint32_t temp[20]; 
        Link::Func<void, 0x021b7408, ClientboundChatPacket*, const mstd::wstring&, uint32_t[], int>()(this, str, temp, 0x46);
    }
}