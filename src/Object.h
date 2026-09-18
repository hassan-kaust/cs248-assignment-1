#pragma once

#include "Vec3.h"
#include "Ray.h"

class Object {
public:
    Vec3 color;

    Object(const Vec3& color = Vec3(1, 1, 1));
    virtual ~Object();

    virtual float intersect(const Ray& ray) const = 0;
    virtual Vec3 getNormal(const Vec3& point) const = 0;
};
