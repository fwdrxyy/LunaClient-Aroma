#include "AABB.h"

#include <Link/Link.h>

namespace mc {
    AABB::AABB(double x1, double y1, double z1, double x2, double y2, double z2) {
        Link::Func<void, 0x0200c920, AABB*, double, double, double, double, double, double>()(this, x1, y1, z1, x2, y2, z2);
    }

    AABB::AABB(const AABB& aabb) {
        Link::Func<void, 0x02ca58a8, AABB*, const AABB&>()(this, aabb);
    }

    AABB::AABB(int x1, int y1, int z1, int x2, int y2, int z2) {
        Link::Func<void, 0x0200c920, AABB*, float, float, float, float, float, float>()(this, 
            Link::toFloat(x1), Link::toFloat(y1), Link::toFloat(z1),
            Link::toFloat(x2), Link::toFloat(y2), Link::toFloat(z2)
        );
    }

    AABB::AABB(Vec3 _min, Vec3 _max) {
        Link::Func<void, 0x0200c920, AABB*, double, double, double, double, double, double>()(this, _min.x, _min.y, _min.z, _max.x, _max.y, _max.z);
    }

    AABB::AABB() {
        min = Vec3(0.0);
        max = Vec3(0.0);
    }

    void AABB::set(const AABB* aabb) {
        Link::Func<void, 0x0200cf7c, AABB*, const AABB*>()(this, aabb);
    }

    AABB AABB::move(double x, double y, double z) {
        return Link::Func<AABB, 0x0200d260, AABB*, double, double, double>()(this, x, y, z);
    }

    void AABB::CreateNewThreadStorage() {
        Link::Func<void, 0x0200C76C>()();
    }
}