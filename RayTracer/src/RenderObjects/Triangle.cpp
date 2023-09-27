
#include "Triangle.h"

Triangle::Triangle(const glm::vec3 in_X, const glm::vec3 in_Y, const glm::vec3 in_Z, std::shared_ptr<Material> in_material_p)
	: m_X(in_X), m_Y(in_Y), m_Z(in_Z), m_material_p(in_material_p)
{}

bool Triangle::isHit(const Ray& in_ray, Interval in_interval, HitRecord& in_hitRecord) const {

	float t; // distance between hit on ray and origin
	glm::vec2 barycentricCoords; // barycentric coords of intersection point

	if (glm::intersectRayTriangle(in_ray.getOrigin(), in_ray.getDirection(), m_X, m_Y, m_Z, barycentricCoords, t) && 
		in_interval.surrounds(t)) 
	{
		// update hit record
		in_hitRecord.m_t = t;
		in_hitRecord.m_point = in_ray.at(in_hitRecord.m_t);

		auto outward_normal = glm::cross(m_Y - m_X, m_Z - m_X); // check ***
		in_hitRecord.setFaceNormal(in_ray, outward_normal);

		in_hitRecord.m_isFrontFacing = glm::dot(in_ray.getDirection(), in_hitRecord.m_normal) < 0;
		in_hitRecord.m_material_p = m_material_p;

		return true;

	}

	return false;



	// calculate edges

	/*
	const glm::vec3 edge0 = m_Y - m_X;
	const glm::vec3 edge1 = m_Z - m_Y;
	const glm::vec3 edge2 = m_X - m_Z;

	const glm::vec3 vXvZ = m_Z - m_X;

	const glm::vec3 pVec = glm::cross(in_ray.getDirection(), vXvZ);

	// determinate determins face orientation
	const float determinate = glm::dot(edge0, pVec);

	constexpr float epsilon = std::numeric_limits<float>::epsilon();
	if (std::fabs(determinate) < epsilon) return false;

	const glm::vec3 tVec = in_ray.getOrigin() - m_X;

	const float u = glm::dot(tVec, pVec) * (1 / determinate);
	if (u < 0 || u > 1) return false;
	
	const glm::vec3 qVec = glm::cross(tVec, edge0);
	double v = glm::dot(in_ray.getDirection(), qVec) * (1 / determinate);
	if (v < 0 || u + v > 1) return false;
	
	const float t = glm::dot(vXvZ, qVec) * (1 / determinate);
	if (!in_interval.surrounds(t)) return false;
	
	// update hit record
	in_hitRecord.m_t = t;

	auto outward_normal = glm::cross(edge0, vXvZ);

	in_hitRecord.setFaceNormal(in_ray, outward_normal);
	in_hitRecord.m_material_p = m_material_p;

	in_hitRecord.m_point = in_ray.at(t);

	return true;
	*/

}