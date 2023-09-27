
// Represents a cohesive mesh composes of triangle primitives

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstdint>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <tinyobj/tiny_obj_loader.h>

#include "../Materials/Material.h"

#include "../RenderObjects/Triangle.h"
#include "../RenderObjects/RenderObjectList.h"

#include "CubeVertices.h"

class Model
{
public:

	Model(const std::vector<glm::vec3> in_vertices, const std::shared_ptr<Material> in_material, const float m_sizeMult);
	Model(const std::string in_objFilePath, const std::shared_ptr<Material> in_material, const float m_sizeMult);

	inline std::shared_ptr<RenderObjectList> getRenderObjectList() const { return std::make_shared<RenderObjectList>(m_renderList); }

private:

	std::vector<glm::vec3> m_vertices;
	std::vector<tinyobj::index_t> m_indices;

	const std::shared_ptr<Material> m_material;
	
	const float m_sizeMult;

	RenderObjectList m_renderList;

	bool loadObjData(const std::string in_objFilePath);

};

