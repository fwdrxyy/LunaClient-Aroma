#pragma once

#include <utils/Types.h>

#include "Tag.h"

#include <minecraft/client/resource/ArrayWithLength.h>

namespace mc {
    class ByteArrayTag : public Tag {
    public:
        static constexpr int getId() { return 7; }

        ArrayWithLength<uint8_t> array;
    };
} // namespace mc