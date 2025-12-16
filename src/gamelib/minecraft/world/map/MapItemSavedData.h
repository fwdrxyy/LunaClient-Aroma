#pragma once

#include "SavedData.h"

#include "../../client/resource/ArrayWithLength.h"
#include "../../client/resource/shared_ptr.h"
#include "../../client/resource/vector.h"

namespace mc {
    class CompoundTag;

    class MapItemSavedData : public SavedData {
    public:
        class HoldingPlayer {
        public:
            void markDirty(int x, int y);

            uint32_t field_0x0;
            uint32_t field_0x4;
            uint8_t field_0x8;
            uint8_t field_0x9;
            uint8_t field_0xA;
            uint8_t field_0xB;
            uint32_t field_0xC;
            uint32_t field_0x10;
            uint32_t field_0x14;
            uint32_t field_0x18;
            uint32_t field_0x1C;
            uint32_t field_0x20;
            uint32_t field_0x24;
            uint32_t field_0x28;
            uint32_t field_0x2C;
            uint32_t field_0x30;
            uint32_t field_0x34;
        };

        MapItemSavedData(const mstd::wstring& str);

        void load(CompoundTag* tag);
        void save(CompoundTag* tag);

        int xCenter;
        int zCenter;
        uint8_t dimension;
        bool trackingPosition;
        bool unlimitedTracking;
        uint8_t scale;
        // 0x3C = Buffer
        // 0x40 = Length
        ArrayWithLength<uint8_t> imgData;
        mstd::vector<mc_boost::shared_ptr<HoldingPlayer>> holdingPlayers;
        uint32_t field_0x54;
        uint32_t field_0x58;
        uint32_t field_0x5C;
        uint32_t field_0x60;
        uint32_t field_0x64;
        uint32_t field_0x68;
        uint32_t field_0x6C;
        uint32_t field_0x70;
        uint32_t field_0x74;
        uint32_t field_0x78;
        uint32_t field_0x7C;
        uint32_t field_0x80;
        uint32_t field_0x84;
        uint32_t field_0x88;
        uint32_t field_0x8C;
        uint32_t field_0x90;
        uint32_t field_0x94;
        uint32_t field_0x98;
        uint32_t field_0x9C;
        uint32_t field_0xA0;
        uint32_t field_0xA4;
    };

    // static_assert(sizeof(MapItemSavedData) == 0xA8);
}