
// Represents a camera

// Notes:

#pragma once

#include <cstdint>
#include <glm/glm.hpp>

class Camera
{

public:

	Camera(const float in_viewportHeight, const float in_imageHeight, const float in_aspectRatio);

	glm::vec3 getPixelCenter(const float height, const float width) const;
	glm::vec3 getRayDirection(const glm::vec3 in_pixelCenter) const;

	inline glm::vec3 getCameraCenter() const { return m_center; }

private:

	// camera and viewport data //
	const float m_viewportHeight;
	const float m_viewportWidth;

	const glm::vec3 m_viewport_U; // horizontal vector
	const glm::vec3 m_viewport_V; // vertical vector

	const glm::vec3 m_pixelDelta_U; // horizontal delta between pixels
	const glm::vec3 m_pixelDelta_V; // vertical delta between pixels

	const uint32_t m_focalLength;

	const glm::vec3 m_center;

	const glm::vec3 m_viewportUpperLeft;
	const glm::vec3 m_pixelOriginLoc; // pixel (0, 0)

	


};
