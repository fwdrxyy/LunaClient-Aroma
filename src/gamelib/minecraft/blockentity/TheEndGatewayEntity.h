#pragma once

#include <utils/Types.h>

#include "BlockEntity.h"

namespace mc {
    class CompoundTag;
    class BlockPos;

    class TheEndGatewayEntity : public BlockEntity {
    public:
        void save(CompoundTag *tag);
        void load(CompoundTag *tag);
        void SetExitPortal(BlockPos *pos);

        uint32_t field_0x28;
        uint32_t field_0x2C;
        uint32_t field_0x30;
        BlockPos *exitPortal;
        uint32_t field_0x38;
        uint32_t field_0x3C;
    };
} // namespace mc