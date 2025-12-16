#include "LivingEntity.h"

#include <Link/Link.h>

namespace mc {
    void LivingEntity::setHealth(float amount) {
        Link::Func<void, 0x02579530, LivingEntity*, float>()(this, amount);
    }

	float LivingEntity::getMaxHealth() {
		return Link::Func<float, 0x0257f6a8, LivingEntity*>()(this);
	}

	int LivingEntity::getArrowCount() {
		return Link::Func<int, 0x0257F6F0, LivingEntity*>()(this);
	}

	void LivingEntity::hurt(DamageSource* source, float dmg) {
		Link::Func<void, 0x025796cc, LivingEntity*, DamageSource*, float>()(this, source, dmg);
	}

	float LivingEntity::getHealth() {
		return Link::Func<float, 0x025793f8, LivingEntity*>()(this);
	}

	uint64_t LivingEntity::GetType() {
		return Link::Func<uint64_t, 0x026027a4>()();
	}

	bool LivingEntity::hasEffect(MobEffect* effect) {
		return Link::Func<bool, 0x025781EC, LivingEntity*, MobEffect*>()(this, effect);
	}

	MobEffectInstance* LivingEntity::getEffect(MobEffect* effect) {
		return Link::Func<MobEffectInstance*, 0x0257822c, LivingEntity*, MobEffect*>()(this, effect);
	}

	int LivingEntity::getFallFlyingTicks() {
		return Link::Func<int, 0x0258dae0, LivingEntity*>()(this);
	}

	void LivingEntity::addEffect(MobEffectInstance* effect) {
		Link::Func<void, 0x0257840C, LivingEntity*, MobEffectInstance*>()(this, effect);
	}
}