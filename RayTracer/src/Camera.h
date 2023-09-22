
// Represents a camera

// Notes:
// some member variables initialized with default values for now

#pragma once

#include <iostream>
#include <cstdint>
#include <glm/glm.hpp>

#include "RenderObjects/RenderObject.h"
#include "Utility/utility.h"

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
	
	const glm::vec3 m_pixelDelta_U;
	const glm::vec3 m_pixelDelta_V;

	const glm::vec3 m_viewportUpperLeft;
	const glm::vec3 m_pixelOriginLoc;

	const uint32_t m_samplesPerPixel;

	void writeColor(std::ostream& outStream, const glm::vec3 pixelColor, const uint32_t in_sampelsPerPixel);

	glm::vec3 pixelSampleSquare() const;
	Ray getRay(uint32_t i, uint32_t j) const;

	glm::vec3 rayColor(const Ray& in_ray, const RenderObject& in_object, const int32_t in_depth);

};
