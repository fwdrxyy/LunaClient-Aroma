#pragma once

#include <utils/Types.h>

#include "../resource/ArrayWithLength.h"

namespace mc {
    class File;

    class FileInputStream {
    public:
        FileInputStream(const File &file);
        ~FileInputStream();

        char read();
        void read(ArrayWithLength<uint8_t> &arr);
        void skip(int l);
        int filesize();
        void close();

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;

        // Added by david.xf
        int readCount;
    };
} // namespace mc