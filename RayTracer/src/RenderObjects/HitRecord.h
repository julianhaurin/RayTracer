
#pragma once

#include <memory>
#include <glm/glm.hpp>

#include "../Ray.h"
#include "../Materials/Material.h"

class Material;

struct HitRecord
{

	float m_t;
	glm::vec3 m_point;
	glm::vec3 m_normal;
	bool m_isFrontFacing;
	std::shared_ptr<Material> m_material_p;

	// outward_normal is assumed to have unit length.
	void setFaceNormal(const Ray& in_ray, const glm::vec3& outwardNormal) {
		m_isFrontFacing = glm::dot(in_ray.getDirection(), outwardNormal) < 0;
		m_normal = m_isFrontFacing ? outwardNormal : -outwardNormal;
	}

};

//class HitRecord
//{
//
//public:
//
//	HitRecord();
//	HitRecord(const float in_t, const glm::vec3 in_point, const glm::vec3 in_normal, const bool in_isFrontFacing);
//
//
//
//	// outward_normal is assumed to have unit length.
//	void setFaceNormal(const Ray& in_ray, const glm::vec3& outwardNormal) {
//		m_isFrontFacing = glm::dot(in_ray.getDirection(), outwardNormal) < 0;
//		m_normal = m_isFrontFacing ? outwardNormal : -outwardNormal;
//	}
//
//	float m_t;
//	glm::vec3 m_point;
//	glm::vec3 m_normal;
//	bool m_isFrontFacing;
//	MetalMat material_p;
//
//};
