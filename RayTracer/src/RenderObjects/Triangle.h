
#pragma once

#include "RenderObject.h"

class Triangle : public RenderObject
{

public:

	Triangle(const glm::vec3 in_X, const glm::vec3 in_Y, const glm::vec3 in_Z, std::shared_ptr<Material> in_material_p);
	bool isHit(const Ray& in_ray, Interval in_interval, HitRecord& in_hitRecord) const override;

private:

	// world positions of three triangle points
	const glm::vec3 m_X;
	const glm::vec3 m_Y;
	const glm::vec3 m_Z;

	std::shared_ptr<Material> m_material_p;


};