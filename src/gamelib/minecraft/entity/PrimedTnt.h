#pragma once

#include <utils/Types.h>

#include "Entity.h"

namespace mc {
    class Level;
    class VTable_Entity;

    class PrimedTnt : public Entity {
    public:
        PrimedTnt(Level *_level);

        void setFuse(int fuse);

        static uint64_t GetType();

        DEFINE_STATIC_DEF_VAR(VTable_Entity *, vtbl, 0x10225758);

        uint32_t field_0x350;
        uint32_t field_0x354;
        int fuseTimer; // I think
        uint32_t field_0x35C;
    };
} // namespace mc