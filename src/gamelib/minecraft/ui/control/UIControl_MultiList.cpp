#include "UIControl_MultiList.h"

#include <Link/Link.h>

namespace mc {
    UIControl_MultiList::UIControl_MultiList() {
        Link::Func<void, 0x02E67BD4, UIControl_MultiList*>()(this);
    }

    UIControl_MultiList::UIControl_MultiList(UIControl_MultiList* _this) {
        Link::Func<void, 0x02E67BD4, UIControl_MultiList*>()(_this);
    }

    void UIControl_MultiList::setupControl(UIScene* scene, fuiRenderNode* fuiNode, mstd::wstring* str) {
        Link::Func<void, 0x02E8E86C, UIControl_MultiList*, UIScene*, fuiRenderNode*, mstd::wstring*>()(this, scene, fuiNode, str);
    }

    void UIControl_MultiList::setupControl(UIScene* scene, uint32_t fuiNode, mstd::wstring* str) {
        Link::Func<void, 0x02E8E86C, UIControl_MultiList*, UIScene*, uint32_t, mstd::wstring*>()(this, scene, fuiNode, str);
    }

    void UIControl_MultiList::AddNewCheckbox(const mstd::wstring& str, uint32_t id, bool enabled) {
        Link::Func<void, 0x02E67CA8, UIControl_MultiList*, const mstd::wstring&, uint32_t, bool>()(this, str, id, enabled);
    }

    void UIControl_MultiList::AddNewButton(const mstd::wstring& str, uint32_t id, bool enabled) {
        Link::Func<void, 0x02E345EC, UIControl_MultiList*, const mstd::wstring&, uint32_t, bool>()(this, str, id, enabled);
    }

    void UIControl_MultiList::AddNewLabel(const mstd::wstring& str, uint32_t id) {
        Link::Func<void, 0x02E67C40, UIControl_MultiList*, const mstd::wstring&, uint32_t>()(this, str, id);
    }

    void UIControl_MultiList::AddNewSlider(const mstd::wstring& str, bool enabled, uint32_t id, uint32_t idx, uint32_t min, uint32_t max) {
        Link::Func<void, 0x02E6CF88, UIControl_MultiList*, const mstd::wstring&, uint32_t, uint32_t, uint32_t, uint32_t, bool, uint32_t, uint32_t>()(this, str, id, min, max, idx, enabled, max, min);
    }
}