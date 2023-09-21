
// Represents an image to be rendered

#pragma once

#include <iostream>
#include <cstdint>

#include <glm/glm.hpp>

class Scene
{
public:

	Scene(const uint32_t in_imageHeight, const uint32_t in_imageWidth);

	void RenderImage(std::ostream &in_outStream) const;

private:

	const uint32_t m_imageHeight;
	const uint32_t m_imageWidth;

	const uint32_t m_rgbRange;

	void writeMetadata(std::ostream& in_outStream) const;
	void writeVec3(std::ostream& in_outStream, glm::vec3 in_vec) const;


};
