#include "PlayerList.h"

#include <Link/Link.h>

namespace mc {
    int PlayerList::getMaxPlayers() {
        return Link::Func<int, 0x0328CAF8, PlayerList *>()(this);
    }

    int PlayerList::getPlayerCount() {
        return Link::Func<int, 0x032A868C, PlayerList *>()(this);
    }

    void PlayerList::broadcastAll(const mc_boost::shared_ptr<Packet> &packet) {
        Link::Func<void, 0x03286804, PlayerList *,
                   const mc_boost::shared_ptr<Packet> &>()(this, packet);
    }

    void PlayerList::tick() {
        Link::Func<void, 0x032a53fc, PlayerList *>()(this);
    }

    int32_t
    PlayerList::addPlayerToReceiving(mc_boost::shared_ptr<ServerPlayer> player,
                                     bool unk1) {
        return Link::Func<int32_t, 0x03286224, PlayerList *,
                          mc_boost::shared_ptr<ServerPlayer>, bool>()(
                this, player, unk1);
    }

    void PlayerList::add(mc_boost::shared_ptr<ServerPlayer> player) {
        Link::Func<void, 0x0328E7CC, PlayerList *,
                   mc_boost::shared_ptr<ServerPlayer>>()(this, player);
    }

    void PlayerList::placeNewPlayer(
            Connection *connection, mc_boost::shared_ptr<ServerPlayer> player,
            mc_boost::shared_ptr<ClientboundLoginPacket> packet) {
        Link::Func<void, 0x03294B54, PlayerList *, Connection *,
                   mc_boost::shared_ptr<ServerPlayer>,
                   mc_boost::shared_ptr<ClientboundLoginPacket>>()(
                this, connection, player, packet);
    }

    void PlayerList::getPlayerForLogin(ServerConnectionListener *listener,
                                       const mstd::wstring &unk1,
                                       PlayerUID uid1, PlayerUID uid2) {
        Link::Func<void, 0x0329AAC0, PlayerList *, ServerConnectionListener *,
                   const mstd::wstring &, PlayerUID, PlayerUID>()(
                this, listener, unk1, uid1, uid2);
    }
} // namespace mc