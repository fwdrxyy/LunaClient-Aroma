#pragma once

#include <utils/Types.h>

#include "Player.h"

namespace mc {
    class GameType;

    class RemotePlayer : public Player {
    public:
        static uint64_t GetType();
        GameType *GetGameType();

        uint32_t field_0x868;
        uint32_t field_0x86C;
        uint32_t field_0x870;
        uint32_t field_0x874;
        uint32_t field_0x878;
        uint32_t field_0x87C;
        uint32_t field_0x880;
        GameType *gameType;
    };
}; // namespace mc