
// Represents a renderable sphere

#pragma once

#include "RenderObject.h"

#include <cmath>

class Sphere : public RenderObject
{

public:

	Sphere();
	Sphere(const glm::vec3 in_center, const float in_radius);
	~Sphere();

	bool isHit(const Ray& in_ray, Interval in_interval, HitRecord& in_hitRecord) const override;

private:

	const glm::vec3 m_center;
	const float m_radius;

};
