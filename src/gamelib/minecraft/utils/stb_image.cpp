#include "stb_image.h"

#include <Link/Link.h>

#include "Common.h"

namespace mc {
    uint8_t* stbi_load_from_memory(const uint8_t* imgData, uint32_t imgSize, int* width, int* height, int* channels, int format) {
        return Link::Func<uint8_t*, 0x03400158, const uint8_t*, uint32_t, int*, int*, int*, int>()(imgData, imgSize, width, height, channels, format);
    }

    void stbi_image_free(uint8_t* data) {
        Link::Func<void, 0x033e5594, uint8_t*>()(data);
    }

    uint8_t* crop(uint8_t* imgData, int& width, int& height) {
        int minAxis = min(width, height);
        int offX = (width  - minAxis) / 2;
        int offY = (height - minAxis) / 2;

        uint8_t* newImgData = crop(imgData, width, height, minAxis, minAxis, offX, offY);
        width = minAxis;
        height = minAxis;
        return newImgData;
    }

    uint8_t* crop(uint8_t* imgData, int width, int height, int newWidth, int newHeight, int offsetX, int offsetY) {
        uint8_t* newImgData = new uint8_t[newWidth * newHeight * sFormat];
        for (int x = 0; x < newWidth; x++) {
            for (int y = 0; y < newHeight; y++) {
                int oldImgIndex = ((y + offsetY) * width + (x + offsetX)) * sFormat;
                int newImgIndex = (y * newWidth + x) * sFormat;

                for (int i = 0; i < sFormat; i++)
                    newImgData[newImgIndex + i] = imgData[oldImgIndex + i];
            }
        }

        return newImgData;
    }

    uint8_t* resize(uint8_t* imgData, int& width, int& height, int newWidth, int newHeight, eResizeMode resizeMode) {
        float xRatio = Link::toFloat(width)  / Link::toFloat(newWidth);
        float yRatio = Link::toFloat(height) / Link::toFloat(newHeight);
        uint8_t* newImg = new uint8_t[newWidth * newHeight * sFormat];

        if (resizeMode == NEAREST_NEIGHBOR) {
            for (int y = 0; y < newHeight; y++) {
                for (int x = 0; x < newWidth; x++) {
                    int nearestX = Link::toInt(Link::toFloat(x) * xRatio);
                    int nearestY = Link::toInt(Link::toFloat(y) * yRatio);

                    int inIndex  = (nearestY * width + nearestX) * sFormat;
                    int outIndex = (y * newWidth + x) * sFormat;

                    for (int i = 0; i < sFormat; i++)
                        newImg[outIndex + i] = imgData[inIndex + i];
                }
            }
        }

        width = newWidth;
        height = newHeight;

        return newImg;
    }

    uint8_t* resize(uint8_t* imgData, int& width, int& height, int newLength, bool heightBased, eResizeMode resizeMode) {
        int newWidth, newHeight;
        float aspectRatio = Link::toFloat(width) / Link::toFloat(height);
        if (heightBased) {
            newHeight = newLength;
            newWidth = Link::toInt(Link::toFloat(newHeight) * aspectRatio);
        } else {
            newWidth = newLength;
            newHeight = Link::toInt(Link::toFloat(newWidth) / aspectRatio);
        }

        return resize(imgData, width, height, newWidth, newHeight, resizeMode);
    }
}