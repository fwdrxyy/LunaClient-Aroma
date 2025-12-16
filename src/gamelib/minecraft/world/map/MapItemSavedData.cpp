#include "MapItemSavedData.h"

#include <Link/Link.h>

namespace mc {
    void MapItemSavedData::HoldingPlayer::markDirty(int x, int y) {
        if (field_0x8 != 0x00) {
            int tempx = field_0xC;
            if (x < (int) field_0xC) tempx = x;

            int tempy = field_0x10;
            if (y < (int) field_0x10) tempy = y;

            field_0xC = tempx;
            if (x < (int) field_0x14) x = field_0x14;

            field_0x10 = tempy;
            if (y < (int) field_0x18) y = field_0x18;

            field_0x14 = x;
            field_0x18 = y;
            return;
        }

        field_0xC  = x;
        field_0x8  = 0x01;
        field_0x18 = y;
        field_0x10 = y;
        field_0x14 = x;
    }

    MapItemSavedData::MapItemSavedData(const mstd::wstring &str)
        : SavedData(str) {
        Link::Func<MapItemSavedData *, 0x025c5aa4, MapItemSavedData *,
                   const mstd::wstring &>()(this, str);
    }

    void MapItemSavedData::load(class CompoundTag *tag) {
        Link::Func<void, 0x025d8670, MapItemSavedData *, class CompoundTag *>()(
                this, tag);
    }

    void MapItemSavedData::save(class CompoundTag *tag) {
        Link::Func<void, 0x025d8eb4, MapItemSavedData *, class CompoundTag *>()(
                this, tag);
    }
} // namespace mc