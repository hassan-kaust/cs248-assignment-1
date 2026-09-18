#pragma once

#include "Object.h"

class Ellipsoid : public Object {
public:
    Vec3 center;
    float a, b, c;

    Ellipsoid(const Vec3& center, float a, float b, float c, const Vec3& color = Vec3(1, 1, 1));

    float intersect(const Ray& ray) const override;
    Vec3 getNormal(const Vec3& point) const override;
};
