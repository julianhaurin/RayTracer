

#pragma once

#include <random>

#include "glm/glm.hpp"

float randomFloat(const float min = 0.0f, const float max = 1.0f);

glm::vec3 randomVec3(const float min = 0.0f, const float max = 1.0f);
glm::vec3 randomVec3inUnitSphere();

glm::vec3 randomUnitVector();

glm::vec3 randomVec3onHemisphere(const glm::vec3& in_normal);

