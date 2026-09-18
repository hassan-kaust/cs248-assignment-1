#include "Shade.h"

const float EPSILON = 1e-6f;

Vec3 shade(const Vec3& hitPoint, const Vec3& normal, Object* closestObject, const std::vector<Object*>& scene) {
    Vec3 I(1.0f, 1.0f, 1.0f);
    Vec3 lightPos(0.0f, 5.0f, 0.0f);
    float ka = 0.2f;
    float kd = 0.8f;

    Vec3 ambient = Vec3::scalarMultiply(closestObject->color, ka);

    Vec3 l = Vec3::subtract(lightPos, hitPoint);
    float distToLight = Vec3::vectorLength(l);
    l = Vec3::normalize(l);

    Ray shadowRay(hitPoint, l);

    bool inShadow = false;
    for (Object* obj : scene) {
        float t = obj->intersect(shadowRay);
        if (t > EPSILON && t < distToLight) {
            inShadow = true;
            break;
        }
    }

    if (inShadow) {
        return ambient;
    } else {
        float cosTheta = Vec3::dot(normal, l);
        cosTheta = cosTheta > 0.0f ? cosTheta : 0.0f;

        Vec3 diffuse = Vec3::scalarMultiply(closestObject->color, kd * cosTheta);
        return Vec3::add(ambient, diffuse);
    }
}
