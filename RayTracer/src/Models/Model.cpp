
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

// Private Methods //

bool Model::loadObjData() {

	tinyobj::ObjReader objReader;

	tinyobj::ObjReaderConfig objReaderConfig;
	objReaderConfig.mtl_search_path = "./assets/textures/";

	// reads file data
	bool readStatus = objReader.ParseFromFile(m_objFilePath, objReaderConfig);

	// handles error messages
	if (readStatus == false) {
		// prints error message
		std::cout << "[J] ERROR - TINYOBJLOADER: unable to read from .obj file " << m_objFilePath << ": ";
		std::cout << objReader.Error() << std::endl;
		return false;

	}

	// handles warning messages
	if (!objReader.Warning().empty()) {
		std::cout << "[J] WARNING - TINYOBJLOADER: warning when reading obj data from file " << m_objFilePath << ": ";
		std::cout << objReader.Warning() << std::endl;
	}

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

				// EBO data
				m_IndexData.push_back(index);

				// VBO data //

				// vertex position
				m_VertexData.push_back(attrib.vertices[3 * (float)index.vertex_index] * m_vertexPositionMultiplyer); // + 0
				m_VertexData.push_back(attrib.vertices[3 * (float)index.vertex_index + 1] * m_vertexPositionMultiplyer);
				m_VertexData.push_back(attrib.vertices[3 * (float)index.vertex_index + 2] * m_vertexPositionMultiplyer);

				// rgb color value
				//m_VertexData.push_back(attrib.colors[3 * size_t(index.vertex_index)]); // + 0
				//m_VertexData.push_back(attrib.colors[3 * size_t(index.vertex_index) + 1]);
				//m_VertexData.push_back(attrib.colors[3 * size_t(index.vertex_index) + 2]);

				// normal data
				if (index.normal_index >= 0) {
					m_VertexData.push_back(attrib.normals[3 * size_t(index.normal_index)]); // + 0
					m_VertexData.push_back(attrib.normals[3 * size_t(index.normal_index) + 1]);
					m_VertexData.push_back(attrib.normals[3 * size_t(index.normal_index) + 2]);
				}

			}

			idxOffset += faceVertices;

		}
	}

	std::cout << "[J] - Successfully loaded model obj data! \n";

	//for (int i = 0; i < m_VertexData.size(); i++) {
	//	std::cout << m_VertexData[i] << " ";
	//	if ((i+1) % 3 == 0) std::cout << "\n";
	//}

	return true;

}
