#pragma once

#include <utils/Types.h>

#include "../client/resource/shared_ptr.h"

namespace mc {
    class Player;

    class DamageSource {
    public:
        static DamageSource *CreatePlayerAttack(const mc_boost::shared_ptr<Player> &player);

        uint32_t field_0x0;
        uint32_t field_0x4;
        bool bypassArmor;      // 0225457C # DamageSource::isBypassArmor(const(void))
        bool bypassInvul;      // 0225458C # DamageSource::isBypassInvul(const(void))
        bool bypassGraceInvul; // 02254594 # DamageSource::isBypassGraceInvul(const(void))
        bool bypassMagic;      // 0225459C # DamageSource::isBypassMagic(const(void))
        float foodExhaustion;  // 02254584 # DamageSource::getFoodExhaustion(const(void))
        bool fire;             // 02255AA8 # DamageSource::isFire(const(void))
        bool projectile;       // 02254564 # DamageSource::isProjectile(const(void))
        bool scalesWithDiffy;  // 022545AC # DamageSource::scalesWithDifficulty(const(void))
        bool magic;            // 022545A4 # DamageSource::isMagic(const(void))
        bool explosion;        // 0225456C # DamageSource::isExplosion(const(void))
        bool fireProjectile;   // 02254574 # DamageSource::isFireProjectile(const(void))
        bool field_0x16;       // unused probably
        bool field_0x17;       // unused probably
        uint32_t vtable;
    };
} // namespace mc