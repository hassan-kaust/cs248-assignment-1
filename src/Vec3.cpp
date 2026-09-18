#include "Vec3.h"

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::add(const Vec3& a, const Vec3& b) {
    return a + b;
}

Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::subtract(const Vec3& a, const Vec3& b) {
    return a - b;
}

float Vec3::dot(const Vec3& a, const Vec3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 Vec3::cross(const Vec3& a, const Vec3& b) {
    return Vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

float Vec3::vectorLength(const Vec3& v) {
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vec3 Vec3::normalize(const Vec3& v) {
    float length = vectorLength(v);
    assert(length != 0.0f && "Cannot normalize a zero-length vector");
    return Vec3(v.x / length, v.y / length, v.z / length);
}

Vec3 Vec3::scalarMultiply(const Vec3& v, float c) {
    return Vec3(c * v.x, c * v.y, c * v.z);
}
