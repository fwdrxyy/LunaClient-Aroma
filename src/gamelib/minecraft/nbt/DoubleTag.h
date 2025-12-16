#pragma once

#include <utils/Types.h>

#include "Tag.h"

namespace mc {
    class DoubleTag : public Tag {
    public:
        static constexpr int getId() { return 6; }

        uint32_t field_0x4;
        double data;
    };
} // namespace mc