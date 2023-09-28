
#include "Mesh.h"

// Public Methods //

Mesh::Mesh(const std::vector<MeshVert> in_vertices, const std::vector<MeshFace> in_faces, const std::shared_ptr<Material> in_material_p)
	: m_Vertices(in_vertices), m_Faces(in_faces), m_Material_p(in_material_p)
{}

bool Mesh::isHit(const Ray& in_ray, Interval in_interval, HitRecord& in_hitRecord) const {

	bool foundIntersection = false;

	// iterate over mesh trianges
	for (uint32_t i = 0; i < m_Faces.size(); i++) {

		const glm::vec3 vert1 = m_Faces[i].vertices[0];
		const glm::vec3 vert2 = m_Faces[i].vertices[1];
		const glm::vec3 vert3 = m_Faces[i].vertices[2];

		float t; // distance between hit on ray and origin
		glm::vec2 barycentricCoords; // barycentric coords of intersection point

		if (glm::intersectRayTriangle(in_ray.getOrigin(), in_ray.getDirection(), vert1, vert2, vert3, barycentricCoords, t) &&
			in_interval.surrounds(t))
		{
			// update hit record
			in_hitRecord.m_t = t;
			in_hitRecord.m_point = in_ray.at(in_hitRecord.m_t);

			// calculate surface normal
			const glm::vec3 surfaceNormal = glm::cross((vert2 - vert1), (vert3 - vert2));
			in_hitRecord.m_normal = surfaceNormal;

			in_hitRecord.m_isFrontFacing = glm::dot(in_ray.getDirection(), in_hitRecord.m_normal) < 0;
			in_hitRecord.m_material_p = m_Material_p;

			foundIntersection = true;

		}

	}

	return foundIntersection;

}

// Private Methods //

