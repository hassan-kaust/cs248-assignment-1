#include "Ellipsoid.h"
#include <cmath>

const float EPSILON = 1e-6f;

Ellipsoid::Ellipsoid(const Vec3& center, float a, float b, float c, const Vec3& color)
    : Object(color), center(center), a(a), b(b), c(c) {}

float Ellipsoid::intersect(const Ray& ray) const {
    Vec3 oc = Vec3::subtract(ray.o, center);

    float a2 = a * a;
    float b2 = b * b;
    float c2 = c * c;

    float A = ray.d.x * ray.d.x / a2 + ray.d.y * ray.d.y / b2 + ray.d.z * ray.d.z / c2;
    float B = 2.0f * (oc.x * ray.d.x / a2 + oc.y * ray.d.y / b2 + oc.z * ray.d.z / c2);
    float C = oc.x * oc.x / a2 + oc.y * oc.y / b2 + oc.z * oc.z / c2 - 1.0f;

    float discriminant = B * B - 4.0f * A * C;

    if (discriminant < 0.0f) {
        return -1.0f;
    }

    float sqrtDisc = std::sqrt(discriminant);

    float t0 = (-B - sqrtDisc) / (2.0f * A);
    float t1 = (-B + sqrtDisc) / (2.0f * A);

    if (t0 > EPSILON) {
        return t0;
    }

    if (t1 > EPSILON) {
        return t1;
    }

    return -1.0f;
}

Vec3 Ellipsoid::getNormal(const Vec3& point) const {
    float a2 = a * a;
    float b2 = b * b;
    float c2 = c * c;

    float nx = 2.0f * (point.x - center.x) / a2;
    float ny = 2.0f * (point.y - center.y) / b2;
    float nz = 2.0f * (point.z - center.z) / c2;

    Vec3 normal(nx, ny, nz);
    return Vec3::normalize(normal);
}
