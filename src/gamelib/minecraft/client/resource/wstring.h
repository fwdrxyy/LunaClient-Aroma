#pragma once

#include <utils/Types.h>

namespace mstd {
    class wstring {
    public:
        wstring(const wchar_t *str);
        wstring() = default;

        const wchar_t *c_str() const;
        wchar_t *data();
        const wstring &assign(const wchar_t *_str, int _length);

        wstring toLowerCase() const;

        bool operator==(const wchar_t *other) const;
        bool operator!=(const wchar_t *other) const;
        wchar_t operator[](int index) const;

        uint32_t field_0x0; // 0x00
        wchar_t str[8];     // 0x04
        wchar_t *pointer;   // 0x14
        uint32_t length;    // 0x18
        uint32_t capacity;  // 0x1C
    };
} // namespace mstd