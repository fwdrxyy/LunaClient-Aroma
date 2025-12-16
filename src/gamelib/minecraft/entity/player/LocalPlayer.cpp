#include "LocalPlayer.h"

#include <Link/Link.h>

namespace mc {
    void LocalPlayer::playSound(SoundEvent *sound, float vol, float pitch) {
        Link::Func<void, 0x031EA16C, float, float, LocalPlayer *, SoundEvent *>()(vol, pitch, this, sound);
    }

    void LocalPlayer::setAndBroadcastCustomSkin(uint32_t skinID) { Link::Func<void, 0x031F3A30, LocalPlayer *, uint32_t>()(this, skinID); }

    void LocalPlayer::setAndBroadcastCustomCape(uint32_t capeID) { Link::Func<void, 0x031F3A40, LocalPlayer *, uint32_t>()(this, capeID); }

    float LocalPlayer::getDamageTaken() { return Link::Func<float, 0x031F3A50, LocalPlayer *>()(this); }

    GameType *LocalPlayer::GetGameType() { return Link::Func<GameType *, 0x031f4114, LocalPlayer *>()(this); }

    void LocalPlayer::getCarriedItem(mc_boost::shared_ptr<ItemInstance> &item) {
        Link::Func<void, 0x031F3AC4, LocalPlayer *, mc_boost::shared_ptr<ItemInstance> &>()(this, item);
    }

    bool LocalPlayer::isSneaking() { return Link::Func<bool, 0x031EC5B4, LocalPlayer *>()(this); }

    void LocalPlayer::swing(mc::InteractionHand::EInteractionHand hand) {
        Link::Func<void, 0x031E7D74, LocalPlayer *, mc::InteractionHand::EInteractionHand>()(this, hand);
    }

    void LocalPlayer::openContainer(const mc_boost::shared_ptr<Container> &container) {
        Link::Func<void, 0x031EAAC8, LocalPlayer *, const mc_boost::shared_ptr<Container> &>()(this, container);
    }

    void LocalPlayer::stopUsingItem() { Link::Func<void, 0x031EA444, LocalPlayer *>()(this); }
} // namespace mc