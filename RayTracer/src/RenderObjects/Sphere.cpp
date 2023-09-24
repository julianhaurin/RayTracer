
#include "Sphere.h"

// Public Methods //

Sphere::Sphere()
    : m_center(glm::vec3(0, 0, 0)), m_radius(1)
{}

Sphere::Sphere(const glm::vec3 in_center, const float in_radius, std::shared_ptr<Material> in_material_p)
	: m_center(in_center), m_radius(in_radius), m_material_p(in_material_p)
{}

Sphere::~Sphere() {

}

// returns true if the sphere is hit by the ray and updates in_hitRecord
bool Sphere::isHit(const Ray& in_ray, Interval in_interval, HitRecord& in_hitRecord) const {

    glm::vec3 originToCenter = in_ray.getOrigin() - m_center;

    const float rayLengthSquared = pow(glm::length(in_ray.getDirection()), 2); // a

    const float half_b = glm::dot(originToCenter, in_ray.getDirection());
    const float c = pow(glm::length(originToCenter), 2) - pow(m_radius, 2);

    const float discriminant = half_b * half_b - rayLengthSquared * c;
    if (discriminant < 0) return false;

    const float sqrtDisc = sqrt(discriminant);

    // find nearest root that lies in the acceptable range
    auto root = (-half_b - sqrtDisc) / rayLengthSquared;
    if (!in_interval.surrounds(root)) {
        root = (-half_b + sqrtDisc) / rayLengthSquared;
        if (!in_interval.surrounds(root)) return false;
    }

    in_hitRecord.m_t = root;
    in_hitRecord.m_point = in_ray.at(in_hitRecord.m_t);
    in_hitRecord.m_normal = (in_hitRecord.m_point - m_center) / m_radius;

    glm::vec3 outwardNormal = (in_hitRecord.m_point - m_center) / m_radius;
    in_hitRecord.setFaceNormal(in_ray, outwardNormal);
    in_hitRecord.m_material_p = m_material_p;

	return true;

}


// Private Methods