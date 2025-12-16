#pragma once

#include <utils/Types.h>

#include "Vec3.h"

namespace mc {
    class AABB {
    public:
        AABB(double x1, double y1, double z1, double x2, double y2, double z2);
        AABB(const AABB &aabb);
        AABB(int x1, int y1, int z1, int x2, int y2, int z2);
        AABB(Vec3 _min, Vec3 _max);
        AABB();

        void set(const AABB *aabb);
        AABB move(double x, double y, double z);
        static void CreateNewThreadStorage();

        Vec3 min;
        Vec3 max;
    };
} // namespace mc