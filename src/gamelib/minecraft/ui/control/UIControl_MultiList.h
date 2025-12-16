#pragma once

#include <utils/Types.h>

#include "UIControl_List.h"

namespace mstd {
    class wstring;
}

namespace mc {
    class UIScene;
    class fuiRenderNode;

    class UIControl_MultiList : public UIControl_List {
    public:
        UIControl_MultiList();
        UIControl_MultiList(UIControl_MultiList *_this);

        void setupControl(UIScene *scene, fuiRenderNode *fuiNode, mstd::wstring *str);
        void setupControl(UIScene *scene, uint32_t fuiNode, mstd::wstring *str);
        void AddNewCheckbox(const mstd::wstring &str, uint32_t id, bool enabled);
        void AddNewButton(const mstd::wstring &str, uint32_t id, bool enabled);
        void AddNewLabel(const mstd::wstring &str, uint32_t id);
        void AddNewSlider(const mstd::wstring &str, bool enabled, uint32_t id, uint32_t idx, uint32_t min, uint32_t max);

        uint32_t field_0x60;
        uint32_t field_0x64;
        uint32_t field_0x68;
        uint32_t field_0x6C;
        uint32_t field_0x70;
        uint32_t field_0x74;
        uint32_t field_0x78;
        uint32_t field_0x7C;
        uint32_t field_0x80;
        uint32_t field_0x84;
        uint32_t field_0x88;
        uint32_t field_0x8C;
        uint32_t field_0x90;
        uint32_t field_0x94;
        uint32_t field_0x98;
        uint32_t field_0x9C;
        uint32_t field_0xA0;
        uint32_t field_0xA4;
        uint32_t field_0xA8;
        uint32_t field_0xAC;
        uint32_t field_0xB0;
        uint32_t field_0xB4;
        uint32_t field_0xB8;
        uint32_t field_0xBC;
    };
} // namespace mc