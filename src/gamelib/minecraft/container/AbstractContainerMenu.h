#pragma once

#include <utils/Types.h>

#include "../client/resource/shared_ptr.h"
#include "../client/resource/vector.h"

namespace mc {
    class ItemInstance;

    class AbstractContainerMenu {
    public:
        mstd::vector<mc_boost::shared_ptr<ItemInstance>> &getItems();
    };
} // namespace mc