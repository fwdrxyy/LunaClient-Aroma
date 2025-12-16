#pragma once

#include <utils/Types.h>

namespace mc {
    class GameType {
    public:
        static GameType *byId(int id);
        int getId();
    };
} // namespace mc