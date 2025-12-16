#include "ServerPlayer.h"

#include <Link/Link.h>

namespace mc {
    ServerPlayer::ServerPlayer(MinecraftServer *server, ServerLevel *level, const mstd::wstring &unk1, ServerPlayerGameMode *gamemode) {
        Link::Func<void, 0x03299F8C, ServerPlayer *, MinecraftServer *, ServerLevel *, const mstd::wstring &, ServerPlayerGameMode *>()(
                this, server, level, unk1, gamemode);
    }

    void ServerPlayer::setupForSpawn() {
        auto* data = new uint32_t[4];
        data[0] = 0x1C1;
        data[1] = 2;
        data[2] = 0x108FD3BC;
        data[3] = reinterpret_cast<uint32_t>(this);
        this->this_shared = mc_boost::shared_ptr<Entity>(this, data);
    }

    void ServerPlayer::teleportTo(double _x, double _y, double _z) {
        Link::Func<void, 0x032d6b74, ServerPlayer *, double, double, double>()(this, _x, _y, _z);
    }

    void ServerPlayer::disconnect() { Link::Func<void, 0x03286798, ServerPlayer *>()(this); }

    void ServerPlayer::tick() { Link::Func<void, 0x032c3114, ServerPlayer *>()(this); }

    void ServerPlayer::swing(InteractionHand::EInteractionHand hand) {
        Link::Func<void, 0x032d8b5c, ServerPlayer *, InteractionHand::EInteractionHand>()(this, hand);
    }

    void ServerPlayer::attack(const mc_boost::shared_ptr<Entity> &entity) {
        Link::Func<void, 0x032d8a3c, ServerPlayer *, const mc_boost::shared_ptr<Entity> &>()(this, entity);
    }

    bool ServerPlayer::isSpectator() { return Link::Func<bool, 0x032d8000, ServerPlayer *>()(this); }

    bool ServerPlayer::isCreative() { return Link::Func<bool, 0x032d8060, ServerPlayer *>()(this); }

    void ServerPlayer::openContainer(const mc_boost::shared_ptr<struct Container> &cont) {
        Link::Func<void, 0x032cc440, ServerPlayer *, const mc_boost::shared_ptr<struct Container> &>()(this, cont);
    }

    void ServerPlayer::closeContainer() { Link::Func<void, 0x032D0800, ServerPlayer *>()(this); }

    void ServerPlayer::openTextEdit(const mc_boost::shared_ptr<struct SignBlockEntity> &entity) {
        Link::Func<void, 0x032CACD0, ServerPlayer *, const mc_boost::shared_ptr<struct SignBlockEntity> &>()(this, entity);
    }

    void ServerPlayer::giveExperienceLevels(int _level) { Link::Func<void, 0x032C2730, ServerPlayer *, int>()(this, _level); }

    void ServerPlayer::setGameMode(const struct GameType *_type) {
        Link::Func<void, 0x032d7f3c, ServerPlayer *, const struct GameType *>()(this, _type);
    }

    GameType *ServerPlayer::getGameType() { return Link::Func<GameType *, 0x032d8f8c, ServerPlayer *>()(this); }

    void ServerPlayer::refreshContainer(struct AbstractContainerMenu *_container) {
        Link::Func<void, 0x032a2264, ServerPlayer *, struct AbstractContainerMenu *>()(this, _container);
    }

    void ServerPlayer::addEffect(struct MobEffectInstance *effect, const mc_boost::shared_ptr<Entity> &entity) {
        Link::Func<void, 0x032c6fd8, ServerPlayer *, struct MobEffectInstance *, const mc_boost::shared_ptr<Entity> &>()(this, effect, entity);
    }

    uint64_t ServerPlayer::GetType() { return Link::Func<uint64_t, 0x0332fc30>()(); }

    void ServerPlayer::startRiding(const mc_boost::shared_ptr<Entity> &ent) {
        Link::Func<void, 0x032ca21c, ServerPlayer *, const mc_boost::shared_ptr<Entity> &>()(this, ent);
    }

    void ServerPlayer::onUpdateAbilities() { Link::Func<void, 0x032d7abc, ServerPlayer *>()(this); }
} // namespace mc