#pragma once

#include <utils/Types.h>

#include "../../client/resource/wstring.h"

namespace mc {
    class BufferedImage {
    public:
        BufferedImage(uint8_t *buffer, uint32_t size);

        BufferedImage(const mstd::wstring &path1, bool unk, bool unk2, const mstd::wstring &path2, int unk3);
        int getWidth();
        int getHeight();

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
        uint32_t field_0x20;
        uint32_t field_0x24;
        uint32_t field_0x28;
        uint32_t field_0x2C;
        uint32_t field_0x30;
    };
} // namespace mc