#pragma once

#include <utils/Types.h>

#include "Mob.h"

namespace mc {
    class Level;

    class Slime : public Mob {
    public:
        Slime(Level *_level);

        void setSize(int size, bool unk);

        uint32_t field_0x708;
        uint32_t field_0x70C;
        uint32_t field_0x710;
        uint32_t field_0x714;
    };
} // namespace mc