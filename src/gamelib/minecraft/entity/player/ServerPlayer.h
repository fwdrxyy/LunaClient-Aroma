#pragma once

#include <utils/Types.h>

#include <minecraft/client/resource/shared_ptr.h>
#include <minecraft/client/resource/wstring.h>
#include <minecraft/entity/player/Player.h>
#include <minecraft/network/server/MinecraftServer.h>
#include <minecraft/utils/InteractionHand.h>
#include <minecraft/world/ServerLevel.h>
#include <minecraft/world/gamemode/ServerPlayerGameMode.h>

namespace mc {
    class ServerPlayerGameMode;
    class ServerGamePacketListenerImpl;
    class Container;
    class SignBlockEntity;
    class GameType;

    class ServerPlayer : public Player {
    public:
        ServerPlayer(MinecraftServer *server, ServerLevel *level, const mstd::wstring &unk1, ServerPlayerGameMode *gamemode);

        void setupForSpawn();

        void teleportTo(double _x, double _y, double _z);
        void disconnect();
        void tick();
        void swing(InteractionHand::EInteractionHand hand);
        void attack(const mc_boost::shared_ptr<Entity> &entity);
        bool isSpectator();
        bool isCreative();
        void openContainer(const mc_boost::shared_ptr<Container> &cont);
        void closeContainer();
        void openTextEdit(const mc_boost::shared_ptr<SignBlockEntity> &entity);
        void giveExperienceLevels(int _level);
        void setGameMode(const GameType *_type);
        GameType *getGameType();
        void refreshContainer(AbstractContainerMenu *_container);
        void addEffect(MobEffectInstance *effect, const mc_boost::shared_ptr<Entity> &entity);
        static uint64_t GetType();
        void startRiding(const mc_boost::shared_ptr<Entity> &ent);
        void onUpdateAbilities();

        ServerPlayerGameMode *gamemode;
        ServerGamePacketListenerImpl *listener;
        MinecraftServer* server;
        uint32_t field_0x878;
        uint32_t field_0x87C;
        uint32_t field_0x890;
        uint32_t field_0x894;
        uint32_t field_0x898;
        uint32_t field_0x89C;
        uint32_t field_0x8A0;
        uint32_t field_0x8A4;
        uint32_t field_0x8A8;
        uint32_t field_0x8AC;
        uint32_t field_0x8B0;
        uint32_t field_0x8B4;
        uint32_t field_0x8B8;
        uint32_t field_0x8BC;
        uint32_t field_0x8C0;
        uint32_t field_0x8C4;
        uint32_t field_0x8C8;
        uint32_t field_0x8CC;
        uint32_t field_0x8D0;
        uint32_t field_0x8D4;
        uint32_t field_0x8D8;
        uint32_t field_0x8DC;
        uint32_t field_0x8E0;
        uint32_t field_0x8E4;
        uint32_t field_0x8E8;
        uint32_t field_0x8EC;
        uint32_t field_0x8F0;
        uint32_t field_0x8F4;
        uint32_t field_0x8F8;
        uint32_t field_0x8FC;
        uint32_t field_0x900; // Send Update Packet???
        uint32_t field_0x904;
        uint32_t field_0x908;
        uint32_t field_0x90C;
        uint32_t field_0x910;
        uint32_t field_0x914;
        uint32_t field_0x918;
        uint32_t field_0x91C;
        uint32_t field_0x920;
        uint32_t field_0x924;
        uint32_t field_0x928;
        uint32_t field_0x92C;
        uint32_t field_0x930;
        uint32_t field_0x934;
        uint32_t field_0x938;
        uint32_t field_0x93C;
        uint32_t field_0x940;
        uint32_t field_0x944;
    };
} // namespace mc