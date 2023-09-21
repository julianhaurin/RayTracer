
// Implements ray class

#include "Ray.h"

// Public Methods //

Ray::Ray() {

}

Ray::Ray(const glm::vec3 in_origin, const glm::vec3 in_direction) 
	: m_origin(in_origin), m_direction(in_direction)
{

}

// Private Methods //


