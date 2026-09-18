#pragma once

#include "Vec3.h"
#include "Object.h"
#include <vector>

Vec3 shade(const Vec3& hitPoint, const Vec3& normal, Object* closestObject, const std::vector<Object*>& scene);
