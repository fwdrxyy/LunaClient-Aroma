#include "Block.h"

#include <Link/Link.h>

namespace mc {
    uint32_t Block::defaultBlockState() { return Link::Func<uint32_t, 0x020C9700, Block *>()(this); }

    Block *Block::byId(int id) { return Link::Func<Block *, 0x02019F40, int>()(id); }

    Block *Block::byItem(struct Item *item) { return Link::Func<Block *, 0x020e634c, struct Item *>()(item); }

    bool Block::isIndestructible() { return Link::Func<bool, 0x020E75AC, Block *>()(this); }

    AABB *Block::getOutlineAABB(uint32_t blockState, Level *level, const BlockPos &blockPos) {
        return Link::Func<AABB *, 0x020E7B9C, Block *, uint32_t, Level *, const BlockPos &>()(this, blockState, level, blockPos);
    }
} // namespace mc