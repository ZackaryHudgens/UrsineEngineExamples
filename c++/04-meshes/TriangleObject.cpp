#include "TriangleObject.hpp"

#include "UrsineEngine/MeshComponent.hpp"

using UrsineRenderer::MeshComponent;
using UrsineRenderer::MeshVertex;
using UrsineRenderer::VertexList;
using UrsineRenderer::IndexList;

using example_four::TriangleObject;

TriangleObject::TriangleObject()
  : GameObject()
{
  auto triangleMesh = std::make_unique<MeshComponent>();

  // Create the 3D vertices for this triangle.
  VertexList vertices;
  MeshVertex vertex;
  vertex.mPosition = glm::vec3(-0.5, -0.5, 0.0);
  vertices.emplace_back(vertex);
  vertex.mPosition = glm::vec3(0.5, -0.5, 0.0);
  vertices.emplace_back(vertex);
  vertex.mPosition = glm::vec3(0.0, 0.5, 0.0);
  vertices.emplace_back(vertex);

  triangleMesh->SetVertices(vertices);

  // Specify the order in which to draw these vertices.
  IndexList indices;
  indices.emplace_back(0);
  indices.emplace_back(1);
  indices.emplace_back(2);

  triangleMesh->SetIndices(indices);

  // Set the default color in the default shader.
  auto* shader = triangleMesh->GetShaderByName("default");
  if(shader != nullptr)
  {
    shader->Activate();
    shader->SetVec3("defaultColor", glm::vec3(1.0, 1.0, 0.0));
  }

  // Finally, add the triangle mesh to this object.
  AddComponent(std::move(triangleMesh));
}
