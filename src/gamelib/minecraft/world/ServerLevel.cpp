#include "ServerLevel.h"

#include <Link/Link.h>

#include "../entity/Entity.h"

namespace mc {
    void ServerLevel::sendParticle(const ParticleType* type, double x, double y, double z, int amount, double unk_0, double unk_1, double unk_2, double unk_3, uint32_t n) {
        uint32_t array[2]  = { 0x0000105F,       0x00000000 };
        uint32_t array2[2] = { (uint32_t) array, 0x00000001 };
        Link::Func<void, 0x032BEFB8, ServerLevel*, const ParticleType*, double, double, double, int, double, double, double, double, uint32_t*, uint32_t>()(this, type, x, y, z, amount, unk_0, unk_1, unk_2, unk_3, array2, n);
    }

    void ServerLevel::sendParticle(const ParticleType* type, double x, double y, double z, int amount, double unk_0, double unk_1, double unk_2, double unk_3, uint32_t n, double r, double g, double b) {
        uint32_t array[2]  = { 0x0000105F,       0x00000000 };
        uint32_t array2[2] = { (uint32_t) array, 0x00000001 };
        Link::Func<void, 0x032bf004, ServerLevel*, const ParticleType*, double, double, double, int, double, double, double, double, uint32_t*, uint32_t, double, double, double>()(this, type, x, y, z, amount, unk_0, unk_1, unk_2, unk_3, array2, n, r, g, b);
    }

    void ServerLevel::addEntity(const mc_boost::shared_ptr<Entity>& entity) {
        Link::Func<void, 0x032C06DC, ServerLevel*, const mc_boost::shared_ptr<Entity>&>()(this, entity->this_shared);
    }

    void ServerLevel::addGlobalEntity(const mc_boost::shared_ptr<Entity>& entity) {
        Link::Func<void, 0x032ba450, ServerLevel*, const mc_boost::shared_ptr<Entity>&>()(this, entity->this_shared);
    }
}