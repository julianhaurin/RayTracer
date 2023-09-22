
// Represents a camera

// Notes:
// some member variables initialized with default values for now

#pragma once

#include <iostream>
#include <cstdint>
#include <glm/glm.hpp>

#include "RenderObjects/RenderObject.h"

class Camera
{

public:

	Camera(const float in_aspectRatio, const uint32_t in_imageWidth);

	void Render(const RenderObject& in_worldObjects);


private:

	// input parameters
	const float m_aspectRatio;
	const uint32_t m_imageWidth;

	const uint32_t m_imageHeight;

	const glm::vec3 m_center;
	const float m_viewportHeight;
	const float m_viewportWidth;
	const glm::vec3 m_viewport_U;
	const glm::vec3 m_viewport_V;
	
	const glm::vec3 pixelDelta_U;
	const glm::vec3 pixelDelta_V;

	const glm::vec3 m_viewportUpperLeft;
	const glm::vec3 m_pixelOriginLoc;

	void writeColor(std::ostream& outStream, const glm::vec3 pixelColor);
	glm::vec3 rayColor(const Ray& in_ray, const RenderObject& in_object);


};
