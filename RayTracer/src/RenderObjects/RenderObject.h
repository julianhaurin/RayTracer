
// Represents a scene object that can be hit by rays and therefore rendered

// Notes:
// virtual destructor being funky

#pragma once

#include <glm/glm.hpp>

#include "../Ray.h"
#include "../Utility/Interval.h"

struct HitRecord
{
	float t;
	glm::vec3 point;
	glm::vec3 normal;
	bool isFrontFacing;

	// outward_normal is assumed to have unit length.
	void setFaceNormal(const Ray& in_ray, const glm::vec3& outwardNormal) {
		isFrontFacing = glm::dot(in_ray.getDirection(), outwardNormal) < 0;
		normal = isFrontFacing ? outwardNormal : -outwardNormal;
	}

};

class RenderObject
{

public:
	// No constructor
	//virtual ~RenderObject() = 0;

	// min/max intervals for hit to be true
	virtual bool isHit(const Ray& in_ray, Interval in_interval, HitRecord& in_hitRecord) const = 0;

};
