#include "Util.h"
#include <algorithm>

Vec3 clampColor(const Vec3& color) {
    Vec3 scaled = Vec3::scalarMultiply(color, 255.0f);

    float x = std::min(std::max(scaled.x, 0.0f), 255.0f);
    float y = std::min(std::max(scaled.y, 0.0f), 255.0f);
    float z = std::min(std::max(scaled.z, 0.0f), 255.0f);

    return Vec3(x, y, z);
}
