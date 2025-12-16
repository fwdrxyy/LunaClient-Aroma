#include "Textures.h"

#include <Link/Link.h>

namespace mc {
    void Textures::loadTexture(struct BufferedImage* img, int id)  {
        Link::Func<void, 0x0338f694, Textures*, struct BufferedImage*, int>()(this, img, id);
    }

    void Textures::bind(int id) {
        Link::Func<void, 0x0338ee78, Textures*, int>()(this, id);
    }

    uint32_t Textures::loadMemTexture(const mstd::wstring& str, int unk) {
        return Link::Func<uint32_t, 0x03391f7c, Textures*, const mstd::wstring&, int>()(this, str, unk);
    } 

    void Textures::reloadall() {
        Link::Func<void, 0x03392de0, Textures*>()(this);
    }

    void Textures::releaseTexture(int id) {
        Link::Func<void, 0x03390cd4, Textures*, int>()(this, id);
    }
}