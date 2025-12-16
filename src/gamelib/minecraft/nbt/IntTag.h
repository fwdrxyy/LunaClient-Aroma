#pragma once

#include <utils/Types.h>

#include "Tag.h"

namespace mc {
    class IntTag : public Tag {
    public:
        static constexpr int getId() { return 3; }

        int data;
    };
} // namespace mc