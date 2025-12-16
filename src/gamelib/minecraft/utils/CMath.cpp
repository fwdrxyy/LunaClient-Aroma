#include "CMath.h"

#include <Link/Link.h>

#include <minecraft/world/Level.h>

float64_t mc_sin(float64_t x) { return Link::Func<float64_t, 0x03832468, float64_t>()(x); }

float32_t mc_sinf(float32_t x) { return Link::Func<float32_t, 0x03833f6c, float32_t>()(x); }

float64_t mc_cos(float64_t x) { return Link::Func<float64_t, 0x0383300c, float64_t>()(x); }

float32_t mc_cosf(float32_t x) { return Link::Func<float32_t, 0x03834758, float32_t>()(x); }

float64_t mc_tan(float64_t x) { return Link::Func<float64_t, 0x03832234, float64_t>()(x); }

float32_t mc_tanf(float32_t x) { return Link::Func<float32_t, 0x03833d98, float32_t>()(x); }

float64_t mc_pow(float64_t x, float64_t y) { return Link::Func<float64_t, 0x038324a8, float64_t, float64_t>()(x, y); }

float32_t mc_powf(float32_t x, float32_t y) { return Link::Func<float32_t, 0x038340d4, float32_t, float32_t>()(x, y); }

float64_t mc_sqrt(float64_t x) { return Link::Func<float64_t, 0x038323cc, float64_t>()(x); }

float32_t mc_sqrtf(float32_t x) { return Link::Func<float32_t, 0x03833ee0, float32_t>()(x); }

float32_t mc_degToRad(float32_t deg) { return (deg * M_PI / 180.0f); }

float32_t mc_radToDeg(float32_t rad) { return (rad * 180.0f / M_PI); }

float64_t mc_abs(float64_t x) { return 0.0 > x ? -x : x; }

float32_t mc_fabs(float32_t x) { return 0.0f > x ? -x : x; }

float32_t mc_ceilf(float32_t x) { return Link::Func<float32_t, 0x03833D0C, float32_t>()(x); }

float32_t mc_floorf(float32_t x) { return Link::Func<float32_t, 0x03833C70, float32_t>()(x); }

float32_t mc_acosf(float32_t x) { return Link::Func<float32_t, 0x03834A98, float32_t>()(x); }

namespace mc {
    Vec3 getLookAt(float32_t pitch, float32_t yaw) {
        Vec3 lookAt = {
                mc_fabs(mc_sinf(mc_degToRad(pitch - 90.0f))) * mc_sinf(mc_degToRad(yaw - 180.0f)),
                mc_sinf(mc_degToRad(pitch - 180.0f)),
                mc_fabs(mc_sinf(mc_degToRad(pitch - 90.0f))) * mc_cosf(mc_degToRad(yaw)),
        };

        return lookAt;
    }

    HitResult *getLookAtRay(Player *player, bool ignoreBlockWithoutBoundingBox, float64_t reach) {
        Vec3 start = player->position;
        start.y += player->getEyeHeight();

        Vec3 lookAt = getLookAt(player->pitch, player->yaw);
        lookAt      = lookAt.normalize();

        return player->lvl->clip(start, start + lookAt * reach, false, ignoreBlockWithoutBoundingBox, false, false, nullptr, false);
    }
} // namespace mc
