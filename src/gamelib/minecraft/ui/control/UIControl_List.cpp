#include "UIControl_List.h"

#include <Link/Link.h>

namespace mc {
    void UIControl_List::init(int param_1) {
        Link::Func<void, 0x02E5606C, UIControl_List*, int>()(this, param_1);
    }

    void UIControl_List::SetItemLabel(uint32_t id, UIString* str, bool param_3) {
        Link::Func<void, 0x02E7AA08, UIControl_List*, uint32_t, UIString*, bool>()(this, id, str, param_3);
    }
}