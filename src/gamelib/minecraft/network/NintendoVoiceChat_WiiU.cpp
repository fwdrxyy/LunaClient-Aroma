#include "NintendoVoiceChat_WiiU.h"

#include <Link/Link.h>

namespace mc {
    mstd::vector<NQRNetworkPlayer *> NintendoVoiceChat_WiiU::getPlayers() { return mstd::vector<NQRNetworkPlayer *>(*reinterpret_cast<uint32_t *>(0x10AD2224)); }

    void NintendoVoiceChat_WiiU::addPlayer(NQRNetworkPlayer *player) { Link::Func<void, 0x03472EB0, NQRNetworkPlayer *>()(player); };

    void NintendoVoiceChat_WiiU::removePlayer(NQRNetworkPlayer *player) { Link::Func<void, 0x03472774, NQRNetworkPlayer *>()(player); }
} // namespace mc
