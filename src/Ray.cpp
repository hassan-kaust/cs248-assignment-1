#include "Ray.h"

Ray::Ray(const Vec3& o, const Vec3& d) : o(o), d(d) {}

Vec3 Ray::evaluate(float t) const {
    return Vec3::add(o, Vec3::scalarMultiply(d, t));
}
