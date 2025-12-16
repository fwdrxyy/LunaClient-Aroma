#include "CMinecraftApp.h"

#include <Link/Link.h>

namespace mc {
    void CMinecraftApp::AddMemoryTextureFile(const mstd::wstring& name, uint8_t* data, uint32_t size) {
        Link::Func<void, 0x02F5DF50, CMinecraftApp*, const mstd::wstring&, uint8_t*, uint32_t>()(this, name, data, size);
    }

    const mstd::wstring& CMinecraftApp::getSkinPathFromId(void* ptr, uint32_t id) {
        return Link::Func<const mstd::wstring&, 0x02f6d438, void*, uint32_t>()(ptr, id);
    }

    void CMinecraftApp::SetAppPaused(bool b) {
        Link::Func<void, 0x02f2bf6c, CMinecraftApp*, bool>()(this, b);
    }

    bool CMinecraftApp::isAppPaused()  {
        return Link::Func<bool, 0x02f36eec, CMinecraftApp*>()(this);
    }

    CMinecraftApp* CMinecraftApp::getInstance() {    
        return Link::Mem(0x10528DC0).as<CMinecraftApp*>();
    }
}