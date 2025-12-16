#include "Player.h"

#include "minecraft/entity/PrimedTnt.h"

#include <Link/Link.h>

namespace mc {
    Player::Player(Level* _level, const mstd::wstring& _name) {
		Link::Func<void, 0x0270E1A8, Player*, Level*, const mstd::wstring&>()(this, _level, _name);
	}

    void Player::getDisplayName(mstd::wstring& ret) {
		Link::Func<void, 0x026D2EDC, Player*, mstd::wstring&>()(this, ret);
	}
		
	bool Player::isAllowedToFly() {
		return Link::Func<bool, 0x0271AA10, Player*>()(this);
	}

    float Player::getEyeHeight() {
		return Link::Func<float, 0x027272C8, Player*>()(this);
	}
		
	void Player::setXuid(const PlayerUID& uid) {
		Link::Func<void, 0x0272A178, Player*, const PlayerUID&>()(this, uid);
	}

	void Player::hurt(DamageSource* source, float dmg) {
		Link::Func<void, 0x0271aa90, Player*, DamageSource*, float>()(this, source, dmg);
	}

	bool Player::isAllowedToMine() {
		return Link::Func<bool, 0x0272B284, Player*>()(this);
	}

	bool Player::isAllowedToAttackAnimals() {
		return Link::Func<bool, 0x0272B304, Player*>()(this);
	}

	bool Player::isAllowedToUse(Block* block) {
		return Link::Func<bool, 0x0272a584, Player*, Block*>()(this, block);
	}

	bool Player::isModerator() {
		return Link::Func<bool, 0x0272B714, Player*>()(this);
	}

	float Player::getUnderwaterLightLevel() {
		return Link::Func<float, 0x0272CEE0, Player*>()(this);
	}

	void Player::setUnderwaterLightLevel(float underwaterLightLevel) {
		Link::Func<void, 0x0272CEE8, Player*, float>()(this, underwaterLightLevel);
	}

	void Player::addItem(const mc_boost::shared_ptr<ItemInstance>& item) {
		Link::Func<void, 0x027265c4, Player*, const mc_boost::shared_ptr<ItemInstance>&>()(this, item);
	}

	void Player::setRespawnPosition(BlockPos* pos, bool isForced) {
		Link::Func<void, 0x02721D64, Player*, BlockPos*, bool>()(this, pos, isForced);
	}

	float Player::getAbsorptionAmount() {
		return Link::Func<float, 0x02727718, Player*>()(this);
	}

	float Player::getArmorCoverPercentage() {
		return Link::Func<float, 0x0271b884, Player*>()(this);
	}

	float Player::getCurrentItemAttackStrengthDelay() {
		return Link::Func<float, 0x02728794, Player*>()(this);
	}

	void Player::jumpFromGround() {
		Link::Func<void, 0x02721E08, Player*>()(this);
	}

	uint64_t Player::GetType() {
		return Link::Func<uint64_t, 0x027CD2F4>()();
	}

	// void setItemSlot(EquipmentSlot const * slot, ItemInstance* item) {
	// 	Link::Func<void, 0x02725F70, Player*, EquipmentSlot const *, ItemInstance*>()(this, slot, item);
	// }
}