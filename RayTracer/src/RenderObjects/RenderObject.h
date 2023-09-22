
// Represents a scene object that can be hit by rays and therefore rendered

#pragma once

#include <glm/glm.hpp>

#include "../Ray.h"

struct HitRecord
{
	float t;
	glm::vec3 point;
	glm::vec3 normal;

};

class RenderObject
{

public:
	// No constructor
	virtual ~RenderObject() = 0;

	// min/max intervals for hit to be true
	virtual bool isHit(const Ray& in_ray, const float minInt, const float maxInt) const = 0;

};
