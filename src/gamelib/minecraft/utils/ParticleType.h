#pragma once

#include <utils/Types.h>

#include "ePARTICLE_TYPE.h"

namespace mc {
    class ParticleType {
    public:
        static ParticleType *byId(ePARTICLE_TYPE type);
    };
} // namespace mc