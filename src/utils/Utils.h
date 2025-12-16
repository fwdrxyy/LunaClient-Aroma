#pragma once

#include <memory>

#define FS_SD_CARD_PATH "fs:/vol/external01/"

#define DRC_WIDTH       854
#define DRC_HEIGHT      480

std::unique_ptr<char[]> WCToUTF8(const wchar_t *wstr);