#pragma once

#include <utils/Types.h>

namespace mc {
    enum eResizeMode { NEAREST_NEIGHBOR };

    static const int sFormat = 4;

    uint8_t *stbi_load_from_memory(const uint8_t *imgData, uint32_t imgSize, int *width, int *height, int *channels, int format = sFormat);
    void stbi_image_free(uint8_t *data);

    uint8_t *crop(uint8_t *imgData, int &width, int &height);
    uint8_t *crop(uint8_t *imgData, int width, int height, int newWidth, int newHeight, int offsetX, int offsetY);
    uint8_t *resize(uint8_t *imgData, int &width, int &height, int newWidth, int newHeight, eResizeMode resizeMode = NEAREST_NEIGHBOR);
    uint8_t *resize(uint8_t *imgData, int &width, int &height, int newLength, bool heightBased, mc::eResizeMode resizeMode = NEAREST_NEIGHBOR);
} // namespace mc