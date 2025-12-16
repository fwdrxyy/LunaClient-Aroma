#pragma once

#include <utils/Types.h>

#include <minecraft/client/resource/shared_ptr.h>
#include <minecraft/entity/EntityTracker.h>
#include <minecraft/world/Level.h>

namespace mc {
    class ParticleType;
    class Entity;

    class ServerLevel : public Level {
    public:
        void sendParticle(const ParticleType *type, double x, double y, double z, int amount, double unk_0, double unk_1, double unk_2, double unk_3,
                          uint32_t n = 0x16600000);
        void sendParticle(const ParticleType *type, double x, double y, double z, int amount, double unk_0, double unk_1, double unk_2, double unk_3,
                          uint32_t n, double r, double g, double b);

        void addEntity(const mc_boost::shared_ptr<Entity> &entity);
        void addGlobalEntity(const mc_boost::shared_ptr<Entity> &entity);

        uint32_t field_0x204;
        EntityTracker *entityTracker;
    };
} // namespace mc