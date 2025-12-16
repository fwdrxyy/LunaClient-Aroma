#include "ClientboundPreLoginPacket.h"

#include <Link/Link.h>

namespace mc {
    ClientboundPreLoginPacket::ClientboundPreLoginPacket(mstd::wstring hostName, PlayerUID *uid1, uint32_t index, uint8_t unk2,
                                                         uint32_t unk3, char *unk4, uint32_t unk5, uint32_t unk6, uint8_t unk7,
                                                         uint32_t unk8, bool unk9, uint32_t eMinigameId) {
        Link::Func<void, 0x021DCD50, ClientboundPreLoginPacket *, mstd::wstring, PlayerUID *, uint32_t, uint8_t, uint32_t, char *,
                   uint32_t, uint32_t, uint8_t, uint32_t, bool, uint32_t>()(this, hostName, uid1, index, unk2, unk3, unk4, unk5, unk6,
                                                                            unk7, unk8, unk9, eMinigameId);
    }
} // namespace mc