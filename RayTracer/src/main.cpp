
// Ray Tracer - Julian Haurin - 9/21/23
// C++ 20 required

// Sources:
// raytracing.github.io/books/RayTracingInOneWeekend.html

// Notes:
// image widht/height and viewport width/height need to be uniform across
// camera class and scene class - fix
// add functionality to more easily write to .ppm file
// change hittable name

#include <iostream>
#include <fstream>
#include <cstdint>
#include <cmath>

#include <glm/glm.hpp>

#include "Camera.h"
#include "Scene.h"
#include "RenderObjects/RenderObject.h"
#include "RenderObjects/RenderObjectList.h"
#include "RenderObjects/Sphere.h"

void writeColor(std::ostream& outStream, const glm::vec3 pixelColor);
glm::vec3 rayColor(const Ray& in_ray, const RenderObject& in_object);

int main() {

	// Image //
	const float aspectRatio = 16.0f / 9.0f;
	const uint32_t imageWidth = 400;
	const uint32_t imageHeight = static_cast<uint32_t>(imageWidth / aspectRatio);

	// World Objects //
	
	RenderObjectList worldObjects = RenderObjectList();
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(0, 0, -1), 0.5f));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(0, -100.5f, -1), 100.0f));

	// Camera //
	const float focalLength = 1.0f;
	const float viewportHeight = 2.0f;
	const float viewportWidth = viewportHeight * (static_cast<float>(imageWidth) /  imageHeight);
	const glm::vec3 cameraCenter(0.0f, 0.0f, 0.0f);

	const glm::vec3 viewport_U(viewportWidth, 0, 0);
	const glm::vec3 viewport_V(0, -viewportHeight, 0);

	const glm::vec3 pixelDelta_U = viewport_U / static_cast<float>(imageWidth);
	const glm::vec3 pixelDelta_V = viewport_V / static_cast<float>(imageHeight);

	const glm::vec3 viewportUpperLeft =
		cameraCenter - glm::vec3(0, 0, focalLength) - viewport_U / 2.0f - viewport_V / 2.0f;

	const glm::vec3 pixelOriginLoc = viewportUpperLeft + 0.5f * (pixelDelta_U + pixelDelta_V);

	std::cout << "P3\n";
	std::cout << imageWidth << " " << imageHeight << "\n";
	std::cout << "255\n";

	for (uint32_t i = 0; i < imageHeight; i++) {
		for (uint32_t j = 0; j < imageWidth; j++) {

			const glm::vec3 pixelCenter = pixelOriginLoc + ((float)i * pixelDelta_V) + ((float)j * pixelDelta_U);
			const glm::vec3 rayDirection = pixelCenter - cameraCenter;

			Ray ray(cameraCenter, rayDirection);

			const glm::vec3 pixelColor = rayColor(ray, worldObjects);
			writeColor(std::cout, pixelColor);
		}
	}



}

void writeColor(std::ostream& outStream, const glm::vec3 pixelColor) {
	outStream << static_cast<int>(255.0f * pixelColor.x) << ' '
			  << static_cast<int>(255.0f * pixelColor.y) << ' '
			  << static_cast<int>(255.0f * pixelColor.z) << '\n';
}

float hitSphere(const glm::vec3 in_center, const float radius, const Ray& in_ray) {
	const glm::vec3 oc = in_ray.getOrigin() - in_center;
	auto a = glm::dot(in_ray.getDirection(), in_ray.getDirection());
	auto b = 2.0 * glm::dot(oc, in_ray.getDirection());
	auto c = dot(oc, oc) - radius * radius;
	auto discriminant = b * b - 4 * a * c;

	if (discriminant < 0) {
		return -1.0;
	}
	return (-b - sqrt(discriminant)) / (2.0f * a);
	

}

glm::vec3 rayColor(const Ray& in_ray, const RenderObject& in_object) {
	
	HitRecord hitRec;
	if (in_object.isHit(in_ray, Interval(0, INT_MAX), hitRec)) {
		return 0.5f * (hitRec.normal + glm::vec3(1, 1, 1));
	}

	glm::vec3 unitDir = glm::normalize(in_ray.getDirection());
	float a = 0.5f * (unitDir.y + 1.0f);
	return (1.0f - a) * glm::vec3(1.0f, 1.0f, 1.0f) + a * glm::vec3(0.5f, 0.7f, 1.0f);

}