#pragma once

#include <utils/Types.h>

#include "../../client/resource/wstring.h"

namespace mc {
    class SavedData {
    public:
        SavedData(const mstd::wstring &str);

        void setDirty(bool state);
        void setDirty();
        bool isDirty() const;

        uint32_t field_0x0;
        uint32_t field_0x4;
        // 0x4
        mstd::wstring str;
        bool field_0x25;
        bool field_0x26;
        bool field_0x27;
        bool dirty;
        uint32_t field_0x2C;
    };
} // namespace mc