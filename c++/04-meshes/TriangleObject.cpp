#include "TriangleObject.hpp"

#include <UrsineEngine/Texture.hpp>

#include "TriangleInputComponent.hpp"

#include <cmrc/cmrc.hpp>

CMRC_DECLARE(ShaderLib);

using UrsineRenderer::MeshComponent;
using UrsineRenderer::MeshVertex;
using UrsineRenderer::Shader;
using UrsineRenderer::Texture;

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

  // Texture shader
  vertexFile = fs.open("resources/shaders/Texture.vert");
  fragmentFile = fs.open("resources/shaders/Texture.frag");

  Shader texture(vertexFile.begin(), fragmentFile.begin());

  Texture wall;
  wall.LoadImageFromFile("resources/wall.jpg");
  texture.AddTexture(wall);

  texture.SetInt("texSampler", 0);
  aMesh.AddShader("texture", Shader(vertexFile.begin(), fragmentFile.begin()));
}

void TriangleObject::SetupVertexInfo(MeshComponent& aMesh)
{
  // Create the 3D vertices for this triangle.
  MeshVertex vertex;
  vertex.mPosition = glm::vec3(-0.5, -0.5, 0.0);
  vertex.mColor = glm::vec3(1.0, 0.0, 0.0);
  vertex.mTexCoords = glm::vec2(0.0, 0.0);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(0.5, -0.5, 0.0);
  vertex.mColor = glm::vec3(0.0, 1.0, 0.0);
  vertex.mTexCoords = glm::vec2(1.0, 0.0);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(0.0, 0.5, 0.0);
  vertex.mColor = glm::vec3(0.0, 0.0, 1.0);
  vertex.mTexCoords = glm::vec2(0.5, 1.0);
  aMesh.AddVertex(vertex);

  // Specify the order in which to draw these vertices.
  aMesh.AddIndex(0);
  aMesh.AddIndex(1);
  aMesh.AddIndex(2);
}
