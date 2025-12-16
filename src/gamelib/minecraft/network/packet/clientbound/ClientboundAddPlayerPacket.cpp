#include "ClientboundAddPlayerPacket.h"

#include <Link/Link.h>

namespace mc {
    ClientboundAddPlayerPacket::ClientboundAddPlayerPacket(
            mc_boost::shared_ptr<Player> player, PlayerUID _uid1,
            PlayerUID _uid2, int32_t _x, int32_t _y, int32_t _z, int16_t _yaw,
            int16_t _pitch, int32_t unk1) {
        Link::Func<void, 0x021D14D0, ClientboundAddPlayerPacket *,
                   mc_boost::shared_ptr<Player>, PlayerUID, PlayerUID, int32_t,
                   int32_t, int32_t, int32_t, int32_t, uint32_t>()(
                this, player, _uid1, _uid2, _x, _y, _z, _yaw, _pitch, unk1);
    }
} // namespace mc