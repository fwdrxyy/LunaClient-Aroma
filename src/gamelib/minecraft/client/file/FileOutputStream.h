#pragma once

#include <utils/Types.h>

#include "../resource/ArrayWithLength.h"

namespace mc {
    class File;

    class FileOutputStream {
    public:
        // Does not check if filePath is a File
        FileOutputStream(const char *filePath, bool shouldAppend = false);
        FileOutputStream(const File &file);
        ~FileOutputStream();

        void write(char c);
        void write(const ArrayWithLength<uint8_t> &arr);
        void close();

        void *vtable;
        int fileHandle;
    };
} // namespace mc