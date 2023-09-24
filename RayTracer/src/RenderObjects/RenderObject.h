
// Represents a scene object that can be hit by rays and therefore rendered

// Notes:
// virtual destructor being funky

#pragma once

#include <memory>
#include <glm/glm.hpp>

#include "../Ray.h"
#include "../Utility/Interval.h"
#include "HitRecord.h"

class RenderObject
{

public:
	// No constructor
	//virtual ~RenderObject() = 0;

	// min/max intervals for hit to be true
	virtual bool isHit(const Ray& in_ray, Interval in_interval, HitRecord& in_hitRecord) const = 0;

private:

};
