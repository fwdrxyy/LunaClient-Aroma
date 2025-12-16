#include "MinecraftServer.h"

#include <Link/Link.h>

namespace mc {
    MinecraftServer *MinecraftServer::getInstance() { return Link::Mem(0x104CB6FC + 0x502200).as<MinecraftServer *>(); }

    ServerLevel *MinecraftServer::getLevel(int i) { return Link::Func<ServerLevel *, 0x03222954, MinecraftServer *, int>()(this, i); }

    PlayerList *MinecraftServer::getPlayers() { return Link::Func<PlayerList *, 0x03225F74, MinecraftServer *>()(this); }
} // namespace mc