#include <minecraft/network/NQRNetworkPlayer.h>

namespace mc {
    wchar_t *NQRNetworkPlayer::getMiiName() { return Link::Func<wchar_t *, 0x0346701C, NQRNetworkPlayer *>()(this); }

} // namespace mc
