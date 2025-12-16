#include "TheEndGatewayEntity.h"

#include <Link/Link.h>

namespace mc {
    void TheEndGatewayEntity::save(CompoundTag* tag) {
        Link::Func<void, 0x029ECA18, TheEndGatewayEntity*, CompoundTag*>()(this, tag);
    }

    void TheEndGatewayEntity::load(CompoundTag* tag) {
        Link::Func<void, 0x029ECC54, TheEndGatewayEntity*, CompoundTag*>()(this, tag);
    }

    void TheEndGatewayEntity::SetExitPortal(BlockPos* pos) {
        Link::Func<void, 0x0298B7E4, TheEndGatewayEntity*, BlockPos*>()(this, pos);
    }
}