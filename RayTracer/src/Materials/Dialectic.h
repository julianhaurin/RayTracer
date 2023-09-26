
#pragma once

#include "Material.h"

class Dialectic : public Material
{

public:
	Dialectic(const float in_refractionIndex);

	bool Scatter(const Ray& in_ray, const HitRecord& in_hitRecord, glm::vec3& in_attenuation, Ray& in_scattered) const override;

private:
	const float m_refractionIndex;

};