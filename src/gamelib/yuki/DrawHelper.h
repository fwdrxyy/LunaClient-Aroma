#pragma once

#include <minecraft/Minecraft.h>

using namespace mc;

#define MC_WIDTH  (640)
#define MC_HEIGHT (360)

namespace DrawHelper {
    void setup() {
        GlStateManager::matrixMode(1);
        GlStateManager::loadIdentity();
        GlStateManager::ortho(0.0, 640.0, 360.0, 0.0, 1000.0, 3000.0);
        GlStateManager::matrixMode(0);
        GlStateManager::loadIdentity();
        GlStateManager::translatef(0.0f, 0.0f, -2500.0f);
        GlStateManager::disableCull();
        GlStateManager::disableLighting();
        GlStateManager::disableDepthTest();
        GlStateManager::disableTexture();
        GlStateManager::enableBlend();
        GlStateManager::depthMask(0);
        GlStateManager::blendFunc(MC_GL_SRC_ALPHA, MC_GL_ONE_MINUS_SRC_ALPHA);
        GlStateManager::color4f(1.0, 1.0, 1.0, 1.0);
    }

    void text(const wchar_t *text, float32_t size, float32_t x, float32_t y, uint32_t argb) {
        GlStateManager::pushMatrix();
        GlStateManager::translatef(x, y, 0);
        GlStateManager::scalef(size, size, 0);

        Minecraft::getInstance()->defaultFonts->drawShadow(text, 0, 0, argb);

        GlStateManager::popMatrix();
    }

    void box(float32_t x, float32_t y, float32_t sX, float32_t sY, int32_t rgb, int32_t a) {
        GlStateManager::pushMatrix();
        GlStateManager::disableTexture();
        GlStateManager::translatef(x, y, 0.0f);
        GlStateManager::color4f(1.0, 1.0, 1.0, a);

        BufferBuilder *builder = Tesselator::getInstance()->getBuilder();
        builder->begin();
        builder->color(rgb, a);
        builder->vertexUV(0.0f, sY, -90.0f, 0.0f, 1.0f);
        builder->vertexUV(sX, sY, -90.0f, 1.0f, 1.0f);
        builder->vertexUV(sX, 0.0f, -90.0f, 1.0f, 0.0f);
        builder->vertexUV(0.0f, 0.0f, -90.0f, 0.0f, 0.0f);
        builder->end();

        GlStateManager::popMatrix();
    }
} // namespace DrawHelper