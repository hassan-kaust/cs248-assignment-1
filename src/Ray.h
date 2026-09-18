#pragma once

#include "Vec3.h"

class Ray {
public:
    Vec3 o;  // ray origin
    Vec3 d;  // ray direction

    Ray(const Vec3& o, const Vec3& d);

    Vec3 evaluate(float t) const;
};
