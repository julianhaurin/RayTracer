
// Represents a renderable sphere

#pragma once

#include "RenderObject.h"

#include <cmath>
#include <memory>

#include "../Materials/Material.h"

class Sphere : public RenderObject
{

public:

	Sphere();
	Sphere(const glm::vec3 in_center, const float in_radius, std::shared_ptr<Material> in_material_p);
	~Sphere();

	bool isHit(const Ray& in_ray, Interval in_interval, HitRecord& in_hitRecord) const override;

private:

	const glm::vec3 m_center;
	const float m_radius;
	std::shared_ptr<Material> m_material_p;

};
