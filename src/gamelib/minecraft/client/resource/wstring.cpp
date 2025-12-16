#include "wstring.h"

#include <Link/Link.h>

#include "../../utils/Common.h"

namespace mstd {
    wstring::wstring(const wchar_t *str) { Link::Func<void, 0x020B08D4, wstring *, const wchar_t *>()(this, str); }

    const wchar_t *wstring::c_str() const { return (length > 7) ? pointer : str; }

    wchar_t *wstring::data() { return (length > 7) ? pointer : str; }

    const wstring &wstring::assign(const wchar_t *_str, int32_t _length) {
        return Link::Func<const wstring &, 0x030E8BC4, wstring *, const wchar_t *, int32_t>()(this, _str, _length);
    }

    wstring wstring::toLowerCase() const {
        wstring result = c_str();
        wchar_t *r     = result.data();
        for (int32_t i = 0; i < (int32_t) length; i++) {
            wchar_t &c = r[i];
            if (c <= L'Z' && c >= L'A') c = c - L'A' + L'a';
        }

        return result;
    }

    bool wstring::operator==(const wchar_t *other) const { return mc::mc_strcmp(c_str(), other) == 0; }

    bool wstring::operator!=(const wchar_t *other) const { return mc::mc_strcmp(c_str(), other) != 0; }

    wchar_t wstring::operator[](int32_t index) const { return c_str()[index]; }
} // namespace mstd