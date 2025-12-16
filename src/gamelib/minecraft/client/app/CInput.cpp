#include "CInput.h"

#include <Link/Link.h>

namespace mc {
    CInput *CInput::GetInput() { return Link::Mem(0x1058EC6C + 0x502200).as<CInput *>(); }

    void CInput::GetText(const wchar_t *buffer, int32_t length) { Link::Func<void, 0x0340A480, CInput *, const wchar_t *, uint32_t>()(this, buffer, length); }

    bool CInput::RequestKeyboard(const wchar_t *nothing, const wchar_t *default_text, uint32_t unk_Ui0, uint32_t max_size, int (*call_back)(void *, bool), void *arg1,
                                 KeyboardMode eKeyboardMode) {
        return Link::Func<bool, 0x0340A33C, CInput *, const wchar_t *, const wchar_t *, uint32_t, uint32_t, int (*)(void *, bool), void *, KeyboardMode>()(
                this, nothing, default_text, unk_Ui0, max_size, call_back, arg1, eKeyboardMode);
    }
} // namespace mc