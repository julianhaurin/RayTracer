
#pragma once

#include "RenderObject.h"

#include <memory>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

#include "../Materials/Material.h"

struct MeshVert
{

	glm::vec3 position;
	glm::vec3 normal;

	MeshVert(const glm::vec3 in_pos, const glm::vec3 in_norm)
		: position(in_pos), normal(in_norm)
	{}

};

struct MeshFace
{

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;

	MeshFace(const std::vector<glm::vec3> in_vertices, const std::vector<glm::vec3> in_normals)
		: vertices(in_vertices), normals(vertices)
	{}

};

class Mesh : public RenderObject
{

public:
	Mesh(const std::vector<MeshVert> in_vertices, const std::vector<MeshFace> in_faces, const std::shared_ptr<Material> in_material_p);

	bool isHit(const Ray& in_ray, Interval in_interval, HitRecord& in_hitRecord) const;

private:
	std::vector<MeshVert> m_Vertices;
	std::vector<MeshFace> m_Faces;

	const std::shared_ptr<Material> m_Material_p;

};
