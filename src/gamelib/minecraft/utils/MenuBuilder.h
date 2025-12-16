#pragma once

#include <utils/Types.h>

#include "../client/resource/shared_ptr.h"

namespace mc {
    class ItemInstance;

    class MenuBuilder {
    public:
        void ADD(const mc_boost::shared_ptr<ItemInstance> &Instance, const mc_boost::shared_ptr<ItemInstance> &InstanceSharedPtr);
        void ITEM_BLOCKSTATE(uint32_t BlockState);
    };
} // namespace mc