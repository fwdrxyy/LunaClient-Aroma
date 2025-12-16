#pragma once

#include <utils/Types.h>

#include "LivingEntity.h"

namespace mc {
    class Level;
    class EquipmentSlot;
    class ItemInstance;

    class ArmorStand : public LivingEntity {
    public:
        ArmorStand(Level *_level);

        void setShortArms(bool state);
        void setItemSlot(EquipmentSlot *slot, const mc_boost::shared_ptr<ItemInstance> &item);
        static uint64_t GetType();

        uint32_t field_0x5F0;
        uint32_t field_0x5F4;
        uint32_t field_0x5F8;
        uint32_t field_0x5FC;
        uint32_t field_0x600;
        uint32_t field_0x604;
        uint32_t field_0x608;
        uint32_t field_0x60C;
        uint32_t field_0x610;
        uint32_t field_0x614;
        uint32_t field_0x618;
        uint32_t field_0x61C;
        uint32_t field_0x620;
        uint32_t field_0x624;
    };
} // namespace mc