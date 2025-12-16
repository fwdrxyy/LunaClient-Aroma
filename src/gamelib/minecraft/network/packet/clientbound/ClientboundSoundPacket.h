#pragma once

#include <utils/Types.h>

#include "../../../utils/SoundSource.h"
#include "../Packet.h"

namespace mc {
    class SoundEvent;

    class ClientboundSoundPacket : public Packet {
    public:
        ClientboundSoundPacket(SoundEvent *sound, SoundSource::ESoundSource source, double x, double y, double z, float vol, float pitch);
        ClientboundSoundPacket(SoundEvent *sound, float vol = 1.0f, float pitch = 1.0f);

        uint32_t field_0x10;
        uint32_t field_0x14;
        SoundEvent *sound;
        SoundSource::ESoundSource source;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        float volume;
        float pitch;
        bool playUi;
        bool looping;
        bool field_0x36;
        bool field_0x37;
        uint32_t soundInstance; // idk which type
        int entityId;
    };
} // namespace mc