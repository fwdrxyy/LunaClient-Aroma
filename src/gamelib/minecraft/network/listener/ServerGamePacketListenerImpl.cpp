#include "ServerGamePacketListenerImpl.h"

#include <Link/Link.h>

namespace mc {
    ServerGamePacketListenerImpl::ServerGamePacketListenerImpl(MinecraftServer *_server, Connection *_connection, mc_boost::shared_ptr<ServerPlayer> _player) {
        Link::Func<void, 0x0328C4B8, ServerGamePacketListenerImpl *, MinecraftServer *, Connection *, mc_boost::shared_ptr<ServerPlayer>>()(this, _server, _connection, _player);
    }

    void ServerGamePacketListenerImpl::send(mc_boost::shared_ptr<Packet> packet) {
        Link::Func<void, 0x03249FB4, ServerGamePacketListenerImpl *, mc_boost::shared_ptr<Packet>>()(this, packet);
    }

    void ServerGamePacketListenerImpl::disconnect(DisconnectPacket::eDisconnectReason reason) {
        Link::Func<void, 0x03288878, ServerGamePacketListenerImpl *, DisconnectPacket::eDisconnectReason>()(this, reason);
    }

    void ServerGamePacketListenerImpl::teleport(double x, double y, double z, float yaw, float pitch, bool unk1, bool unk2) {
        Link::Func<void, 0x03293e88, ServerGamePacketListenerImpl *, double, double, double, float, float, bool, bool>()(this, x, y, z, yaw, pitch, unk1, unk2);
    }

    void ServerGamePacketListenerImpl::handleMovePlayer(const mc_boost::shared_ptr<ServerboundMovePlayerPacket> &packet) {
        Link::Func<void, 0x032dc90c, ServerGamePacketListenerImpl *, const mc_boost::shared_ptr<ServerboundMovePlayerPacket> &>()(this, packet);
    }

    void ServerGamePacketListenerImpl::handlePlayerAction(const mc_boost::shared_ptr<ServerboundPlayerActionPacket> &packet) {
        Link::Func<void, 0x032dff9c, ServerGamePacketListenerImpl *, const mc_boost::shared_ptr<ServerboundPlayerActionPacket> &>()(this, packet);
    }

    void ServerGamePacketListenerImpl::handleUseItemOn(const mc_boost::shared_ptr<ServerboundUseItemOnPacket> &packet) {
        Link::Func<void, 0x032e2c64, ServerGamePacketListenerImpl *, const mc_boost::shared_ptr<ServerboundUseItemOnPacket> &>()(this, packet);
    }

    void ServerGamePacketListenerImpl::handleContainerClick(const mc_boost::shared_ptr<ServerboundContainerClickPacket> &packet) {
        Link::Func<void, 0x032e9b10, ServerGamePacketListenerImpl *, const mc_boost::shared_ptr<ServerboundContainerClickPacket> &>()(this, packet);
    }

    void ServerGamePacketListenerImpl::handleSoundEvent(const mc_boost::shared_ptr<ClientboundSoundPacket> &packet) {
        Link::Func<void, 0x032f9d3c, ServerGamePacketListenerImpl *, const mc_boost::shared_ptr<ClientboundSoundPacket> &>()(this, packet);
    }

    void ServerGamePacketListenerImpl::handleChat(const mc_boost::shared_ptr<ClientboundChatPacket> &packet) {
        Link::Func<void, 0x032e68a4, ServerGamePacketListenerImpl *, const mc_boost::shared_ptr<ClientboundChatPacket> &>()(this, packet);
    }
} // namespace mc
