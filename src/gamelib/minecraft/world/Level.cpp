#include "Level.h"

#include <Link/Link.h>

#include "../block/BlockPos.h"

namespace mc {
    uint32_t Level::getBlockId(int x, int y, int z) { return Link::Func<uint32_t, 0x0254CCAC, Level *, int, int, int>()(this, x, y, z); }

    uint32_t Level::getBlockId(const BlockPos &pos) { return Link::Func<uint32_t, 0x0254CCAC, Level *, int, int, int>()(this, pos.x, pos.y, pos.z); }

    uint32_t Level::getBlockData(int x, int y, int z) { return Link::Func<uint32_t, 0x0254D800, Level *, int, int, int>()(this, x, y, z); }

    uint32_t Level::getBlockState(const BlockPos &pos) { return Link::Func<uint32_t, 0x0254ca88, Level *, const BlockPos &>()(this, pos); }

    Block *Level::getBlock(const BlockPos &pos) { return Link::Func<Block *, 0x0254D958, Level *, const BlockPos &>()(this, pos); }

    void Level::setData(const BlockPos &pos, int unk, int unk2, bool unk3) {
        Link::Func<void, 0x0254A7E4, Level *, const BlockPos &, int, int, bool>()(this, pos, unk, unk2, unk3);
    }

    int Level::isInWorldBounds(int x, int y, int z) { return Link::Func<int, 0x02546BB4, Level *, int, int, int>()(this, x, y, z); }

    void Level::setBlock(const BlockPos &pos, uint32_t state, int id, bool unk) {
        Link::Func<void, 0x02547678, Level *, const BlockPos &, uint32_t, int, bool>()(this, pos, state, id, unk);
    }

    bool Level::hasSignal(const BlockPos &pos, Direction *dir) { return Link::Func<bool, 0x0256767C, Level *, const BlockPos &, Direction *>()(this, pos, dir); }

    void Level::getPlayerByName(const mc_boost::shared_ptr<Player> &player, const mstd::wstring &name) {
        Link::Func<void, 0x02569ae4, Level *, const mc_boost::shared_ptr<Player> &, const mstd::wstring &>()(this, player, name);
    }

    HitResult *Level::clip(const Vec3 &start, const Vec3 &end, bool unk3, bool unk4, bool unk5, bool unk6, void *unk7, bool unk8) {
        return Link::Func<HitResult *, 0x0254DC20, Level *, const Vec3 &, const Vec3 &, bool, bool, bool, bool, void *, bool>()(this, start, end, unk3, unk4, unk5, unk6,
                                                                                                                                unk7, unk8);
    }

    bool Level::isDay() { return Link::Func<bool, 0x0254DC0C, Level *>()(this); }

    bool Level::isRaining() { return Link::Func<bool, 0x0256B494, Level *>()(this); }

    float32_t Level::getTimeOfDay(float32_t unk1) { return Link::Func<float32_t, 0x0255504C, Level *, float32_t>()(this, unk1); }
} // namespace mc