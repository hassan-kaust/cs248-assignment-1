#include "Sphere.h"
#include <cmath>

const float EPSILON = 1e-6f;

Sphere::Sphere(float radius, const Vec3& center, const Vec3& color)
    : Object(color), R(radius), c(center) {}

float Sphere::intersect(const Ray& ray) const {
    Vec3 oc = Vec3::subtract(ray.o, c);

    float A = Vec3::dot(ray.d, ray.d);
    float B = 2.0f * Vec3::dot(ray.d, oc);
    float C = Vec3::dot(oc, oc) - R * R;

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

Vec3 Sphere::getNormal(const Vec3& point) const {
    Vec3 normal = Vec3::subtract(point, c);
    return Vec3::normalize(normal);
}
