#pragma once

#include <utils/Types.h>

#include "../block/BlockPos.h"
#include "../client/resource/shared_ptr.h"

namespace mc {
    class Entity;
    class AABB;

    class HitResult {
    public:
        HitResult(const mc_boost::shared_ptr<Entity> &entity);

        mc::BlockPos pos;
        uint32_t field_0xC;
        uint32_t field_0x10;
        AABB *aabb;
        uint32_t field_0x18;
        uint32_t field_0x1C;
    };
} // namespace mc