#include "Font.h"

#include <Link/Link.h>

namespace mc {
    int Font::width(const mstd::wstring& wstr) {
		return Link::Func<uint32_t, 0x30E919C, Font*, const mstd::wstring&>()(this, wstr);
	}

	void Font::drawShadow(const mstd::wstring& wstr, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
		Link::Func<void, 0x3126B88, Font*, const mstd::wstring&, uint32_t, uint32_t, uint32_t>()(this, wstr, arg1, arg2, arg3);
	}

	void Font::draw(const mstd::wstring& wstr, uint32_t arg1, uint32_t arg2, uint32_t arg3) {
		Link::Func<void, 0x030E9A10, Font*, const mstd::wstring&, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>()(this, wstr, arg1, arg2, arg3, 0, 1);
	}
}