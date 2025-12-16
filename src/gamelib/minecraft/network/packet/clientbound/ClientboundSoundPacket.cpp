#include "ClientboundSoundPacket.h"

#include <Link/Link.h>

namespace mc {
    ClientboundSoundPacket::ClientboundSoundPacket(SoundEvent* sound, SoundSource::ESoundSource source, double x, double y, double z, float vol, float pitch) {
        Link::Func<void, 0x02229070, ClientboundSoundPacket*, SoundEvent*, SoundSource::ESoundSource, double, double, double, float, float>()(this, sound, source, x, y, z, vol, pitch);
    }

    ClientboundSoundPacket::ClientboundSoundPacket(SoundEvent* sound, float vol, float pitch) {
        Link::Func<void, 0x02229214, ClientboundSoundPacket*, SoundEvent*, float, float>()(this, sound, vol, pitch);
    }
}