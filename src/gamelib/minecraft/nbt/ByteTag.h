#pragma once

#include <utils/Types.h>

#include "Tag.h"

namespace mc {
    class ByteTag : public Tag {
    public:
        static constexpr int getId() { return 1; }

        uint8_t data;
    };
} // namespace mc