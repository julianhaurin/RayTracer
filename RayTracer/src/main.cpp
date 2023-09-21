
// Ray Tracer - Julian Haurin - 9/21/23
// C++ 20 required

// Sources:
// raytracing.github.io/books/RayTracingInOneWeekend.html

// Notes:
//

#include <iostream>
#include <cstdint>

#include <glm/glm.hpp>

#include "Scene.h"

int main() {

	
	Scene testScene(256, 256);
	testScene.RenderImage(std::cout);

	return EXIT_SUCCESS;

}
