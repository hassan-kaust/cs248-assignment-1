#include "RayGenerator.h"

Ray generateRay(int i, int j, int nx, int ny, bool isPerspective) {
    Vec3 e(0, 0, -1);

    float l = -2.0f;
    float r = 2.0f;
    float t = 1.5f;
    float b = -1.5f;

    float u = l + (r - l) * (i + 0.5f) / nx;
    float v = b + (t - b) * (j + 0.5f) / ny;

    if (!isPerspective) {
        return Ray(Vec3(u, v, 0), Vec3(0, 0, 1));
    } else {
        Vec3 origin = e;
        Vec3 dir = Vec3::subtract(Vec3(u, v, 0), e);
        return Ray(origin, Vec3::normalize(dir));
    }
}
