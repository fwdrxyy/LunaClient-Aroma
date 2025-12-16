#include "ServerPlayerGameMode.h"

#include <Link/Link.h>

namespace mc {
    ServerPlayerGameMode::ServerPlayerGameMode(Level *level, MasterGameMode *masterGamemode) {
        Link::Func<void, 0x0329A940, ServerPlayerGameMode *, Level *, MasterGameMode *>()(this, level, masterGamemode);
    }

    void ServerPlayerGameMode::getServerPlayer(mc_boost::shared_ptr<ServerPlayer> &player) {
        Link::Func<void, 0x032DE5D8, ServerPlayerGameMode *, mc_boost::shared_ptr<ServerPlayer> &>()(this, player);
    }

    void ServerPlayerGameMode::destroyBlock(const BlockPos &pos) {
        Link::Func<void, 0x032de9d8, ServerPlayerGameMode *, const BlockPos &>()(this, pos);
    }
} // namespace mc