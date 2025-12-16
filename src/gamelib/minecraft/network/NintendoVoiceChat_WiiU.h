#ifndef NINTENDOVOICECHAT_WIIU_H
#define NINTENDOVOICECHAT_WIIU_H

#include "../client/resource/vector.h"
#include "NQRNetworkPlayer.h"

namespace mc {
    class NintendoVoiceChat_WiiU {
    public:
        static mstd::vector<NQRNetworkPlayer*> getPlayers();
        static void addPlayer(NQRNetworkPlayer *player);
        static void removePlayer(NQRNetworkPlayer *player);
    };
} // namespace mc

#endif // NINTENDOVOICECHAT_WIIU_H
