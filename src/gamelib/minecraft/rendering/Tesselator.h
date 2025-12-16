#pragma once

#include <utils/Types.h>

namespace mc {
    class BufferBuilder;

    class Tesselator {
    public:
        static Tesselator *getInstance();
        BufferBuilder *getBuilder();
    };
} // namespace mc