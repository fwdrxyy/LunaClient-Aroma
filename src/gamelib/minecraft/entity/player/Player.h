#pragma once

#include <utils/Types.h>

#include "../LivingEntity.h"
#include "PlayerUID.h"

#include "../../client/resource/shared_ptr.h"

#include "Abilities.h"
#include "FoodData.h"

namespace mc {
    class Level;
    class Block;
    class ItemInstance;
    class Inventory;
    class AbstractContainerMenu;
    class CameraController;

    class Player : public LivingEntity {
    public:
        Player() = default;
        Player(Level *_level, const mstd::wstring &_name);

        void getDisplayName(mstd::wstring &ret);
        bool isAllowedToFly();
        float getEyeHeight();
        void setXuid(const PlayerUID &uid);
        void hurt(DamageSource *source, float dmg);
        bool isAllowedToMine();
        bool isAllowedToAttackAnimals();
        bool isAllowedToUse(Block *block);
        bool isModerator();
        float getUnderwaterLightLevel();
        void setUnderwaterLightLevel(float underwaterLightLevel);
        void addItem(const mc_boost::shared_ptr<ItemInstance> &item);
        void setRespawnPosition(BlockPos *pos, bool isForced);
        float getAbsorptionAmount();
        float getArmorCoverPercentage();
        float getCurrentItemAttackStrengthDelay();
        void jumpFromGround();
        static uint64_t GetType();

        Inventory *inventory;
        uint32_t field_0x5F4;
        uint32_t field_0x5F8;
        uint32_t field_0x5FC;
        AbstractContainerMenu *notInUseContainer;
        AbstractContainerMenu *currentContainer;
        FoodData foodData;
        uint32_t field_0x61C;
        uint32_t field_0x620;
        uint32_t field_0x624;
        uint32_t field_0x628;
        mstd::wstring customSkinPath;
        mstd::wstring customCapePath;
        uint32_t field_0x66C;
        uint32_t field_0x670;
        uint32_t field_0x674;
        uint32_t field_0x678;
        uint32_t field_0x67C;
        uint32_t field_0x680;
        uint32_t field_0x684;
        uint32_t field_0x688;
        uint32_t field_0x68C;
        uint32_t field_0x690;
        uint32_t field_0x694;
        uint32_t field_0x698;
        uint32_t field_0x69C;
        mstd::wstring _name;
        bool isSleeping;
        bool field_0x6C1;
        bool field_0x6C2;
        bool field_0x6C3;
        uint32_t field_0x6C4;
        int sleeptimer; // max 0x64
        uint32_t field_0x6CC;
        uint32_t field_0x6D0;
        uint32_t field_0x6D4;
        uint32_t field_0x6D8;
        uint32_t field_0x6DC;
        uint32_t field_0x6E0;
        uint32_t field_0x6E4;
        uint32_t field_0x6E8;
        uint32_t field_0x6EC;
        uint32_t field_0x6F0;
        uint32_t field_0x6F4;
        uint32_t field_0x6F8;
        uint32_t field_0x6FC;
        uint32_t field_0x700;
        uint32_t field_0x704;
        uint32_t field_0x708;
        Abilities abilities;
        uint32_t xpLevel;
        uint32_t rawXp;
        float xpProgress;
        mc_boost::shared_ptr<Entity> thrownItem;
        uint32_t field_0x730;
        float redirection; // default = 0.02f
        uint32_t cooldowns;
        uint32_t field_0x73C;
        mstd::wstring name;
        uint32_t field_0x760;
        uint32_t field_0x764;
        uint32_t field_0x768;
        uint32_t field_0x76C;
        uint32_t field_0x770;
        uint32_t field_0x774;
        uint32_t field_0x778;
        CameraController *field_0x77C; // Is nullptr?
        uint32_t field_0x780;
        PlayerUID uuid;
        PlayerUID uuid2;
        PlayerUID uuid3;
        uint32_t field_0x7C0;
        uint32_t field_0x7C4;
        uint32_t field_0x7C8;
        uint32_t field_0x7CC;
        uint32_t field_0x7D0;
        uint32_t field_0x7D4;
        uint32_t field_0x7D8;
        uint32_t customSkinId;
        uint32_t customCapeId;
        uint32_t colourIndex;
        uint32_t field_0x7E8;
        uint32_t field_0x7EC;
        uint32_t field_0x7F0;
        uint32_t field_0x7F4;
        uint32_t field_0x7F8;
        uint32_t field_0x7FC;
        uint32_t field_0x800;
        uint32_t field_0x804;
        uint32_t field_0x808;
        Entity *entitySpectating;
        uint32_t field_0x810;
        bool positionLocked;
        uint8_t field_0x815;
        uint8_t field_0x816;
        uint8_t field_0x817;
        uint32_t field_0x818;
        uint32_t field_0x81C;
        uint32_t field_0x820;
        uint32_t field_0x824;
        uint32_t field_0x828;
        uint32_t field_0x82C;
        uint32_t field_0x830;
        uint32_t field_0x834;
        uint32_t field_0x838;
        uint32_t field_0x83C;
        float field_0x840;
        float field_0x844;
        float field_0x848;
        float field_0x84C;
        uint32_t field_0x850;
        float field_0x854; // Underwater Light Level
        float field_0x858; // Underwater Vision Scale
        uint32_t field_0x85C;
        uint32_t field_0x860;
        uint32_t field_0x864;
    };
} // namespace mc