#include "FileOutputStream.h"

#include <Link/Link.h>

#include "File.h"

#include "../resource/wstring.h"

#include "../../utils/Common.h"

namespace mc {
    int CreateFileA(const char* filePath, uint32_t ui0, uint32_t ui1, void* ptr0, uint32_t mode, uint32_t ui3, int i0) {
        return Link::Func<int, 0x02f21a98, const char*, uint32_t, uint32_t, void*, uint32_t, uint32_t, int>()(filePath, ui0, ui1, ptr0, mode, ui3, i0);
    }
    
    FileOutputStream::FileOutputStream(const char* filePath, bool shouldAppend) {
        vtable = (void*) 0x100f5544;
        fileHandle = CreateFileA(filePath, 0x40000000, 0, 0, shouldAppend ? 4 : 5, 0x80, 0);
    }

    FileOutputStream::FileOutputStream(const File& file) {
        Link::Func<void, 0x02320b24, FileOutputStream*, const File&>()(this, file);
    }

    FileOutputStream::~FileOutputStream() {
        Link::Func<void, 0x02320c44, FileOutputStream*>()(this);
    }

    void FileOutputStream::write(char c) {
        Link::Func<void, 0x02320CC0, FileOutputStream*, char>()(this, c);
    }
    
    void FileOutputStream::write(const ArrayWithLength<uint8_t>& arr) {
        Link::Func<void, 0x02320d04, FileOutputStream*, const ArrayWithLength<uint8_t>&>()(this, arr);
    }

    void FileOutputStream::close() {
        Link::Func<void, 0x02320d8c, FileOutputStream*>()(this);
    }
}