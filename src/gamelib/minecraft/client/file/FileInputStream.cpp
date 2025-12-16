#include "FileInputStream.h"

#include <Link/Link.h>

namespace mc {
    FileInputStream::FileInputStream(const File& file) {
        Link::Func<void, 0x023204a4, FileInputStream*, const File&>()(this, file);
        readCount = 0;
    }

    FileInputStream::~FileInputStream() {
        Link::Func<void, 0x02320630, FileInputStream*>()(this);
    }

    char FileInputStream::read() {
        readCount++;
        return Link::Func<char, 0x023206ac, FileInputStream*>()(this);
    }

    void FileInputStream::read(ArrayWithLength<uint8_t>& arr) {
        Link::Func<void, 0x02320788, FileInputStream*, ArrayWithLength<uint8_t>&>()(this, arr);
        readCount += arr.length;
    }

    void FileInputStream::skip(int l) {
        Link::Func<void, 0x02320984, FileInputStream*, int>()(this, l);
    }

    int FileInputStream::filesize() {
        return Link::Func<int, 0x02320990, FileInputStream*>()(this);
    }

    void FileInputStream::close() {
        Link::Func<void, 0x02320938, FileInputStream*>()(this);
    }
}