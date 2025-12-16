#include "PlayerUID.h"

#include <Link/Link.h>

namespace mc {
    PlayerUID::PlayerUID(int32_t unk1) { Link::Func<void, 0x034A2684, PlayerUID *, int32_t>()(this, unk1); }

    bool PlayerUID::operator==(const PlayerUID &playerUID) const {
        return Link::Func<bool, 0x034a39c8, const PlayerUID *, const PlayerUID &>()(this, playerUID);
    }

    bool PlayerUID::operator!=(const PlayerUID &playerUID) const {
        return Link::Func<bool, 0x034a3a80, const PlayerUID *, const PlayerUID &>()(this, playerUID);
    }
} // namespace mc