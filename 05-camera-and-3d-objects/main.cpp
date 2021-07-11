#include <UrsineEngine/Environment.hpp>
#include <UrsineEngine/Scene.hpp>

#include "CameraInputComponent.hpp"
#include "CubeObject.hpp"

int main()
{
  UrsineCore::GraphicsOptions gOptions;
  gOptions.mTitle = "Example 05 - Camera and 3D Objects";
  gOptions.mWidth = 800;
  gOptions.mHeight = 600;

  env.Initialize(gOptions);

  UrsineCore::Scene scene;

  scene.GetDefaultCamera()->AddComponent(std::make_unique<example_five::CameraInputComponent>());
  //scene.GetDefaultCamera()->Translate(glm::vec3(0.0, 0.0, 15.0));

  auto cube = std::make_unique<example_five::CubeObject>();
  cube->Translate(glm::vec3(0.0, 0.0, 5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>("Cube 2");
  cube->Translate(glm::vec3(10.0, 10.0, 5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>("Cube 3");
  cube->Translate(glm::vec3(-10.0, 10.0, 5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>("Cube 4");
  cube->Translate(glm::vec3(0.0, 0.0, -5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>("Cube 5");
  cube->Translate(glm::vec3(10.0, 10.0, -5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>("Cube 6");
  cube->Translate(glm::vec3(-10.0, 10.0, -5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>("Cube 7");
  cube->Translate(glm::vec3(10.0, 0.0, 0.0));
  scene.AddObject(std::move(cube));

  env.LoadScene(scene);
  env.Run();

  return 0;
}
