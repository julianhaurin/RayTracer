
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
	  m_pixelDelta_U(m_viewport_U / static_cast<float>(m_imageWidth)), 
	  m_pixelDelta_V(m_viewport_V / static_cast<float>(m_imageHeight)),
	  m_viewportUpperLeft(m_center - glm::vec3(0, 0, 1) - m_viewport_U / 2.0f - m_viewport_V / 2.0f),
	  m_pixelOriginLoc(m_viewportUpperLeft + 0.5f * (m_pixelDelta_U + m_pixelDelta_V)),
	  m_samplesPerPixel(10)
{}

void Camera::Render(const RenderObject& in_worldObjects) {

	std::cout << "P3\n";
	std::cout << m_imageWidth << " " << m_imageHeight << "\n";
	std::cout << "255\n";

	for (uint32_t i = 0; i < m_imageHeight; i++) {
		for (uint32_t j = 0; j < m_imageWidth; j++) {

			glm::vec3 pixelColor(0, 0, 0);
			for (int sample = 0; sample < m_samplesPerPixel; sample++) {
				Ray ray = getRay(j, i);
				pixelColor += rayColor(ray, in_worldObjects, 10); // *** 10 == max ray bounce depth
			}
			writeColor(std::cout, pixelColor, m_samplesPerPixel);

		}
	}

}

// Private Methods //

void Camera::writeColor(std::ostream& outStream, const glm::vec3 pixelColor, const uint32_t in_sampelsPerPixel) {

	float r = pixelColor.x;
	float g = pixelColor.y;
	float b = pixelColor.z;

	// Divide the color by the number of samples.
	const float scale = 1.0f / in_sampelsPerPixel;
	r *= scale;
	g *= scale;
	b *= scale;

	static const Interval intensity(0.000, 0.999);
	outStream << static_cast<int>(256 * intensity.clamp(r)) << ' '
		 	  << static_cast<int>(256 * intensity.clamp(g)) << ' '
			  << static_cast<int>(256 * intensity.clamp(b)) << std::endl;
}

glm::vec3 Camera::pixelSampleSquare() const {
	const float px = -0.5f + randomFloat(0.0f, 1.0f);
	const float py = -0.5f + randomFloat(0.0f, 1.0f);
	return (px * m_pixelDelta_U) + (py * m_pixelDelta_V);
}

Ray Camera::getRay(uint32_t i, uint32_t j) const {
	const glm::vec3 pixelCenter = m_pixelOriginLoc + ((float)i * m_pixelDelta_U) + ((float)j * m_pixelDelta_V);
	const glm::vec3 pixelSample = pixelCenter + pixelSampleSquare();

	const glm::vec3 rayOrigin = m_center;
	const glm::vec3 rayDirection = pixelSample - rayOrigin;

	return Ray(rayOrigin, rayDirection);
}


glm::vec3 Camera::rayColor(const Ray& in_ray, const RenderObject& in_object, const int32_t in_depth) {

	if (in_depth <= 0) return glm::vec3(0, 0, 0);

	HitRecord hitRec;

	if (in_object.isHit(in_ray, Interval(0.001f, INT_MAX), hitRec)) {
		Ray scattered = Ray(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
        glm::vec3 attenuation;
        if (hitRec.m_material_p->Scatter(in_ray, hitRec, attenuation, scattered))
            return attenuation * rayColor(scattered, in_object, in_depth - 1);
        return glm::vec3(0,0,0);
	}

	glm::vec3 unitDir = glm::normalize(in_ray.getDirection());
	float a = 0.5f * (unitDir.y + 1.0f);
	return (1.0f - a) * glm::vec3(1.0f, 1.0f, 1.0f) + a * glm::vec3(0.5f, 0.7f, 1.0f);

}