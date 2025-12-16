#pragma once

#include <utils/Types.h>

#include <minecraft/entity/player/Player.h>
#include <minecraft/utils/HitResult.h>

#define M_PI   3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.78539816339744830962
#define M_1_PI 0.31830988618379067154
#define M_2_PI 0.63661977236758134308

float64_t mc_sin(float64_t x);
float32_t mc_sinf(float32_t x);

float64_t mc_cos(float64_t x);
float32_t mc_cosf(float32_t x);

float64_t mc_tan(float64_t x);
float32_t mc_tanf(float32_t x);

float64_t mc_pow(float64_t x, float64_t y);
float32_t mc_powf(float32_t x, float32_t y);

float64_t mc_sqrt(float64_t x);
float32_t mc_sqrtf(float32_t x);

float32_t mc_degToRad(float32_t deg);
float32_t mc_radToDeg(float32_t rad);

float64_t mc_abs(float64_t x);
float32_t mc_fabs(float32_t x);

float32_t mc_ceilf(float32_t x);

float32_t mc_floorf(float32_t x);

float32_t mc_acosf(float32_t x);

namespace mc {
    Vec3 getLookAt(float32_t pitch, float32_t yaw);
    HitResult *getLookAtRay(Player *player, bool ignoreBlockWithoutBoundingBox, float64_t reach);
} // namespace mc
