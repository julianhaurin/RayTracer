
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
#include <cstdint>

#include <glm/glm.hpp>

#include "Camera.h"
#include "RenderObjects/RenderObject.h"
#include "RenderObjects/RenderObjectList.h"
#include "RenderObjects/Sphere.h"


int main() {

	// Image //
	const float aspectRatio = 2.0f / 1.0f;
	const uint32_t imageWidth = 400;

	// World Objects //
	RenderObjectList worldObjects = RenderObjectList();
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(0, 0, -1), 0.5f));
	worldObjects.addObject(std::make_shared<Sphere>(glm::vec3(0, -100.5f, -1), 100.0f));

	// Camera //
	Camera camera = Camera(aspectRatio, imageWidth);
	
	camera.Render(worldObjects);


}
