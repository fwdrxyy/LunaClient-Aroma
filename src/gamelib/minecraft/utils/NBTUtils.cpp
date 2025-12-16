#include "NBTUtils.h"

#include "../nbt/ByteArrayTag.h"
#include "../nbt/ByteTag.h"
#include "../nbt/CompoundTag.h"
#include "../nbt/DoubleTag.h"
#include "../nbt/FloatTag.h"
#include "../nbt/IntTag.h"
#include "../nbt/ListTag.h"
#include "../nbt/LongTag.h"
#include "../nbt/ShortTag.h"
#include "../nbt/StringTag.h"
#include "../nbt/Tag.h"
#include <utils/Logger.h>

#include "Common.h"
#include "VTable_Tag.h"

uint8_t hexStrToUint8(const char *hex) {
    uint8_t result = 0;

    // Convert first character
    if (hex[0] >= '0' && hex[0] <= '9') {
        result = (hex[0] - '0') << 4;
    } else if (hex[0] >= 'a' && hex[0] <= 'f') {
        result = (hex[0] - 'a' + 10) << 4;
    } else if (hex[0] >= 'A' && hex[0] <= 'F') {
        result = (hex[0] - 'A' + 10) << 4;
    }

    // Convert second character
    if (hex[1] >= '0' && hex[1] <= '9') {
        result |= (hex[1] - '0');
    } else if (hex[1] >= 'a' && hex[1] <= 'f') {
        result |= (hex[1] - 'a' + 10);
    } else if (hex[1] >= 'A' && hex[1] <= 'F') {
        result |= (hex[1] - 'A' + 10);
    }

    return result;
}

uint8_t *strToByteArray(const char *str) {
    int size        = mc::mc_strlen(str) / 2;
    uint8_t *result = new uint8_t[size];
    for (int i = 0; i < size; i++) {
        char temp[2];
        temp[0] = str[(i * 2) + 0];
        temp[1] = str[(i * 2) + 1];

        result[i] = hexStrToUint8(temp);
    }

    return result;
}

uint16_t uint8ArrTo16(uint8_t *arr, int s_index) { return (arr[s_index] << 8) | arr[s_index + 1]; }

uint32_t uint8ArrTo32(uint8_t *arr, int s_index) { return (arr[s_index] << 24) | (arr[s_index + 1] << 16) | (arr[s_index + 2] << 8) | arr[s_index + 3]; }

char *uint8ArrToCStr(uint8_t *arr, int s_index, uint16_t length) {
    char *result   = new char[length + 1];
    result[length] = '\0';
    for (int i = 0; i < length; i++) result[i] = arr[s_index + i];

    return result;
}

void removeWaste(uint8_t *&tag) {
    const uint8_t removeArray[4]{0x0A, 0x00, 0x01, 0x0A};

    bool startsWith = true;
    for (int i = 0; i < 4; i++)
        if (tag[i] != removeArray[i]) startsWith = false;

    if (startsWith) tag += 4;
}

namespace mc {
    CompoundTag *Str_to_NBT(const char *nbtStr) {
        uint8_t *tag = strToByteArray(nbtStr);
        removeWaste(tag);

        mstd::vector<CompoundTag *> *tags = new mstd::vector<CompoundTag *>(200);
        ParseNBTData(tag, tags);

        delete tag;
        return tags->size() == 0 ? nullptr : tags->operator[](0);
    }

    CompoundTag *Arr_to_NBT(mstd::vector<uint8_t> *nbtArr) {
        uint8_t *tag                      = nbtArr->data();
        uint8_t *ptrCopy                  = tag;
        mstd::vector<CompoundTag *> *tags = new mstd::vector<CompoundTag *>(200);
        ParseNBTData(tag, tags);

        DEBUG_FUNCTION_LINE_VERBOSE("Loaded %d/%d Bytes", (int) tag - (int) ptrCopy, nbtArr->size());
        return tags->size() == 0 ? nullptr : tags->operator[](0);
    }

    void ParseNBTData(uint8_t *&tag, mstd::vector<CompoundTag *> *parents) {
        uint8_t tagId = tag[0];
        tag++;

        if (tagId == 0x00) {
            if (parents->size() > 1) parents->pop_back();

            return ParseNBTData(tag, parents);
        } else if (tagId == 0xFF)
            return;

        uint16_t nameLen  = uint8ArrTo16(tag, 0);
        char *tagName     = uint8ArrToCStr(tag, 2, nameLen);
        wchar_t *tagNameW = new wchar_t[nameLen + 1];
        mc_swprintf(tagNameW, nameLen + 1, L"%s", tagName);
        tag += 2 + nameLen;

        switch (tagId) {
            case CompoundTag::getId(): {
                CompoundTag *newTag = new CompoundTag();
                if (parents->size() > 0) parents->back()->put(tagNameW, newTag);
                parents->push_back(newTag);
                break;
            }
            case IntTag::getId(): {
                int intTag = uint8ArrTo32(tag, 0);
                parents->back()->putInt(tagNameW, intTag);
                tag += 4;
                break;
            }
            case ShortTag::getId(): {
                short shortTag = uint8ArrTo16(tag, 0);
                parents->back()->putShort(tagNameW, shortTag);
                tag += 2;
                break;
            }
            case ByteTag::getId(): {
                uint8_t byteTag = tag[0];
                parents->back()->putByte(tagNameW, byteTag);
                tag++;
                break;
            }
            case StringTag::getId(): {
                uint16_t strLen = uint8ArrTo16(tag, 1);
                char *str       = uint8ArrToCStr(tag, 3, strLen);

                wchar_t *temp = new wchar_t[strLen + 1];
                for (int i = 0; i <= strLen; i++) temp[i] = str[i];

                parents->back()->putString(tagNameW, temp);
                delete[] temp;

                tag += 2 + nameLen;
                break;
            }
            case FloatTag::getId(): {
                float floatTag;
                for (int i = 0; i < (int) sizeof(float); i++) ((uint8_t *) &floatTag)[i] = tag[i];
                parents->back()->putFloat(tagNameW, floatTag);
                tag += sizeof(float);
                break;
            }
            case DoubleTag::getId(): {
                double doubleTag;
                for (int i = 0; i < (int) sizeof(double); i++) ((uint8_t *) &doubleTag)[i] = tag[i];
                parents->back()->putDouble(tagNameW, doubleTag);
                tag += sizeof(double);
                break;
            }
            case LongTag::getId(): {
                long long longTag;
                for (int i = 0; i < (int) sizeof(long long); i++) ((uint8_t *) &longTag)[i] = tag[i];
                parents->back()->putLong(tagNameW, longTag);
                tag += sizeof(long long);
                break;
            }
            default:
                DEBUG_FUNCTION_LINE_VERBOSE("- Unknown Tag ID: %d 0x%02X, returning...", tagId, tagId);
                return;
        }

        ParseNBTData(tag, parents);
    }

    mstd::vector<uint8_t> *NBT_to_Arr(CompoundTag *tag, const wchar_t *tagName) {
        // 20kb
        mstd::vector<uint8_t> *result = new mstd::vector<uint8_t>(20 * 1000);
        StoreNBTData(tag, tagName, result);
        // Custom End for the NBT Parser (Could be fixed by giving size and checking but.... i am lazy :P)
        result->push_back(0xFF);
        return result;
    }

    void StoreNBTData(Tag *tag, const wchar_t *tagName, mstd::vector<uint8_t> *result) {
        int tagId = tag->vtable->getId(tag);

        uint16_t nameLength = mc_strlen(tagName);
        result->push_back(tagId);
        result->push_back(((uint8_t *) &nameLength)[0]);
        result->push_back(((uint8_t *) &nameLength)[1]);
        for (uint16_t i = 0; i < nameLength; i++) result->push_back((uint8_t) tagName[i]);

        switch (tagId) {
            case CompoundTag::getId(): {
                CompoundTag *compound = (CompoundTag *) tag;
                for (mstd::wstring tagNames : *compound->getAllKeys()) {
                    Tag *insertTag = compound->get(tagNames.c_str());
                    StoreNBTData(insertTag, tagNames.c_str(), result);
                }

                result->push_back(0x00);
                break;
            }
            case IntTag::getId(): {
                int data = ((IntTag *) tag)->data;
                for (int i = 0; i < (int) sizeof(int); i++) result->push_back(((uint8_t *) &data)[i]);
                break;
            }
            case ShortTag::getId(): {
                short data = ((ShortTag *) tag)->data;
                for (short i = 0; i < (int) sizeof(short); i++) result->push_back(((uint8_t *) &data)[i]);
                break;
            }
            case ByteTag::getId(): {
                uint8_t data = ((ByteTag *) tag)->data;
                result->push_back(data);
                break;
            }
            case StringTag::getId(): {
                mstd::wstring &data = ((StringTag *) tag)->data;
                uint16_t nameLength = data.length;
                result->push_back(((uint8_t *) &nameLength)[0]);
                result->push_back(((uint8_t *) &nameLength)[1]);
                for (uint16_t i = 0; i < data.length; i++) result->push_back((uint8_t) data[i]);
                break;
            }
            case FloatTag::getId(): {
                float data = ((FloatTag *) tag)->data;
                for (int i = 0; i < (int) sizeof(float); i++) result->push_back(((uint8_t *) &data)[i]);
                break;
            }
            case DoubleTag::getId(): {
                double data = ((DoubleTag *) tag)->data;
                for (int i = 0; i < (int) sizeof(double); i++) result->push_back(((uint8_t *) &data)[i]);
                break;
            }
            case LongTag::getId(): {
                long long data = ((LongTag *) tag)->data;
                for (int i = 0; i < (int) sizeof(long long); i++) result->push_back(((uint8_t *) &data)[i]);
                break;
            }
            default:
                DEBUG_FUNCTION_LINE_VERBOSE("- Unknown Tag ID: %d 0x%02X", tagId, tagId);
                break;
        }
    }

    mstd::vector<char> *NBT_to_TEXT(CompoundTag *tag, const wchar_t *tagName) {
        // 20kb
        mstd::vector<char> *result = new mstd::vector<char>(20 * 1000);
        const char *disclaimerText = "DISCLAIMER!\nEditing this File does not Change anything, this "
                                     "is just a Readable Visualization of the Original .nbt "
                                     "file\n";
        for (size_t i = 0; i < strlen(disclaimerText); i++) result->push_back(disclaimerText[i]);

        int tabCount = 0;
        StoreNBTData(tag, tagName, result, tabCount);
        return result;
    }

    void StoreNBTData(Tag *tag, const wchar_t *tagName, mstd::vector<char> *result, int &tabCount) {
        int tagId = tag->vtable->getId(tag);

        if (tabCount > 0) result->push_back('\n');

        for (int i = 0; i < tabCount; i++) result->push_back('\t');

        uint16_t nameLength = mc_strlen(tagName);
        for (uint16_t i = 0; i < nameLength; i++) result->push_back((char) tagName[i]);

        result->push_back(':');
        result->push_back(' ');

        char formatHelper[0x50];
        switch (tagId) {
            case CompoundTag::getId(): {
                tabCount++;
                CompoundTag *compound                       = (CompoundTag *) tag;
                mstd::vector<mstd::wstring> *tagNamesVector = compound->getAllKeys();
                for (mstd::wstring tagNames : *tagNamesVector) {
                    Tag *insertTag = compound->get(tagNames.c_str());
                    StoreNBTData(insertTag, tagNames.c_str(), result, tabCount);
                }

                tabCount--;
                break;
            }
            case IntTag::getId(): {
                int data = ((IntTag *) tag)->data;
                mc_snprintf(formatHelper, 0x50, "%d", data);
                for (size_t i = 0; i < strlen(formatHelper); i++) result->push_back(formatHelper[i]);
                break;
            }
            case ShortTag::getId(): {
                short data = ((ShortTag *) tag)->data;
                mc_snprintf(formatHelper, 0x50, "%d", data);
                for (size_t i = 0; i < strlen(formatHelper); i++) result->push_back(formatHelper[i]);
                break;
            }
            case ByteTag::getId(): {
                uint8_t data = ((ByteTag *) tag)->data;
                mc_snprintf(formatHelper, 0x50, "%d", data);
                for (size_t i = 0; i < strlen(formatHelper); i++) result->push_back(formatHelper[i]);
                break;
            }
            case StringTag::getId(): {
                mstd::wstring &data = ((StringTag *) tag)->data;
                for (uint16_t i = 0; i < data.length; i++) result->push_back((char) data[i]);
                break;
            }
            case FloatTag::getId(): {
                float data = ((FloatTag *) tag)->data;
                toCStr(data, formatHelper, 5);
                for (size_t i = 0; i < strlen(formatHelper); i++) result->push_back(formatHelper[i]);
                break;
            }
            case DoubleTag::getId(): {
                double data = ((DoubleTag *) tag)->data;
                toCStr(data, formatHelper, 5);
                for (size_t i = 0; i < strlen(formatHelper); i++) result->push_back(formatHelper[i]);
                break;
            }
            case LongTag::getId(): {
                long long data = ((LongTag *) tag)->data;
                mc_snprintf(formatHelper, 0x50, "%lld", data);
                for (size_t i = 0; i < strlen(formatHelper); i++) result->push_back(formatHelper[i]);
                break;
            }
            default:
                DEBUG_FUNCTION_LINE_VERBOSE("- Unknown Tag ID: %d 0x%02X", tagId, tagId);
                break;
        }
    }
} // namespace mc