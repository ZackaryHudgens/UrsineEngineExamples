#include "TriangleObject.hpp"

#include "TriangleInputComponent.hpp"

#include <cmrc/cmrc.hpp>

CMRC_DECLARE(ShaderLib);

using UrsineRenderer::MeshComponent;
using UrsineRenderer::MeshVertex;
using UrsineRenderer::Shader;
using UrsineRenderer::VertexList;
using UrsineRenderer::IndexList;

using example_four::TriangleInputComponent;
using example_four::TriangleObject;

TriangleObject::TriangleObject()
  : GameObject()
{
  auto triangleMesh = std::make_unique<MeshComponent>();

  SetupShaders(*triangleMesh.get());
  SetupVertexInfo(*triangleMesh.get());

  triangleMesh->SetCurrentShader("solidColor");

  // Finally, add the triangle mesh to this object.
  AddComponent(std::move(triangleMesh));

  // Add the input component for switching between shaders.
  AddComponent(std::make_unique<TriangleInputComponent>());
}

void TriangleObject::SetupShaders(MeshComponent& aMesh)
{
  auto fs = cmrc::ShaderLib::get_filesystem();

  // Solid Color shader
  auto vertexFile = fs.open("resources/shaders/SolidColor.vert");
  auto fragmentFile = fs.open("resources/shaders/SolidColor.frag");

  Shader solidColor(vertexFile.begin(), fragmentFile.begin());
  solidColor.Activate();
  solidColor.SetVec3("solidColor", glm::vec3(1.0, 1.0, 0.0));
  aMesh.AddShader("solidColor", solidColor);

  // Per Vertex Color shader
  vertexFile = fs.open("resources/shaders/PerVertexColor.vert");
  fragmentFile = fs.open("resources/shaders/PerVertexColor.frag");

  Shader perVertexColor(vertexFile.begin(), fragmentFile.begin());
  aMesh.AddShader("perVertexColor", Shader(vertexFile.begin(), fragmentFile.begin()));
}

void TriangleObject::SetupVertexInfo(MeshComponent& aMesh)
{
  // Create the 3D vertices for this triangle.
  VertexList vertices;
  MeshVertex vertex;
  vertex.mPosition = glm::vec3(-0.5, -0.5, 0.0);
  vertex.mColor = glm::vec3(1.0, 0.0, 0.0);
  vertices.emplace_back(vertex);
  vertex.mPosition = glm::vec3(0.5, -0.5, 0.0);
  vertex.mColor = glm::vec3(0.0, 1.0, 0.0);
  vertices.emplace_back(vertex);
  vertex.mPosition = glm::vec3(0.0, 0.5, 0.0);
  vertex.mColor = glm::vec3(0.0, 0.0, 1.0);
  vertices.emplace_back(vertex);

  aMesh.SetVertices(vertices);

  // Specify the order in which to draw these vertices.
  IndexList indices;
  indices.emplace_back(0);
  indices.emplace_back(1);
  indices.emplace_back(2);

  aMesh.SetIndices(indices);
}
