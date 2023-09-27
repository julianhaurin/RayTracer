
#include "Model.h"

Model::Model(const std::vector<glm::vec3> in_vertices, const std::shared_ptr<Material> in_material, const float m_sizeMult)
	: m_vertices(in_vertices), m_indices(std::vector<tinyobj::index_t>()),
	  m_material(in_material), m_sizeMult(m_sizeMult)
{

	// populate list of render objects with triangles using provided vertices
	for (uint32_t i = 0; i <= m_vertices.size() - 3; i++) {

		const glm::vec3 vert1 = m_vertices[i++];
		const glm::vec3 vert2 = m_vertices[i++];
		const glm::vec3 vert3 = m_vertices[i++];

		auto currentTriangle = std::make_shared<Triangle>(vert1, vert2, vert3, m_material);

		m_renderList.addObject(currentTriangle);

	}


}

Model::Model(const std::string in_objFilePath, const std::shared_ptr<Material> in_material, const float m_sizeMult)
	: m_vertices(std::vector<glm::vec3>()), m_indices(std::vector<tinyobj::index_t>()),
	  m_material(in_material), m_sizeMult(m_sizeMult)
{
	loadObjData(in_objFilePath);

	// abstract to function
	for (uint32_t i = 0; i <= m_vertices.size() - 3; i++) {

		const glm::vec3 vert1 = m_vertices[i++];
		const glm::vec3 vert2 = m_vertices[i++];
		const glm::vec3 vert3 = m_vertices[i++];

		auto currentTriangle = std::make_shared<Triangle>(vert1, vert2, vert3, m_material);

		m_renderList.addObject(currentTriangle);

	}

}

// Private Methods //

// code taken from environment simulator
bool Model::loadObjData(const std::string in_objFilePath) {

	tinyobj::ObjReader objReader;

	tinyobj::ObjReaderConfig objReaderConfig;
	objReaderConfig.mtl_search_path = "./assets/textures/";

	// reads file data
	bool readStatus = objReader.ParseFromFile(in_objFilePath, objReaderConfig);

	// handles error messages
	if (readStatus == false) {
		// prints error message
		std::cout << "[J] ERROR - TINYOBJLOADER: unable to read from .obj file " << in_objFilePath << ": ";
		std::cout << objReader.Error() << std::endl;
		return false;

	}

	// handles warning messages
	//if (!objReader.Warning().empty()) {
	//	std::cout << "[J] WARNING - TINYOBJLOADER: warning when reading obj data from file " << in_objFilePath << ": ";
	//	std::cout << objReader.Warning() << std::endl;
	//}

	// loads data into containers //
	const tinyobj::attrib_t attrib = objReader.GetAttrib();
	const std::vector<tinyobj::shape_t> shapes = objReader.GetShapes();
	const std::vector<tinyobj::material_t> materials = objReader.GetMaterials();

	// populate class data //

	// loop over shapes
	for (size_t shapeIdx = 0; shapeIdx < shapes.size(); shapeIdx++) {
		size_t idxOffset = 0;

		// loop over faces
		for (size_t faceIdx = 0; faceIdx < shapes[shapeIdx].mesh.num_face_vertices.size(); faceIdx++) {
			size_t faceVertices = size_t(shapes[shapeIdx].mesh.num_face_vertices[faceIdx]);

			for (size_t vertIdx = 0; vertIdx < faceVertices; vertIdx++) {

				tinyobj::index_t index = shapes[shapeIdx].mesh.indices[idxOffset + vertIdx];
				m_indices.push_back(index);

				// *** no size multiplyer for now
				glm::vec3 currentVertex(
					(attrib.vertices[3 * (float)index.vertex_index] - 20) / 10,
					(attrib.vertices[3 * (float)index.vertex_index + 1] - 20) / 10,
					(attrib.vertices[3 * (float)index.vertex_index + 2] - 20) / 10
				);

				m_vertices.push_back(currentVertex);

			}

			idxOffset += faceVertices;

		}
	}

	return true;

}
