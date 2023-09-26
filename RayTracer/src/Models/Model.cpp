
#include "Model.h"

Model::Model(const std::vector<glm::vec3> in_vertices, const std::shared_ptr<Material> in_material, const float m_sizeMult)
	: m_vertices(in_vertices), m_material(in_material), m_sizeMult(m_sizeMult)
{

	//glm::mat4 projection = glm::perspective(glm::radians(
	//	60.0f),
	//	800.0f / 450.0f,
	//	0.1f, 255.0f
	//);

	// populate list of render objects with triangles using provided vertices
	for (uint32_t i = 0; i <= in_vertices.size() - 3; i++) {

		auto currentTriangle = 
			std::make_shared<Triangle>(
				in_vertices[i++], // / 400.0f, // hardcoded for now
				in_vertices[i++], // / 400.0f,
				in_vertices[i++], // / 400.0f,
				m_material
			);

		m_renderList.addObject(currentTriangle);

	}


}