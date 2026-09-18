#pragma once

#include "Object.h"

class Sphere : public Object {
public:
    float R;
    Vec3 c;

    Sphere(float radius, const Vec3& center, const Vec3& color = Vec3(1, 1, 1));

    float intersect(const Ray& ray) const override;
    Vec3 getNormal(const Vec3& point) const override;
};
