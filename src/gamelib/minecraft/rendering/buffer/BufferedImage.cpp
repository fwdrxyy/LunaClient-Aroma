#include "BufferedImage.h"

#include <Link/Link.h>

namespace mc {
    BufferedImage::BufferedImage(uint8_t* buffer, uint32_t size) {
        Link::Func<void, 0x03029a40, BufferedImage*, uint8_t*, uint32_t>()(this, buffer, size);
    }

    BufferedImage::BufferedImage(const mstd::wstring& path1, bool unk, bool unk2, const mstd::wstring& path2, int unk3) {
        Link::Func<void, 0x03028614, BufferedImage*, const mstd::wstring&, bool, bool, const mstd::wstring&, int>()(this, path1, unk, unk2, path2, unk3);
    }

    int BufferedImage::getWidth() {
        return Link::Func<int, 0x03029c60, BufferedImage*>()(this);
    }

    int BufferedImage::getHeight() {
        return Link::Func<int, 0x03029c68, BufferedImage*>()(this);
    }
}