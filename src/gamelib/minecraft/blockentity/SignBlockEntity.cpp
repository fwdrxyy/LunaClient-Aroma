#include "SignBlockEntity.h"

#include <Link/Link.h>

namespace mc {
    class Packet;
    class Player;

    void SignBlockEntity::SetMessage(int index, const mstd::wstring& message) {
		Link::Func<void, 0x02913680, SignBlockEntity*, int, const mstd::wstring&>()(this, index, message);
	}

	const mc_boost::shared_ptr<Packet>& SignBlockEntity::getUpdatePacket() {
		return Link::Func<const mc_boost::shared_ptr<Packet>&, 0x029144b8, SignBlockEntity*>()(this);
	}

	uint64_t SignBlockEntity::getType() {
		return Link::Func<uint64_t, 0x0297BF48>()();
	}

	bool SignBlockEntity::executeClickCommands(mc_boost::shared_ptr<Player> player) {
		return Link::Func<bool, 0x02915610, SignBlockEntity*, mc_boost::shared_ptr<Player>>()(this, player);
	}
}