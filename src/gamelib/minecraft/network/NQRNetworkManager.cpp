#include "NQRNetworkManager.h"

#include <Link/Link.h>

namespace mc {
    NQRNetworkManager::PlayerSyncData::PlayerSyncData() { Link::Func<void, 0x03486A78, PlayerSyncData *>()(this); }
} // namespace mc