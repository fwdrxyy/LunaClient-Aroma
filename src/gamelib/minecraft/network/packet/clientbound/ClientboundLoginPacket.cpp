#include "ClientboundLoginPacket.h"

#include <Link/Link.h>

namespace mc {
    ClientboundLoginPacket::ClientboundLoginPacket(const mstd::wstring &wstr, int32_t unk1, PlayerUID uid1, PlayerUID uid2,
                                                   bool unk2, uint32_t unk3, uint32_t skinId, uint32_t capeId, bool unk4,
                                                   bool unk5) {
        Link::Func<void, 0x021DB1C0, ClientboundLoginPacket *, const mstd::wstring &, int32_t, PlayerUID, PlayerUID, bool,
                   uint32_t, uint32_t, uint32_t, bool, bool>()(this, wstr, unk1, uid1, uid2, unk2, unk3, skinId, capeId, unk4,
                                                               unk5);
    }
} // namespace mc