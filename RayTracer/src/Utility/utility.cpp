
#include "utility.h"

float randomFloat(const float min, const float max) {

    static std::uniform_real_distribution<float> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);

}

glm::vec3 randomVec3(const float min, const float max) {

    return glm::vec3(randomFloat(min, max), randomFloat(min, max), randomFloat(min, max));

}

glm::vec3 randomVec3inUnitSphere() {
    while (true) {
        glm::vec3 vec = randomVec3(-1.0f, 1.0f);
        if (pow(glm::length(vec), 2) < 1)
            return vec;
    }
}

glm::vec3 randomUnitVector() {
    return glm::normalize(randomVec3inUnitSphere());
}

glm::vec3 randomVec3onHemisphere(const glm::vec3& in_normal) {
    glm::vec3 onUnitSphere = randomUnitVector();
    if (glm::dot(onUnitSphere, in_normal) > 0.0f) // In the same hemisphere as the normal
        return onUnitSphere;

    return -onUnitSphere;
}

bool isVecNearZero(const glm::vec3 in_vec) {
    const float size = 1e-8f;
    return (fabs(in_vec.x) < size) && (fabs(in_vec.y) < size) && (fabs(in_vec.z) < size);
}

glm::vec3 reflect(const glm::vec3 in_vec1, const glm::vec3 in_vec2) {
    return in_vec1 - 2 * dot(in_vec1, in_vec2) * in_vec2;
}

