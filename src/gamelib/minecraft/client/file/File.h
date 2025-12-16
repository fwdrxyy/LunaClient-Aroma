#pragma once

#include <utils/Types.h>

namespace mstd {
    class wstring;

    template<typename T>
    class vector;
} // namespace mstd

namespace mc {
    class File {
    public:
        File(const mstd::wstring &path);
        File() = default;

        ~File();

        bool exists();
        bool isDirectory();
        void _delete();
        void getPath(const mstd::wstring &str);
        mstd::vector<File *> &getFiles();
        void getName(const mstd::wstring &name);

        uint32_t field_0x0;
        uint32_t field_0x4;
        uint32_t field_0x8;
        uint32_t field_0xC;
        uint32_t field_0x10;
        uint32_t field_0x14;
        uint32_t field_0x18;
        uint32_t field_0x1C;
    };
} // namespace mc