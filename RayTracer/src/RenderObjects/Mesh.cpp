
#include "Mesh.h"

// Public Methods //

Mesh::Mesh(const std::vector<MeshVert> in_vertices, const std::vector<MeshFace> in_faces, const std::shared_ptr<Material> in_material_p)
	: m_Vertices(in_vertices), m_Faces(in_faces), m_Material_p(in_material_p)
{}

