#include "SavedData.h"

#include <Link/Link.h>

namespace mc {
    SavedData::SavedData(const mstd::wstring& str) {
        Link::Func<SavedData*, 0x027EC778, SavedData*, const mstd::wstring&>()(this, str);
    }

    void SavedData::setDirty(bool state) {
        dirty = state;
    }

    void SavedData::setDirty() {
        setDirty(true);
    }

    bool SavedData::isDirty() const {
        return dirty;
    }
}