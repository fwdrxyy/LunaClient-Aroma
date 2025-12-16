#include "AbstractContainerMenu.h"

#include <Link/Link.h>

namespace mc {
    mstd::vector<mc_boost::shared_ptr<ItemInstance>>& AbstractContainerMenu::getItems() {
        return Link::Func<mstd::vector<mc_boost::shared_ptr<ItemInstance>>&, 0x02033EA0, AbstractContainerMenu*>()(this);
    }  
}