
// Represents a cohesive mesh composes of triangle primitives

#pragma once

#include <memory>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Materials/Material.h"

#include "../RenderObjects/Triangle.h"
#include "../RenderObjects/RenderObjectList.h"

#include "CubeVertices.h"

class Model
{
public:

	Model(const std::vector<glm::vec3> in_vertices, const std::shared_ptr<Material> in_material, const float m_sizeMult);

	inline std::shared_ptr<RenderObjectList> getRenderObjectList() const { return std::make_shared<RenderObjectList>(m_renderList); }

private:

	const std::vector<glm::vec3> m_vertices;
	const std::shared_ptr<Material> m_material;
	
	const float m_sizeMult;

	RenderObjectList m_renderList;

};

