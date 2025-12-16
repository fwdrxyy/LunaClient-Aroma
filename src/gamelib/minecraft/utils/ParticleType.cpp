#include "ParticleType.h"

#include <Link/Link.h>

namespace mc {
    ParticleType* ParticleType::byId(ePARTICLE_TYPE type) {
        return Link::Func<ParticleType*, 0x26D9A54, ePARTICLE_TYPE>()(type);
    }
}