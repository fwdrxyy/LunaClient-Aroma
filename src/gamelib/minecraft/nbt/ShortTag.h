#pragma once

#include <utils/Types.h>

#include "Tag.h"

namespace mc {
    class ShortTag : public Tag {
    public:
        static constexpr int getId() { return 2; }

        short data;
    };
} // namespace mc