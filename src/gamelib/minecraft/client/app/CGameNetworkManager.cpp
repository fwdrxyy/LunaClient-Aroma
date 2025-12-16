#include "CGameNetworkManager.h"

#include "../../../Link/Link.h"

#include <Link/Link.h>

namespace mc {
    CGameNetworkManager *CGameNetworkManager::getInstance() {
        return reinterpret_cast<CGameNetworkManager *>(*reinterpret_cast<uint32_t *>(0x109f83FC));
    }

    bool CGameNetworkManager::IsHost() {
        return Link::Func<bool, 0x02D54BD4, CGameNetworkManager*>()(this);
    }

    void CGameNetworkManager::FakeLocalPlayerJoined() {
        Link::Func<void, 0x02D5AD58>()();
    }
} // namespace mc
