#pragma once

#include <utils/Types.h>

namespace mstd {
    class wstring;
}

namespace mc {
    class BufferedImage;

    class Textures {
    public:
        void loadTexture(BufferedImage *img, int id);
        void bind(int id);
        uint32_t loadMemTexture(const mstd::wstring &str, int unk);
        void reloadall();
        void releaseTexture(int id);
    };
} // namespace mc