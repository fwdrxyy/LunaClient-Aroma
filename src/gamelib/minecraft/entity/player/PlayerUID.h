#pragma once

#include <utils/Types.h>

namespace mc {
    class PlayerUID {
    public:
        PlayerUID() = default;
        PlayerUID(int32_t unk1);

        bool operator==(const PlayerUID &playerUID) const;
        bool operator!=(const PlayerUID &playerUID) const;

        uint32_t uid[5];
    };
} // namespace mc