#pragma once

#include <utils/Types.h>

#include <minecraft/block/BlockPos.h>
#include <minecraft/client/resource/shared_ptr.h>
#include <minecraft/entity/player/ServerPlayer.h>
#include <minecraft/world/Level.h>
#include <minecraft/world/gamemode/MasterGameMode.h>

namespace mc {
    class ServerPlayerGameMode {
    public:
        ServerPlayerGameMode(Level *level, MasterGameMode *masterGamemode);

        void getServerPlayer(mc_boost::shared_ptr<ServerPlayer> &player);
        void destroyBlock(const BlockPos &pos);
    };
} // namespace mc