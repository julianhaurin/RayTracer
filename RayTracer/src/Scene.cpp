
// Implementation of a single scene

#include "Scene.h"

// Public Methods //

Scene::Scene(const Camera& in_camera, const uint32_t in_imageHeight, const uint32_t in_imageWidth)
	: m_camera(in_camera),
	  m_imageHeight(in_imageHeight), m_imageWidth(in_imageWidth), 
	  m_aspectRatio(in_imageWidth / m_imageHeight), m_rgbRange(255)
{}

void Scene::RenderImage(std::ostream& in_outStream) const {

	//std::cout << "[J] - Rendering image... " << std::endl;
	writeMetadata(in_outStream);

	for (int i = 0; i < m_imageHeight; i++) {
		// progress bar
		//std::clog << "\rScanlines remaining: " << (m_imageHeight - i) << ' ' << std::flush;

		for (int j = 0; j < m_imageWidth; j++) {

			glm::vec3 pixelCenter = m_camera.getPixelCenter(i, j);
			glm::vec3 rayDir = m_camera.getRayDirection(pixelCenter);

			Ray ray(m_camera.getCameraCenter(), rayDir);

			//glm::vec3 pixelColor(float(i) / (m_imageWidth - 1.0f), float(j) / (m_imageHeight - 1.0f), 0.0f);
			//glm::vec3 pixelColor = rayColor(ray);
			//writeVec3(in_outStream, pixelColor);

		}
	}

	//std::cout << "[J] - Successfully rendered image! " << std::endl;

}

// Private Methods //

// writes meta data of PPM file
void Scene::writeMetadata(std::ostream& in_outStream) const {

	in_outStream << "P3" << std::endl;
	in_outStream << m_imageWidth << " " << m_imageHeight << std::endl;
	in_outStream << m_rgbRange << std::endl;
	
}

// note: multiplies each color value by max RGB range - in_vec should be normalized
void Scene::writeVec3(std::ostream& in_outStream, glm::vec3 in_vec) const {
	in_outStream << static_cast<uint32_t>(m_rgbRange * in_vec.x) << " "
				 << static_cast<uint32_t>(m_rgbRange * in_vec.y) << " "
				 << static_cast<uint32_t>(m_rgbRange * in_vec.z) << std::endl;
}

