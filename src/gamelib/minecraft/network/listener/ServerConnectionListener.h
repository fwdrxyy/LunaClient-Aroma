#pragma once

#include <utils/Types.h>

#include <minecraft/client/resource/shared_ptr.h>
#include <minecraft/client/resource/wstring.h>
#include <minecraft/network/packet/Packet.h>
#include <minecraft/network/server/MinecraftServer.h>

namespace mc {
    class Socket;
    class Connection;

    class ServerConnectionListener {
    public:
        ServerConnectionListener(MinecraftServer *server, Socket *socket, const mstd::wstring &name);

        void send(mc_boost::shared_ptr<Packet> packet);
        void sendPreLoginResponse();

        uint32_t field_0x0;
        Connection *connection;
        uint32_t field_0x8;
        uint32_t field_0xC;
        uint32_t field_0x10;
        mstd::wstring field_0x14;
        uint32_t field_0x34;
        uint32_t field_0x38;
        uint32_t field_0x3C;
        uint32_t field_0x40;
        uint32_t field_0x44;
        uint32_t field_0x48;
        uint32_t field_0x4C;
        uint32_t field_0x50;
        uint32_t field_0x54;
        uint32_t field_0x58;
    };
} // namespace mc