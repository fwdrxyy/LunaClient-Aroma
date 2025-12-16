#pragma once

#include <utils/Types.h>

#include "Common.h"

#include "VTable.h"

namespace mc {
    class VTable_Tag : public VTable {
    public:
        MC_VFUNC(void, class Tag, write);
        MC_VFUNC(void, class Tag, load);
        MC_VFUNC(void, class Tag, toString);
        MC_VFUNC(int, class Tag, getId);
    };
} // namespace mc