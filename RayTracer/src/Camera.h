
// Represents a camera

// Notes:
// some member variables initialized with default values for now

#pragma once

#include <iostream>
#include <cstdint>
#include <cmath>

#include <glm/glm.hpp>

#include "RenderObjects/RenderObject.h"
#include "Utility/utility.h"

class Camera
{

public:

	Camera(const float in_aspectRatio, const uint32_t in_imageWidth, const float in_vertFOV = 90.0f);

	void Render(const RenderObject& in_worldObjects);


private:

	// input parameters
	const float m_aspectRatio; // ratio of imageWidth to imageHeight
	const uint32_t m_imageWidth;

	const uint32_t m_imageHeight;
	const uint32_t m_vFOV; // vertical FOV

	const uint32_t m_maxDepth; // max ray bounces per ray
	const uint32_t m_samplesPerPixel; // random samples per pixel (antialiasing)

	glm::vec3 m_position; // global position of camera
	glm::vec3 m_lookAtPoint; // global position camera is looking at
	glm::vec3 m_cameraUp;

	const float m_defocusAngle; // variation angle of rays through each pixel
	const float m_focusDistance; // distance between position and plane of focus
	
	glm::vec3 m_pixelOriginLoc;

	glm::vec3 m_pixelDelta_U;
	glm::vec3 m_pixelDelta_V;

	// camera frame basis vectors //
	glm::vec3 m_U;
	glm::vec3 m_V;
	glm::vec3 m_W;

	glm::vec3 m_defocusDisk_U;  // defocus disk horizontal radius
	glm::vec3 m_defocusDisk_V;

	glm::vec3 m_viewportUpperLeft;

	// methods //
	void Initialize();

	void writeColor(std::ostream& outStream, const glm::vec3 pixelColor, const uint32_t in_sampelsPerPixel);

	glm::vec3 pixelSampleSquare() const;
	Ray getRay(uint32_t i, uint32_t j) const;

	glm::vec3 rayColor(const Ray& in_ray, const RenderObject& in_object, const int32_t in_depth);

};
