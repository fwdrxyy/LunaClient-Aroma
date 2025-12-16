#include "BlockItem.h"

#include <Link/Link.h>

namespace mc {
    BlockItem::BlockItem(Block* block) {
        Link::Func<void, 0x02171ecc, BlockItem*, Block*>()(this, block);
    }

    bool BlockItem::mayPlace(Level* level, const BlockPos& pos, Direction* dir, const mc_boost::shared_ptr<Player>& player, const mc_boost::shared_ptr<ItemInstance>& item) {
        return Link::Func<bool, 0x02173C88, BlockItem*, Level*, const BlockPos&, Direction*, const mc_boost::shared_ptr<Player>&, const mc_boost::shared_ptr<ItemInstance>&>()(this, level, pos, dir, player, item);
    }
}