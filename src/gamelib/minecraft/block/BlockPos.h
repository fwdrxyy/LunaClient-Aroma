#pragma once

namespace mc {
    class BlockPos {
    public:
        BlockPos() = default;
        BlockPos(int x, int y, int z);

        BlockPos operator+(const mc::BlockPos &pos) const;
        BlockPos operator-(const mc::BlockPos &pos) const;
        bool operator==(const BlockPos &pos);
        bool operator!=(const BlockPos &pos);

        int x = 0;
        int y = 0;
        int z = 0;
    };
} // namespace mc