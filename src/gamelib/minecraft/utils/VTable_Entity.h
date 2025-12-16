#pragma once

#include <utils/Types.h>

#include "VTable.h"

namespace mc {
    class Entity;

    class VTable_Entity : public VTable {
    public:
        MC_VFUNC(uint64_t, Entity, GetType);
    };
} // namespace mc