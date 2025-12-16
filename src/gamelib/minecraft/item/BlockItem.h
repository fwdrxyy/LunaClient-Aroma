#pragma once

#include "Item.h"

#include "../client/resource/shared_ptr.h"

namespace mc {
    class Block;
    class Level;
    class BlockPos;
    class Direction;
    class Player;
    class ItemInstance;

    class BlockItem : public Item {
    public:
        BlockItem(Block* block);

        bool mayPlace(Level* level, const BlockPos& pos, Direction* dir, const mc_boost::shared_ptr<Player>& player, const mc_boost::shared_ptr<ItemInstance>& item);

        uint32_t field_0x78;
    };
}