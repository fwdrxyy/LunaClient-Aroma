#pragma once

#include <utils/Types.h>

#include "Tag.h"

namespace mc {
    class LongTag : public Tag {
    public:
        static constexpr int getId() { return 4; }

        uint32_t field_0x4;
        long long data;
    };
} // namespace mc