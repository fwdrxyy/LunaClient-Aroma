#pragma once

#include <utils/Types.h>

#include "Animal.h"

namespace mc {
    class Level;
    class VTable_Entity;

    class Sheep : public Animal {
    public:
        Sheep(Level *_level);

        void registerGoals();
        static uint64_t GetType();

        DEFINE_STATIC_DEF_VAR(VTable_Entity *, vtbl, 0x10242E30);

        uint32_t field_0x780;
        uint32_t field_0x784;
        uint32_t field_0x788;
        uint32_t field_0x78C;
        uint32_t field_0x790;
        uint32_t field_0x794;
    };
} // namespace mc