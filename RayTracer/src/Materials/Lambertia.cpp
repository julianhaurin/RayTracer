
#include "Lambertia.h"

// Public Methods //

Lambertia::Lambertia(const glm::vec3& in_albedo)
	: m_albedo(in_albedo) 
{}

bool Lambertia::Scatter(
    const Ray& in_ray, const HitRecord& in_hitRec, glm::vec3& in_attenuation, Ray& in_scatteredRay
) const {
    glm::vec3 scatterDir = in_hitRec.m_normal + randomUnitVector();

    if (isVecNearZero(scatterDir))
        scatterDir = in_hitRec.m_normal;

    in_scatteredRay = Ray(in_hitRec.m_point, scatterDir);
    in_attenuation = m_albedo;
    return true;
}