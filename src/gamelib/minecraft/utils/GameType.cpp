#include "GameType.h"

#include <Link/Link.h>

namespace mc {
    GameType* GameType::byId(int id) {
        return Link::Func<GameType*, 0x02457008, int>()(id);
    }

    int GameType::getId() {
        return Link::Func<int, 0x02456dcc, GameType*>()(this);
    }
}