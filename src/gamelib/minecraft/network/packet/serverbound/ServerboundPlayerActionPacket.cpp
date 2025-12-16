#include "ServerboundPlayerActionPacket.h"

#include <Link/Link.h>

namespace mc {
    ServerboundPlayerActionPacket::ServerboundPlayerActionPacket(Action action, const BlockPos &pos, const Direction *dir, int arg5) {
        Link::Func<void, 0x028AEC5C, ServerboundPlayerActionPacket *, Action, const BlockPos &, const Direction *, int>()(this, action, pos, dir, arg5);
    }

    ServerboundPlayerActionPacket::~ServerboundPlayerActionPacket() { Link::Func<void, 0x028D0530, ServerboundPlayerActionPacket *>()(this); }
} // namespace mc