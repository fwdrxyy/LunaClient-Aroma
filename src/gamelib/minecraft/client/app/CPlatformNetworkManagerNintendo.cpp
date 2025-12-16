#include "CPlatformNetworkManagerNintendo.h"

#include <Link/Link.h>

namespace mc {
    CPlatformNetworkManagerNintendo *CPlatformNetworkManagerNintendo::getInstance() {
        return (CPlatformNetworkManagerNintendo *) (*(uint32_t *) 0x109C91E4);
    }

    NetworkPlayerNintendo *CPlatformNetworkManagerNintendo::addNetworkPlayer(NQRNetworkPlayer *player) {
        return Link::Func<NetworkPlayerNintendo *, 0x03468D14, CPlatformNetworkManagerNintendo *, NQRNetworkPlayer *>()(this,
                                                                                                                        player);
    }

    void CPlatformNetworkManagerNintendo::HandlePlayerJoined(NQRNetworkPlayer *player) {
        Link::Func<void, 0x03469334, CPlatformNetworkManagerNintendo *, NQRNetworkPlayer *>()(this, player);
    }

} // namespace mc