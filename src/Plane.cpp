#include "Plane.h"
#include <cmath>

const float EPSILON = 1e-6f;

Plane::Plane(const Vec3& point, const Vec3& normal, const Vec3& color)
    : Object(color), point(point), normal(normal) {}

float Plane::intersect(const Ray& ray) const {
    float denom = Vec3::dot(normal, ray.d);

    if (std::abs(denom) < EPSILON) {
        return -1.0f;
    }

    Vec3 diff = Vec3::subtract(point, ray.o);
    float t = Vec3::dot(normal, diff) / denom;

    if (t > EPSILON) {
        return t;
    }

    return -1.0f;
}

Vec3 Plane::getNormal(const Vec3& point) const {
    return normal;
}
