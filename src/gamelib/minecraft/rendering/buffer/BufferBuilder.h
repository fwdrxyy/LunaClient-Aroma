#pragma once

#include <utils/Types.h>

namespace mc {
    class BufferBuilder {
    public:
        void begin(int mode = 3);
        void color(int color, int alpha);
        void vertexUV(float x, float y, float z, float u, float v);
        void vertex(float x, float y, float z = 0.0f, bool fixCoordinates = false);
        void end();
    };
} // namespace mc