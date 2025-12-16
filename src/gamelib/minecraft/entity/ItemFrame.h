#pragma once

#include <utils/Types.h>

#include "Entity.h"

namespace mc {
    class ItemFrame : public Entity {
    public:
        static uint64_t GetType();
    };
} // namespace mc