#include "Vec3.h"

#include <Link/Link.h>

#include "CMath.h"

#include "../block/BlockPos.h"

namespace mc {
    Vec3::Vec3(double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    Vec3::Vec3(float yaw, float pitch) {
        x = mc_abs(mc_sin(mc_degToRad(pitch - 90.0f))) * mc_sin(mc_degToRad(yaw - 180.0f));
        y = mc_sin(mc_degToRad(pitch - 180.0f));
        z = mc_abs(mc_sin(mc_degToRad(pitch - 90.0f))) * mc_cos(mc_degToRad(yaw));
    }

    Vec3::Vec3(double all) {
        x = all;
        y = all;
        z = all;
    }

    Vec3::Vec3(const BlockPos &pos) {
        x = Link::toFloat(pos.x);
        y = Link::toFloat(pos.y);
        z = Link::toFloat(pos.z);
    }

    double Vec3::distance(const Vec3 &other) const { return (*this - other).lengthSqrt(); }

    double Vec3::length() const { return x * x + y * y + z * z; }

    double Vec3::lengthSqrt() const { return mc_sqrt(length()); }

    Vec3 Vec3::normalize() const { return *this / lengthSqrt(); }

    double Vec3::operator[](int i) const { return ((double *) this)[i]; }

    Vec3 Vec3::operator+(const Vec3 &other) const { return Vec3(x + other.x, y + other.y, z + other.z); }

    Vec3 Vec3::operator+(double amt) const { return Vec3(x + amt, y + amt, z + amt); }

    Vec3 Vec3::operator-(const Vec3 &other) const { return Vec3(x - other.x, y - other.y, z - other.z); }

    Vec3 Vec3::operator-(double amt) const { return Vec3(x - amt, y - amt, z - amt); }

    Vec3 Vec3::operator*(const Vec3 &other) const { return Vec3(x * other.x, y * other.y, z * other.z); }

    Vec3 Vec3::operator*(double amt) const { return Vec3(x * amt, y * amt, z * amt); }

    Vec3 Vec3::operator/(const Vec3 &other) const { return Vec3(x / other.x, y / other.y, z / other.z); }

    Vec3 Vec3::operator/(double amt) const { return Vec3(x / amt, y / amt, z / amt); }

    Vec3 Vec3::operator=(const Vec3 &other) {
        x = other.x;
        y = other.y;
        z = other.z;

        return *this;
    }

    Vec3 Vec3::operator*=(double amt) {
        x *= amt;
        y *= amt;
        z *= amt;

        return *this;
    }

    Vec3 Vec3::operator/=(double amt) {
        x /= amt;
        y /= amt;
        z /= amt;

        return *this;
    }

    bool Vec3::operator==(const Vec3 &other) const {
        bool b_x = x == other.x;
        bool b_y = y == other.y;
        bool b_z = z == other.z;

        return b_x && b_y && b_z;
    }

    bool Vec3::operator!=(const Vec3 &other) const {
        bool b_x = x != other.x;
        bool b_y = y != other.y;
        bool b_z = z != other.z;

        return b_x && b_y && b_z;
    }
} // namespace mc