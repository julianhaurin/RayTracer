
// Ray Tracer - Julian Haurin - 9/21/23

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
#include <tinyobj/tiny_obj_loader.h>

#include "Camera.h"
#include "RenderObjects/RenderObject.h"
#include "RenderObjects/RenderObjectList.h"
#include "RenderObjects/Sphere.h"
#include "RenderObjects/Triangle.h"

#include "Models/Model.h"
#include "Models/CubeVertices.h"

#include "Materials/Lambertia.h"
#include "Materials/Metal.h"
#include "Materials/Dialectic.h"

int main() {

	// Image //
	const float aspectRatio = 16.0f / 9.0f;
	const uint32_t imageWidth = 800;

	// World Objects //
	RenderObjectList worldObjects = RenderObjectList();

	auto groundMat = std::make_shared<Lambertia>(glm::vec3(0.8, 0.8, 0.9));
	//auto triangle = std::make_shared<Triangle>(glm::vec3(0.2, 0.4, -0.5), glm::vec3(0.1, -0.5, -0.5), glm::vec3(-0.3, 0.3, -0.5), groundMat);
	//worldObjects.addObject(triangle);

	std::vector<glm::vec3> triangleVertices = {
		glm::vec3(0.2f, 0.04f, -0.05f),
		glm::vec3(0.01f, -0.05f, -0.05f),
		glm::vec3(-0.03f, 0.03f, -0.05f)
	};

	Model testModel = Model(triangleVertices, groundMat, 0.5f);
	worldObjects.addObject(testModel.getRenderObjectList());


	/*
	auto material_ground = std::make_shared<Lambertia>(glm::vec3(0.8, 0.8, 0.9));
	auto material_center = std::make_shared<Lambertia>(glm::vec3(0.7, 0.3, 0.3));
	auto material_left = std::make_shared<Metal>(glm::vec3(0.8, 0.8, 0.8), 1.0f);
	auto material_right = std::make_shared<Dialectic>(1.5f);

	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(0.0, -100.5, -100.0), 100.0, material_ground));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(0.0, -0.5, -1.0), 0.5, material_right));

	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(-1.0, 0.5, -1.0), 0.5, material_left));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(1.0, -1.0, -4.0), 0.5, material_left));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(-1.0, 0.0, -20.0), 8, material_left));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(1.0, 1.0, -1.0), 1.0, material_right));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(1.0, 1.0, -1.0), 0.2, material_ground));
	*/

	// Camera //
	Camera camera = Camera(aspectRatio, imageWidth);
	
	camera.Render(worldObjects);


}
