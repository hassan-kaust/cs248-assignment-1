#pragma once

#include "Object.h"

class Plane : public Object {
public:
    Vec3 point;
    Vec3 normal;

    Plane(const Vec3& point, const Vec3& normal, const Vec3& color = Vec3(1, 1, 1));

    float intersect(const Ray& ray) const override;
    Vec3 getNormal(const Vec3& point) const override;
};
