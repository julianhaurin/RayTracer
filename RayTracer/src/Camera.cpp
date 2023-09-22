
#include "Camera.h"

// Public Methods //

Camera::Camera(const float in_viewportHeight, const float in_imageHeight, const float in_aspectRatio)
	: m_viewportHeight(in_viewportHeight), 
	  m_viewportWidth(in_viewportHeight * in_aspectRatio),
	  m_viewport_U(glm::vec3(m_viewportWidth, 0.0f, 0.0f)),
	  m_viewport_V(glm::vec3(0.0f, -m_viewportHeight, 0.0f)),
	  m_pixelDelta_U(m_viewport_U / (in_imageHeight * in_aspectRatio)),
	  m_pixelDelta_V(in_viewportHeight / in_imageHeight),
	  m_focalLength(1),
	  m_center(glm::vec3(0.0f, 0.0f, 0.0f)), 
	  m_viewportUpperLeft(m_center - glm::vec3(0, 0, m_focalLength) - (m_viewport_U / 2.0f) - (m_viewport_V / 2.0f)),
	  m_pixelOriginLoc(m_viewportUpperLeft + 0.5f * (m_pixelDelta_U + m_pixelDelta_V))
{}	

glm::vec3 Camera::getPixelCenter(const float height, const float width) const {
	return m_pixelOriginLoc + (height * m_pixelDelta_U) + (width * m_pixelDelta_V);

}

glm::vec3 Camera::getRayDirection(const glm::vec3 in_pixelCenter) const {
	return in_pixelCenter - m_center;
}

// Private Methods //


