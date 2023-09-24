
#pragma once

#include <glm/glm.hpp>

#include "../Ray.h"
#include "../RenderObjects/HitRecord.h"

struct HitRecord;

class Material
{

public:

    virtual bool Scatter(
        const Ray& in_ray, const HitRecord& in_hitRec, glm::vec3& in_attenuation, Ray& in_scatteredRay
    ) const = 0;

};