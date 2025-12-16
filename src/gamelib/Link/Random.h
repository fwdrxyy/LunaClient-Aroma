#pragma once

#include <utils/Types.h>

namespace Link {
    class Random {
    public:
        static uint32_t Lehmer32();

        static uint32_t next(uint32_t min, uint32_t max);
        static float nextFloat();
        static double nextDouble();

        static uint32_t mLehmer;
    };
} // namespace Link