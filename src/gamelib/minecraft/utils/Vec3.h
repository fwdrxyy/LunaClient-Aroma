#pragma once

namespace mc {
    class BlockPos;

    class Vec3 {
    public:
        Vec3(double _x, double _y, double _z);
        Vec3(float yaw, float pitch);
        Vec3(double all);
        Vec3(const BlockPos& pos);
        Vec3() = default;

        double distance(const Vec3& other) const;
        double length() const;
        double lengthSqrt() const;
        Vec3 normalize() const;

        double operator[](int i) const;

        Vec3 operator+(const Vec3& other) const;
        Vec3 operator+(double amt) const;
        Vec3 operator-(const Vec3& other) const;
        Vec3 operator-(double amt) const;
        Vec3 operator*(const Vec3& other) const;
        Vec3 operator*(double amt) const;
        Vec3 operator/(const Vec3& other) const;
        Vec3 operator/(double amt) const;
        Vec3 operator=(const Vec3& other);
        Vec3 operator*=(double amt);
        Vec3 operator/=(double amt);
        bool operator==(const Vec3& other) const;
        bool operator!=(const Vec3& other) const;

        double x = 0.0f;
        double y = 0.0f;
        double z = 0.0f;
    };
}