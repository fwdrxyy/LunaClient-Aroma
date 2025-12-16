#include "BufferBuilder.h"

#include <Link/Link.h>

namespace mc {
    void BufferBuilder::begin(int mode) { Link::Func<void, 0x02FD1FB4, BufferBuilder *, int>()(this, mode); }

    void BufferBuilder::color(int color, int alpha) { Link::Func<void, 0x2FD36C4, BufferBuilder *, int, int>()(this, color, alpha); }

    void BufferBuilder::vertexUV(float x, float y, float z, float u, float v) {
        Link::Func<void, 0x02FD2AF4, BufferBuilder *, float, float, float, float, float>()(this, x, y, z, u, v);
    }

    void BufferBuilder::vertex(float x, float y, float z, bool fixCoordinates) {
        double fx = fixCoordinates ? (x - Link::Mem(0x109CCC18).as<double>()) : (x);
        double fy = fixCoordinates ? (y - Link::Mem(0x109CCC20).as<double>()) : (y);
        double fz = fixCoordinates ? (z - Link::Mem(0x109CCC28).as<double>()) : (z);

        Link::Func<void, 0x02FD2A34, BufferBuilder *, float, float, float>()(this, fx, fy, fz);
    }

    void BufferBuilder::end() { Link::Func<void, 0x02FD2288, BufferBuilder *>()(this); }
} // namespace mc