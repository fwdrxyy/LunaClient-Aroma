#pragma once

#include <utils/Types.h>

#include "../client/resource/vector.h"

namespace mc {
    class CompoundTag;
    class Tag;

    CompoundTag *Str_to_NBT(const char *nbtStr);
    CompoundTag *Arr_to_NBT(mstd::vector<uint8_t> *nbtArr);
    void ParseNBTData(uint8_t *&tag, mstd::vector<CompoundTag *> *parents);

    mstd::vector<uint8_t> *NBT_to_Arr(CompoundTag *tag, const wchar_t *tagName = L"tag");
    void StoreNBTData(Tag *tag, const wchar_t *tagName, mstd::vector<uint8_t> *result);

    mstd::vector<char> *NBT_to_TEXT(CompoundTag *tag, const wchar_t *tagName);
    void StoreNBTData(Tag *tag, const wchar_t *tagName, mstd::vector<char> *result, int &tabCount);
} // namespace mc