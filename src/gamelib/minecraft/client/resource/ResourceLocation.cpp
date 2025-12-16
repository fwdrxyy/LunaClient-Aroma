#include "ResourceLocation.h"

#include <Link/Link.h>

namespace mc {
    ResourceLocation::ResourceLocation(const mstd::wstring& str1, const mstd::wstring& str2) {
        Link::Func<void, 0x03250d30, ResourceLocation*, const mstd::wstring&, const mstd::wstring&>()(this, str1, str2);
    }
}