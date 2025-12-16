#include "GlStateManager.h"

#include <Link/Link.h>

namespace mc {
    void GlStateManager::disableDepthTest() { Link::Func<void, 0x030E9B9C>()(); }

    void GlStateManager::lineWidth(float size) { Link::Func<void, 0x030e9bfc, float>()(size); }

    void GlStateManager::enableDepthTest() { Link::Func<void, 0x030E9BB8>()(); }

    void GlStateManager::pushMatrix() { Link::Func<void, 0x030E4B3C>()(); }

    void GlStateManager::scalef(float x, float y, float z) { Link::Func<void, 0x030E4B6C, float, float, float>()(x, y, z); }

    void GlStateManager::translatef(float x, float y, float z) { Link::Func<void, 0x30E4B54, float, float, float>()(x, y, z); }

    void GlStateManager::rotatef(float x, float y, float z, float w) { Link::Func<void, 0x030E4B84, float, float, float, float>()(x, y, z, w); }

    void GlStateManager::popMatrix() { Link::Func<void, 0x030E4BD8>()(); }

    void GlStateManager::disableTexture() { Link::Func<void, 0x030E6268>()(); }

    int GlStateManager::genTexture() { return Link::Func<int, 0x03124ef8>()(); }

    void GlStateManager::enableTexture() { Link::Func<void, 0x030E6294>()(); }

    void GlStateManager::depthMask(bool arg1) { Link::Func<void, 0x030E52FC, bool>()(arg1); }

    void GlStateManager::ortho(double arg1, double arg2, double arg3, double arg4, double arg5, double arg6) {
        Link::Func<void, 0x3110D4C, double, double, double, double, double, double>()(arg1, arg2, arg3, arg4, arg5, arg6);
    }

    void GlStateManager::matrixMode(uint32_t arg1) { Link::Func<void, 0x3103064, uint32_t>()(arg1); }

    void GlStateManager::loadIdentity() { Link::Func<void, 0x03103080>()(); }

    void GlStateManager::disableCull() { Link::Func<void, 0x030F974C>()(); }

    void GlStateManager::enableCull() { Link::Func<void, 0x030f9768>()(); }

    void GlStateManager::clear(int i) { Link::Func<void, 0x031078C8, int>()(i); }

    void GlStateManager::enableBlend() { Link::Func<void, 0x30E5284>()(); }

    void GlStateManager::disableBlend() { Link::Func<void, 0x030E5328>()(); }

    void GlStateManager::blendFunc(uint32_t arg1, uint32_t arg2) { Link::Func<void, 0x30E52A0, uint32_t, uint32_t>()(arg1, arg2); }

    void GlStateManager::disableLighting() { Link::Func<void, 0x030E4B24>()(); }

    void GlStateManager::enableLighting() { Link::Func<void, 0x030E4C04>()(); }

    void GlStateManager::color4f(double r, double g, double b, double a) { Link::Func<void, 0x30E4BA8, double, double, double, double>()(r, g, b, a); }

    void GlStateManager::disableFog() { Link::Func<void, 0x03108C44>()(); }
} // namespace mc