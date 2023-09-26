
#include "Metal.h"

Metal::Metal(const glm::vec3& in_albedo, const float in_fuzzAmount)
	: m_albedo(in_albedo), 
	  m_fuzzAmount(in_fuzzAmount < 1.0f && in_fuzzAmount >= 0.0f ? in_fuzzAmount : 1.0f)
{}

bool Metal::Scatter(
	const Ray& in_ray, const HitRecord& in_hitRec, glm::vec3& in_attenuation, Ray& in_scatteredRay
) const {

	glm::vec3 reflected = reflect(glm::normalize(in_ray.getDirection()), in_hitRec.m_normal);
	in_scatteredRay = Ray(in_hitRec.m_point, reflected + randomUnitVector() * m_fuzzAmount);
	in_attenuation = m_albedo;
	return (glm::dot(in_scatteredRay.getDirection(), in_hitRec.m_normal) > 0);

}

