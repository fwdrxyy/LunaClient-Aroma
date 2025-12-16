#pragma once

namespace mc {
    class Direction {
    public:
        static Direction *down asm("0x104C24A0 + 0x502200");
        static Direction *up asm("0x104C24A4 + 0x502200");
        static Direction *north asm("0x104C24A8 + 0x502200");
        static Direction *south asm("0x104C24AC + 0x502200");
        static Direction *west asm("0x104C24B0 + 0x502200");
        static Direction *east asm("0x104C24B4 + 0x502200");
    };
} // namespace mc