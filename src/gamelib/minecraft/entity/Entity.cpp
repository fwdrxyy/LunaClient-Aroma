#include "Entity.h"

#include <Link/Link.h>

#include "../utils/VTable_Entity.h"

#include "ItemEntity.h"
#include "PrimedTnt.h"

namespace mc {
    Entity::Entity(Level *level, bool unk1) { Link::Func<void, 0x02329E64, Entity *, Level *, bool>()(this, level, unk1); }

    void Entity::setupForSpawn(const mstd::wstring &name) {
        this->setCustomName(name, L"", false);

        const uint64_t thisType = type();
        auto *data              = new uint32_t[4];
        data[1]                 = 2;
        data[3]                 = reinterpret_cast<uint32_t>(this);
        if (thisType == PrimedTnt::GetType()) {
            data[0] = 2;
            data[2] = 0x10282E38; // boost_detail<PrimedTnt>
        } else if (thisType == ItemEntity::GetType()) {
            data[0] = 3;          // Maybe also 2?
            data[2] = 0x101B9994; // boost_detail<ItemEntity>
        } else {
            data[0] = 3;
            data[2] = reinterpret_cast<uint32_t>(Entity::boost_detail); // boost_detail<Entity>
        }

        this->this_shared = mc_boost::shared_ptr<Entity>(this, data);
    }

    void Entity::setPos(double _x, double _y, double _z) {
        Link::Func<void, 0x023298e0, Entity *, double, double, double>()(this, _x, _y, _z);
    }

    void Entity::setPos(const Vec3 &pos) {
        Link::Func<void, 0x023298e0, Entity *, double, double, double>()(this, pos.x, pos.y, pos.z);
    }

    void Entity::moveTo(double _x, double _y, double _z, float _yaw, float _pitch) {
        Link::Func<void, 0x0233474c, Entity *, double, double, double, float, float>()(this, _x, _y, _z, _yaw, _pitch);
    }

    void Entity::moveTo(const Vec3 &pos, float _yaw, float _pitch) {
        Link::Func<void, 0x0233474c, Entity *, double, double, double, float, float>()(this, pos.x, pos.y, pos.z, _yaw, _pitch);
    }

    float Entity::getEyeHeight() { return Link::Func<float, 0x02347618, Entity *>()(this); }

    uint64_t Entity::type() { return vtable->GetType(this); }

    void Entity::getStringUUID(const mstd::wstring &str) {
        Link::Func<void, 0x0234651C, Entity *, const mstd::wstring &>()(this, str);
    }

    void Entity::getName(mstd::wstring &str) { Link::Func<void, 0x0234174c, Entity *, mstd::wstring &>()(this, str); }

    void Entity::setCustomName(const mstd::wstring &str1, const mstd::wstring &str2, bool unk) {
        Link::Func<void, 0x023467E4, Entity *, const mstd::wstring &, const mstd::wstring &, bool>()(this, str1, str2, unk);
    }

    void Entity::push(double _x, double _y, double _z) {
        Link::Func<void, 0x02334EF4, Entity *, double, double, double>()(this, _x, _y, _z);
    }

    void Entity::push(const Vec3 &pos) {
        Link::Func<void, 0x02334EF4, Entity *, double, double, double>()(this, pos.x, pos.y, pos.z);
    }

    void Entity::startRiding(const mc_boost::shared_ptr<Entity> &entity, bool unk) {
        Link::Func<void, 0x0233BEA0, Entity *, const mc_boost::shared_ptr<Entity> &, bool>()(this, entity, unk);
    }

    const Vec3 &Entity::calculateViewVector() { return Link::Func<const Vec3 &, 0x02334FB8, Entity *>()(this); }

    void Entity::setSilent(bool state) { Link::Func<void, 0x02331394, Entity *, bool>()(this, state); }

    void Entity::setNoGravity(bool state) { Link::Func<void, 0x023314a4, Entity *, bool>()(this, state); }

    void Entity::remove() { Link::Func<void, 0x0232b538, Entity *>()(this); }

    bool Entity::isSneaking() { return Link::Func<bool, 0x02340568, Entity *>()(this); }

    bool Entity::getSharedFlag(int index) { return Link::Func<bool, 0x023369b8, Entity *, int>()(this, index); }

    void Entity::setSharedFlag(int index, bool state) { Link::Func<void, 0x0232bb18, Entity *, int, bool>()(this, index, state); }

    void Entity::setCustomNameVisible(bool state) { Link::Func<void, 0x02347228, Entity *, bool>()(this, state); }

    void Entity::setInvulnerable(bool state) { Link::Func<void, 0x023418dc, Entity *, bool>()(this, state); }
} // namespace mc