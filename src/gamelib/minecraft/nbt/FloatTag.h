#pragma once

#include <utils/Types.h>

#include "Tag.h"

namespace mc {
    class FloatTag : public Tag {
    public:
        static constexpr int getId() { return 5; }

        float data;
    };
} // namespace mc