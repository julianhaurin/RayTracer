
// Ray Tracer - Julian Haurin - 9/21/23
// C++ 20 required

// Sources:
// raytracing.github.io/books/RayTracingInOneWeekend.html

// Notes:
// image widht/height and viewport width/height need to be uniform across
// camera class and scene class - fix

#include <iostream>
#include <cstdint>

#include <glm/glm.hpp>

#include "Camera.h"
#include "Scene.h"

int main() {

	// viewport height, image height, aspect ratio
	Camera camera(2.0f, 800.0f, 16.0f / 9.0f); 


	Scene scene(camera, 256, 256);
	scene.RenderImage(std::cout);

	return EXIT_SUCCESS;

}
