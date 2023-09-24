
// Ray Tracer - Julian Haurin - 9/21/23
// C++ 20 required

// Sources:
// raytracing.github.io/books/RayTracingInOneWeekend.html

// Notes:
// image widht/height and viewport width/height need to be uniform across
// camera class and scene class - fix
// add functionality to more easily write to .ppm file
// change hittable name
// change lambertia name to lambertian

#include <iostream>
#include <cstdint>
#include <memory>

#include <glm/glm.hpp>

#include "Camera.h"
#include "RenderObjects/RenderObject.h"
#include "RenderObjects/RenderObjectList.h"
#include "RenderObjects/Sphere.h"

#include "Materials/Lambertia.h"
#include "Materials/Metal.h"

int main() {

	// Image //
	const float aspectRatio = 16.0f / 9.0f;
	const uint32_t imageWidth = 400;

	// World Objects //
	RenderObjectList worldObjects = RenderObjectList();
	
	auto material_ground = std::make_shared<Lambertia>(glm::vec3(0.8, 0.8, 0.0));
	auto material_center = std::make_shared<Lambertia>(glm::vec3(0.7, 0.3, 0.3));
	auto material_left = std::make_shared<Metal>(glm::vec3(0.8, 0.8, 0.8));
	auto material_right = std::make_shared<Metal>(glm::vec3(0.8, 0.6, 0.2));

	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(0.0, -100.5, -1.0), 100.0, material_ground));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(0.0, 0.0, -1.0), 0.5, material_center));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(-1.0, 2.0, -1.0), 0.5, material_left));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(12.0, 0.0, -4.0), 0.1, material_right));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(-2.0, 0.0, -1.0), 0.1, material_left));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(1.0, 4.0, -1.0), 0.2, material_right));

	// Camera //
	Camera camera = Camera(aspectRatio, imageWidth);
	
	camera.Render(worldObjects);


}
