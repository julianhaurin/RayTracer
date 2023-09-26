
#include "Dialectic.h"

Dialectic::Dialectic(const float in_refractionIndex) 
	: m_refractionIndex(in_refractionIndex)
{}

bool Dialectic::Scatter(const Ray& in_ray, const HitRecord& in_hitRecord, glm::vec3& in_attenuation, Ray& in_scattered) const {

    in_attenuation = glm::vec3(1.0f, 1.0f, 1.0f);
    const float refractionRatio = in_hitRecord.m_isFrontFacing ? (1.0f / m_refractionIndex) : m_refractionIndex;

    glm::vec3 unitDir = glm::normalize(in_ray.getDirection());

    const float cosTheta = std::fmin(glm::dot(-unitDir, in_hitRecord.m_normal), 1.0f);
    const float sinTheta = sqrt(1.0f - pow(cosTheta, 2));

    glm::vec3 refracted;
    if (refractionRatio * sinTheta > 1.0f || reflectance(cosTheta, refractionRatio) > randomFloat()) { // cannot refract, so should reflect
        refracted = reflect(unitDir, in_hitRecord.m_normal);
    }
    else {
        refracted = refract(unitDir, in_hitRecord.m_normal, refractionRatio);
    }

    in_scattered = Ray(in_hitRecord.m_point, refracted);
    return true;

}

// Private Methods //

float Dialectic::reflectance(const float in_cos, const float in_relflectenceIndex) const {
    float r0 = (1 - in_relflectenceIndex) / (1 + in_relflectenceIndex);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1 - in_cos), 5);

}