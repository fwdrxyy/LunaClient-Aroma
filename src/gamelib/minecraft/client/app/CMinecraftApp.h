#pragma once

#include <utils/Types.h>

namespace mstd {
    class wstring;
}

namespace mc {
    class CMinecraftApp {
    public:
        void AddMemoryTextureFile(const mstd::wstring &name, uint8_t *data, uint32_t size);
        static const mstd::wstring &getSkinPathFromId(void *ptr, uint32_t id);

        void SetAppPaused(bool b);
        bool isAppPaused();

        static CMinecraftApp *getInstance();
    };
} // namespace mc