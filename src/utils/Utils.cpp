#include "Utils.h"

#include <utils/Types.h>

std::unique_ptr<char[]> WCToUTF8(const wchar_t *wstr) {
    if (!wstr) return nullptr;

    size_t len         = 0;
    const wchar_t *tmp = wstr;
    while (*tmp++) len++;

    size_t maxOut = (len * 4) + 1;
    std::unique_ptr<char[]> out(new char[maxOut]);

    size_t i = 0;
    while (*wstr) {
        uint32_t wc = (uint32_t) (*wstr++);
        if (wc < 0x80) {
            out[i++] = (char) wc;
        } else if (wc < 0x800) {
            out[i++] = (char) (0xC0 | (wc >> 6));
            out[i++] = (char) (0x80 | (wc & 0x3F));
        } else if (wc < 0x10000) {
            out[i++] = (char) (0xE0 | (wc >> 12));
            out[i++] = (char) (0x80 | ((wc >> 6) & 0x3F));
            out[i++] = (char) (0x80 | (wc & 0x3F));
        } else {
            out[i++] = (char) (0xF0 | (wc >> 18));
            out[i++] = (char) (0x80 | ((wc >> 12) & 0x3F));
            out[i++] = (char) (0x80 | ((wc >> 6) & 0x3F));
            out[i++] = (char) (0x80 | (wc & 0x3F));
        }
    }

    out[i] = '\0';
    return out;
}