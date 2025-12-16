#pragma once

#include <utils/Types.h>

#include "Monster.h"

namespace mc {
    class Level;

    class Zombie : public Monster {
    public:
        Zombie(Level *_level);

        uint32_t field_0x730;
        uint32_t field_0x734;
        uint32_t field_0x738;
        uint32_t field_0x73C;
        uint32_t field_0x740;
        uint32_t field_0x744;
        uint32_t field_0x748;
        uint32_t field_0x74C;
    };
} // namespace mc