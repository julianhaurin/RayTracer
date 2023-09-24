
// Represents a ray vector in 3 dimensional space

#pragma once

#include <glm/glm.hpp>

class Ray
{

public:

	//Ray();
	Ray(const glm::vec3 in_origin, const glm::vec3 in_direction);

	// getters
	inline glm::vec3 getOrigin() const { return m_origin; }
	inline glm::vec3 getDirection() const { return m_direction; }

	// ray function: P(t) = A + tb, A is origin, b is direction, t is param reps. distnce
	inline glm::vec3 at(float t) const { return m_origin + t * m_direction; }

private:

	glm::vec3 m_origin;
	glm::vec3 m_direction;

};
