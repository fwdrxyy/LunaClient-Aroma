#pragma once

#include <utils/Types.h>

namespace mstd {
    class wstring;
}

namespace mc {
    class CProfile {
    public:
        static CProfile *GetProfile();

        void CreatePresenceString(uint32_t id, const mstd::wstring &wcstr);
        void SetPresenceString(uint32_t id);
    };
} // namespace mc