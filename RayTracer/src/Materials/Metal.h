
#pragma once

#include "Material.h"

#include "glm/glm.hpp"

#include "../Utility/utility.h"

class Metal : public Material
{

public:
	Metal(const glm::vec3& in_albedo, const float in_fuzzAmount);

	virtual bool Scatter(
		const Ray& in_ray, const HitRecord& in_hitRec, glm::vec3& in_attenuation, Ray& in_scatteredRay
	) const override;

private:
	const glm::vec3 m_albedo;
	const float m_fuzzAmount;

};
