
// Represents a renderable sphere

#pragma once

#include "RenderObject.h"

class Sphere : public RenderObject
{

public:
	Sphere(const glm::vec3 in_center, const float in_radius);

	const glm::vec3 m_center;
	const float m_radius;


};
