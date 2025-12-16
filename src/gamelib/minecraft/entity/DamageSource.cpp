#include "DamageSource.h"

#include <Link/Link.h>

namespace mc {
    DamageSource* DamageSource::CreatePlayerAttack(const mc_boost::shared_ptr<Player>& player) {
        return Link::Func<DamageSource*, 0x02252ac4, const mc_boost::shared_ptr<Player>&>()(player);
    }
}