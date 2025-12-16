#pragma once

#include <utils/Types.h>

#include "Entity.h"

#include "../client/resource/shared_ptr.h"

namespace mc {
    class Level;
    class ItemInstance;
    class Player;

    class ItemEntity : public Entity {
    public:
        ItemEntity(Level *_level);
        ItemEntity(Level *_level, double x, double y, double z);
        ItemEntity(Level *_level, double x, double y, double z, const mc_boost::shared_ptr<ItemInstance> &item);

        void setItem(const mc_boost::shared_ptr<ItemInstance> &item);
        void setPickUpDelay(int delay);
        void setNeverPickUp();
        void setDefaultPickUpDelay();
        void playerTouch(const mc_boost::shared_ptr<Player> &player);
        void setShortLifeTime();
        static uint64_t GetType();

        int lifeTime;
        int pickUpDelay;
        uint32_t field_0x358;
        uint32_t field_0x35C;
        uint32_t field_0x360;
        uint32_t field_0x364;
        uint32_t field_0x368;
        uint32_t field_0x36C;
        uint32_t field_0x370;
        uint32_t field_0x374;
        uint32_t field_0x378;
        uint32_t field_0x37C;
        uint32_t field_0x380;
        uint32_t field_0x384;
        uint32_t field_0x388;
        uint32_t field_0x38C;
        uint32_t field_0x390;
        uint32_t field_0x394;
        uint32_t field_0x398;
        uint32_t field_0x39C;
        uint32_t field_0x3A0;
        uint32_t field_0x3A4;
        uint32_t field_0x3A8;
        uint32_t field_0x3AC;
        uint32_t field_0x3B0;
        uint32_t field_0x3B4;
        uint32_t field_0x3B8;
        uint32_t field_0x3BC;
    };
} // namespace mc