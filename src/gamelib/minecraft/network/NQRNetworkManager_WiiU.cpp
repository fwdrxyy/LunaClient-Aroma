#include "NQRNetworkManager_WiiU.h"

#include <Link/Link.h>

namespace mc {
    void NQRNetworkManager_WiiU::FindOrCreateNonNetworkPlayer(int32_t unk1, int32_t unk2, NQRNetworkManager::PlayerSyncData *unk3) {
        Link::Func<void, 0x0348E228, NQRNetworkManager_WiiU *, int32_t, int32_t, NQRNetworkManager::PlayerSyncData *>()(this, unk1, unk2, unk3);
    }

    void NQRNetworkManager_WiiU::Pia_SignalJoinSession() { Link::Func<void, 0x034931CC, NQRNetworkManager_WiiU *>()(this); }

    void NQRNetworkManager_WiiU::Pia_JoinSession() { Link::Func<void, 0x03492760, NQRNetworkManager_WiiU *>()(this); }
} // namespace mc