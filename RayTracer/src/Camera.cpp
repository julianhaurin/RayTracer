
#include "Camera.h"

// Public Methods //

// holy moly
Camera::Camera(const float in_aspectRatio, const uint32_t in_imageWidth)
	: m_aspectRatio(in_aspectRatio), m_imageWidth(in_imageWidth),
	  m_imageHeight(static_cast<uint32_t>(m_imageWidth / m_aspectRatio)),
	  m_center(glm::vec3(0, 0, 0)), m_viewportHeight(2.0f), 
	  m_viewportWidth(m_viewportHeight * (static_cast<float>(m_imageWidth) / m_imageWidth)),
	  m_viewport_U(glm::vec3(m_viewportWidth, 0, 0)),
	  m_viewport_V(glm::vec3(0, -m_viewportHeight, 0)),
	  pixelDelta_U(m_viewport_U / static_cast<float>(m_imageWidth)), 
	  pixelDelta_V(m_viewport_V / static_cast<float>(m_imageHeight)),
	  m_viewportUpperLeft(m_center - glm::vec3(0, 0, 1) - m_viewport_U / 2.0f - m_viewport_V / 2.0f),
	  m_pixelOriginLoc(m_viewportUpperLeft + 0.5f * (pixelDelta_U + pixelDelta_V))
{}

void Camera::Render(const RenderObject& in_worldObjects) {

	std::cout << "P3\n";
	std::cout << m_imageWidth << " " << m_imageHeight << "\n";
	std::cout << "255\n";

	for (uint32_t i = 0; i < m_imageHeight; i++) {
		for (uint32_t j = 0; j < m_imageWidth; j++) {

			const glm::vec3 pixelCenter = m_pixelOriginLoc + ((float)i * pixelDelta_V) + ((float)j * pixelDelta_U);
			const glm::vec3 rayDirection = pixelCenter - m_center;

			Ray ray(m_center, rayDirection);

			const glm::vec3 pixelColor = rayColor(ray, in_worldObjects);
			writeColor(std::cout, pixelColor);
		}
	}

}

// Private Methods //

void Camera::writeColor(std::ostream& outStream, const glm::vec3 pixelColor) {
	outStream << static_cast<int>(255.0f * pixelColor.x) << ' '
		<< static_cast<int>(255.0f * pixelColor.y) << ' '
		<< static_cast<int>(255.0f * pixelColor.z) << '\n';
}

glm::vec3 Camera::rayColor(const Ray& in_ray, const RenderObject& in_object) {

	HitRecord hitRec;
	if (in_object.isHit(in_ray, Interval(0, INT_MAX), hitRec)) {
		return 0.5f * (hitRec.normal + glm::vec3(1, 1, 1));
	}

	glm::vec3 unitDir = glm::normalize(in_ray.getDirection());
	float a = 0.5f * (unitDir.y + 1.0f);
	return (1.0f - a) * glm::vec3(1.0f, 1.0f, 1.0f) + a * glm::vec3(0.5f, 0.7f, 1.0f);

}