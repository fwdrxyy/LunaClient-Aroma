#pragma once

#include <utils/Types.h>

#include "BlockEntity.h"

#include "../client/resource/shared_ptr.h"
#include "../client/resource/wstring.h"

namespace mc {
    class Packet;
    class Player;

    class SignBlockEntity : public BlockEntity {
    public:
        void SetMessage(int index, const mstd::wstring &message);
        const mc_boost::shared_ptr<Packet> &getUpdatePacket();
        static uint64_t getType();
        bool executeClickCommands(mc_boost::shared_ptr<Player> player);

        uint32_t field_0x28;
        uint32_t field_0x2C;
        uint32_t field_0x30;
        uint32_t field_0x34;
        uint32_t field_0x38;
        uint32_t field_0x3C;
        uint32_t field_0x40;
        uint32_t field_0x44;
        uint32_t field_0x48;
        uint32_t field_0x4C;
        uint32_t field_0x50;
        mstd::wstring lines[4];
        uint32_t field_0xC8;
        uint32_t field_0xCC;
    };
} // namespace mc