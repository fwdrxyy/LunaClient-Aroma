#pragma once

#include <utils/Types.h>

namespace mc {
    class Packet {
    public:
        ~Packet();

        uint64_t time; // 0x0
        uint8_t unk_1; // 0x8
        uint8_t unk_2; // 0x9
        uint8_t unk_3; // 0xA
        uint8_t unk_4; // 0xB
        void *vtbl;    // 0xC
    };
} // namespace mc
