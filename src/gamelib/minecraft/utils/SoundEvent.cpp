#include "SoundEvent.h"

#include <Link/Link.h>

#include "CMath.h"

namespace mc {
    void SoundEvent::getName(const mstd::wstring &name) { Link::Func<void, 0x028E11EC, SoundEvent *, const mstd::wstring &>()(this, name); }

    float SoundEvent::getNoteBlockPitch(int count) {
        switch (count) {
            case 0:
                return 0.5f;
            case 12:
                return 1.0f;
            default:
                return mc_powf(2.0f, (-12.0f + Link::toFloat(count)) / 12.0f);
        };
    }
} // namespace mc