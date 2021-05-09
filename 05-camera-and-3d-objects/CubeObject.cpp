#include "CubeObject.hpp"

#include <UrsineEngine/Texture.hpp>

#include "CubeInputComponent.hpp"

#include <cmrc/cmrc.hpp>

CMRC_DECLARE(ShaderLib_05);

using UrsineRenderer::MeshComponent;
using UrsineRenderer::MeshVertex;
using UrsineRenderer::Shader;
using UrsineRenderer::Texture;

using example_five::CubeObject;

CubeObject::CubeObject(const std::string& aName)
  : GameObject(aName)
{
  auto cubeMesh = std::make_unique<MeshComponent>();

  SetupShaders(*cubeMesh.get());
  SetupVertexInfo(*cubeMesh.get());

  cubeMesh->SetCurrentShader("solidColor");

  AddComponent(std::move(cubeMesh));
  AddComponent(std::make_unique<CubeInputComponent>());
}

void CubeObject::SetupShaders(MeshComponent& aMesh)
{
  auto fs = cmrc::ShaderLib_05::get_filesystem();

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
  aMesh.AddTexture(wall);

  texture.SetInt("texSampler", 0);
  aMesh.AddShader("texture", Shader(vertexFile.begin(), fragmentFile.begin()));
}

void CubeObject::SetupVertexInfo(MeshComponent& aMesh)
{
  // Create the 3D vertices for thix cube.
  MeshVertex vertex;

  // Front side
  vertex.mPosition = glm::vec3(-1.0, -1.0, 1.0);
  vertex.mColor = glm::vec3(1.0, 0.0, 0.0);
  vertex.mTexCoords = glm::vec2(0.0, 0.0);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(1.0, -1.0, 1.0);
  vertex.mColor = glm::vec3(0.0, 1.0, 0.0);
  vertex.mTexCoords = glm::vec2(1.0, 0.0);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(1.0, 1.0, 1.0);
  vertex.mColor = glm::vec3(0.0, 0.0, 1.0);
  vertex.mTexCoords = glm::vec2(1.0, 1.0);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(-1.0, 1.0, 1.0);
  vertex.mColor = glm::vec3(1.0, 0.0, 0.0);
  vertex.mTexCoords = glm::vec2(0.0, 1.0);
  aMesh.AddVertex(vertex);

  // Back side
  vertex.mPosition = glm::vec3(-1.0, -1.0, -1.0);
  vertex.mColor = glm::vec3(0.0, 1.0, 0.0);
  vertex.mTexCoords = glm::vec2(0.0, 0.0);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(1.0, -1.0, -1.0);
  vertex.mColor = glm::vec3(0.0, 0.0, 1.0);
  vertex.mTexCoords = glm::vec2(1.0, 0.0);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(1.0, 1.0, -1.0);
  vertex.mColor = glm::vec3(1.0, 0.0, 0.0);
  vertex.mTexCoords = glm::vec2(1.0, 1.0);
  aMesh.AddVertex(vertex);
  vertex.mPosition = glm::vec3(-1.0, 1.0, -1.0);
  vertex.mColor = glm::vec3(0.0, 1.0, 0.0);
  vertex.mTexCoords = glm::vec2(0.0, 1.0);
  aMesh.AddVertex(vertex);

  // Specify the order in which to draw these vertices.
  // Front side
  aMesh.AddIndex(0);
  aMesh.AddIndex(1);
  aMesh.AddIndex(2);
  aMesh.AddIndex(2);
  aMesh.AddIndex(3);
  aMesh.AddIndex(0);

  // Right side
  aMesh.AddIndex(1);
  aMesh.AddIndex(5);
  aMesh.AddIndex(6);
  aMesh.AddIndex(6);
  aMesh.AddIndex(2);
  aMesh.AddIndex(1);

  // Back side
  aMesh.AddIndex(7);
  aMesh.AddIndex(6);
  aMesh.AddIndex(5);
  aMesh.AddIndex(5);
  aMesh.AddIndex(4);
  aMesh.AddIndex(7);

  // Left side
  aMesh.AddIndex(4);
  aMesh.AddIndex(0);
  aMesh.AddIndex(3);
  aMesh.AddIndex(3);
  aMesh.AddIndex(7);
  aMesh.AddIndex(4);

  // Bottom
  aMesh.AddIndex(4);
  aMesh.AddIndex(5);
  aMesh.AddIndex(1);
  aMesh.AddIndex(1);
  aMesh.AddIndex(0);
  aMesh.AddIndex(4);

  // Top
  aMesh.AddIndex(3);
  aMesh.AddIndex(2);
  aMesh.AddIndex(6);
  aMesh.AddIndex(6);
  aMesh.AddIndex(7);
  aMesh.AddIndex(3);
}
