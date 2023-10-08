
#pragma once

#include <cmath>
#include <random>

#include "glm/glm.hpp"

# define PI 3.14159265358979323846

// gamma correction
inline float linearToGamma(const float in_linearComponent) { return sqrt(in_linearComponent); }

inline float degreesToRadians(const float in_degrees) { return in_degrees * (PI / 180.0f); }

float randomFloat(const float min = 0.0f, const float max = 1.0f);

glm::vec3 randomVec3(const float min = 0.0f, const float max = 1.0f);
glm::vec3 randomVec3inUnitSphere();

glm::vec3 randomUnitVector();

glm::vec3 randomVec3onHemisphere(const glm::vec3& in_normal);

bool isVecNearZero(const glm::vec3 in_vec);

glm::vec3 reflect(const glm::vec3 in_vec1, const glm::vec3 in_vec2);
glm::vec3 refract(const glm::vec3 in_vec1, const glm::vec3 in_vec2, const float in_etaiOverEtat);


