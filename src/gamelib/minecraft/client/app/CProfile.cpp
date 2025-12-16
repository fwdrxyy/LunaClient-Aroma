#include "CProfile.h"

#include <Link/Link.h>

namespace mc {
    CProfile* CProfile::GetProfile() {
        return Link::Mem(0x105CFA58).as<CProfile*>();
    }

    void CProfile::CreatePresenceString(uint32_t id, const mstd::wstring& wcstr) {
        Link::Func<void, 0x0341118C, CProfile*, uint32_t, const mstd::wstring&>()(this, id, wcstr);
    }

    void CProfile::SetPresenceString(uint32_t id) {
        Link::Func<void, 0x034114F4, CProfile*, uint32_t>()(this, id);
    }
}