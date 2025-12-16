#include "MenuBuilder.h"

#include <Link/Link.h>

#include "../item/ItemInstance.h"

namespace mc {
    void MenuBuilder::ADD(const mc_boost::shared_ptr<ItemInstance>& Instance, const mc_boost::shared_ptr<ItemInstance>& InstanceSharedPtr) {
		ItemInstance::toShared(InstanceSharedPtr, Instance.get());
		Link::Func<void, 0x02F0F424, MenuBuilder*, const mc_boost::shared_ptr<ItemInstance>&>()(this, InstanceSharedPtr);
	}
		
    void MenuBuilder::ITEM_BLOCKSTATE(uint32_t BlockState) {
		Link::Func<void, 0x02eccd20, MenuBuilder*, uint32_t>()(this, BlockState);
	}
}