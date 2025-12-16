#include "ServerConnectionListener.h"

#include <Link/Link.h>

namespace mc {
    ServerConnectionListener::ServerConnectionListener(MinecraftServer *server, Socket *socket, const mstd::wstring &name) {
        Link::Func<void, 0x03304FFC, ServerConnectionListener *, MinecraftServer *, Socket *, const mstd::wstring &>()(this, server, socket, name);
    }

    void ServerConnectionListener::send(mc_boost::shared_ptr<Packet> packet) {
        Link::Func<void, 0x03308B3C, ServerConnectionListener *, mc_boost::shared_ptr<Packet>>()(this, packet);
    }

    void ServerConnectionListener::sendPreLoginResponse() {
        Link::Func<void, 0x0330727C, ServerConnectionListener*>()(this);
    }
} // namespace mc