#include "RemotePlayer.h"

#include <Link/Link.h>

namespace mc {
    uint64_t RemotePlayer::GetType() {
        return Link::Func<uint64_t, 0x0332d9f4>()();
    }

    GameType* RemotePlayer::GetGameType() {
		return Link::Func<GameType*, 0x032692f8, RemotePlayer*>()(this);
	}
}