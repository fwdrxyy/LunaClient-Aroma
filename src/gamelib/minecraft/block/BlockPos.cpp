#include "BlockPos.h"

#include <Link/Link.h>

namespace mc {
    BlockPos::BlockPos(int x, int y, int z) { Link::Func<BlockPos *, 0x020c3ad4, BlockPos *, int, int, int>()(this, x, y, z); }

    BlockPos BlockPos::operator+(const mc::BlockPos &pos) const { return BlockPos(x + pos.x, y + pos.y, z + pos.z); }

    BlockPos BlockPos::operator-(const mc::BlockPos &pos) const { return BlockPos(x - pos.x, y - pos.y, z - pos.z); }

    bool BlockPos::operator==(const BlockPos &pos) { return Link::Func<bool, 0x020c4bf4, BlockPos *, const BlockPos &>()(this, pos); }

    bool BlockPos::operator!=(const BlockPos &pos) { return Link::Func<bool, 0x020c4c04, BlockPos *, const BlockPos &>()(this, pos); }
} // namespace mc