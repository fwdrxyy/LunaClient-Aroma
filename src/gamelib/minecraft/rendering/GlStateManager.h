#pragma once

#include <utils/Types.h>

#define MC_GL_ZERO                0
#define MC_GL_ONE                 1
#define MC_GL_SRC_ALPHA           4
#define MC_GL_ONE_MINUS_SRC_ALPHA 5

#define MC_GL_TRIANGLES           0
#define MC_GL_TRIANGLE_FAN        1
#define MC_GL_QUADS               2
#define MC_GL_QUADS_STRIP         3
#define MC_GL_LINES               4
#define MC_GL_LINES_STRIP         5

#define MC_GL_MODELVIEW           0
#define MC_GL_PROJECTION          1
#define MC_GL_TEXTURE             2

namespace mc {
    class GlStateManager {
    public:
        static void disableDepthTest();
        static void lineWidth(float size);
        static void enableDepthTest();
        static void pushMatrix();
        static void scalef(float x, float y, float z);
        static void translatef(float x, float y, float z);
        static void rotatef(float x, float y, float z, float w);
        static void popMatrix();
        static void disableTexture();
        static int genTexture();
        static void enableTexture();
        static void depthMask(bool arg1);
        static void ortho(double arg1, double arg2, double arg3, double arg4, double arg5, double arg6);
        static void matrixMode(uint32_t arg1);
        static void loadIdentity();
        static void disableCull();
        static void enableCull();
        static void clear(int i);
        static void enableBlend();
        static void disableBlend();
        static void blendFunc(uint32_t arg1, uint32_t arg2);
        static void disableLighting();
        static void enableLighting();
        static void color4f(double r, double g, double b, double a);
        static void disableFog();
    };
} // namespace mc