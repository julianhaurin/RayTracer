
#pragma once

#include "CubeVertices.h"

std::vector<glm::vec3> vertices = {
   glm::vec3(-0.5f, -0.5f, -1.5f),
   glm::vec3( 0.5f, -0.5f, -1.5f),
   glm::vec3( 0.5f,  0.5f, -1.5f),
   glm::vec3( 0.5f,  0.5f, -1.5f),
   glm::vec3(-0.5f,  0.5f, -1.5f),
   glm::vec3(-0.5f, -0.5f, -1.5f),

   glm::vec3(-0.5f, -0.5f, - 0.5f),
   glm::vec3( 0.5f, -0.5f,  -0.5f),
   glm::vec3( 0.5f,  0.5f,  -0.5f),
   glm::vec3( 0.5f,  0.5f,  -0.5f),
   glm::vec3(-0.5f,  0.5f,  -0.5f),
   glm::vec3(-0.5f, -0.5f,  -0.5f),

   glm::vec3(-0.5f,  0.5f,  -0.5f),
   glm::vec3(-0.5f,  0.5f, -1.5f),
   glm::vec3(-0.5f, -0.5f, -1.5f),
   glm::vec3(-0.5f, -0.5f, -1.5f),
   glm::vec3(-0.5f, -0.5f,  -0.5f),
   glm::vec3(-0.5f,  0.5f,  -0.5f),

   glm::vec3( 0.5f,  0.5f,  -0.5f),
   glm::vec3( 0.5f,  0.5f, -1.5f),
   glm::vec3( 0.5f, -0.5f, -1.5f),
   glm::vec3( 0.5f, -0.5f, -1.5f),
   glm::vec3( 0.5f, -0.5f,  -0.5f),
   glm::vec3( 0.5f,  0.5f,  -0.5f),

   glm::vec3(-0.5f, -0.5f, -1.5f),
   glm::vec3( 0.5f, -0.5f, -1.5f),
   glm::vec3( 0.5f, -0.5f,  -0.5f),
   glm::vec3( 0.5f, -0.5f,  -0.5f),
   glm::vec3(-0.5f, -0.5f,  -0.5f),
   glm::vec3(-0.5f, -0.5f, -1.5f),

   glm::vec3(-0.5f,  0.5f, -1.5f),
   glm::vec3( 0.5f,  0.5f, -1.5f),
   glm::vec3( 0.5f,  0.5f,  -0.5f),
   glm::vec3( 0.5f,  0.5f,  -0.5f),
   glm::vec3(-0.5f,  0.5f,  -0.5f),
   glm::vec3(-0.5f,  0.5f, -1.5f)
};

std::vector<glm::vec3> CubeVertices::cubeVertices = vertices;
