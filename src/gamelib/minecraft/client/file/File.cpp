#include "File.h"

#include <Link/Link.h>

namespace mc {
    File::File(const mstd::wstring& path) {
        Link::Func<void, 0x023237c0, File*, const mstd::wstring&>()(this, path);
    }

    File::~File() {
        Link::Func<void, 0x0323ed84, File*>()(this);
    }

    bool File::exists() {
        return Link::Func<bool, 0x023209b8, File*>()(this);
    }
    
    bool File::isDirectory() {
        return Link::Func<bool, 0x02320a4c, File*>()(this);
    }

    void File::_delete() {
        Link::Func<void, 0x023238e4, File*>()(this);
    }

    void File::getPath(const mstd::wstring& str) {
        Link::Func<void, 0x0232042C, File*, const mstd::wstring&>()(this, str);
    }

    mstd::vector<File*>& File::getFiles() {
        return Link::Func<mstd::vector<File*>&, 0x02324220, File*>()(this); 
    }

    void File::getName(const mstd::wstring& name) {
        Link::Func<void, 0x02324904, File*, const mstd::wstring&>()(this, name);
    }
}