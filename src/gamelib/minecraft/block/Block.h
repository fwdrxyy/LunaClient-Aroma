#pragma once

#include <utils/Types.h>

#include <minecraft/block/BlockPos.h>
#include <minecraft/utils/AABB.h>
#include <minecraft/world/Level.h>

namespace mc {
    class SoundType;
    class Item;

    class Block {
    public:
        uint32_t defaultBlockState();

        static Block *byId(int id);
        static Block *byItem(Item *item);

        bool isIndestructible();

        AABB *getOutlineAABB(uint32_t blockState, Level *level, const BlockPos &blockPos);

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
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
        uint32_t field_0x38;
        uint32_t field_0x3C;
        float destroySpeed;
        uint32_t field_0x44;
        uint32_t field_0x48;
        uint32_t field_0x4C;
        uint32_t baseItemType;
        uint32_t field_0x54;
        uint32_t field_0x58;
        SoundType *soundType;
        uint32_t field_0x60;
        uint32_t field_0x64;
        uint32_t field_0x68;
        uint32_t field_0x6C;
        uint32_t field_0x70;
        uint32_t defBlockState;
        uint32_t field_0x78;
        uint32_t field_0x7C;
        uint32_t field_0x80;
        uint32_t field_0x84;
        uint32_t field_0x88;
        uint32_t field_0x8C;
    };
} // namespace mc