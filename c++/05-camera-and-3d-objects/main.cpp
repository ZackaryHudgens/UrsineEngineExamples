#include <UrsineEngine/Environment.hpp>
#include <UrsineEngine/Scene.hpp>

#include "CameraInputComponent.hpp"
#include "CubeObject.hpp"

int main()
{
  env.CreateWindow("05-camera-and-3d-objects", 800, 600);

  UrsineCore::Scene scene;

  scene.GetDefaultCamera()->AddComponent(std::make_unique<example_five::CameraInputComponent>());
  //scene.GetDefaultCamera()->Translate(glm::vec3(0.0, 0.0, 15.0));

  auto cube = std::make_unique<example_five::CubeObject>();
  cube->Translate(glm::vec3(0.0, 0.0, 5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>();
  cube->Translate(glm::vec3(10.0, 10.0, 5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>();
  cube->Translate(glm::vec3(-10.0, 10.0, 5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>();
  cube->Translate(glm::vec3(0.0, 0.0, -5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>();
  cube->Translate(glm::vec3(10.0, 10.0, -5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>();
  cube->Translate(glm::vec3(-10.0, 10.0, -5.0));
  scene.AddObject(std::move(cube));

  cube = std::make_unique<example_five::CubeObject>();
  cube->Translate(glm::vec3(10.0, 0.0, 0.0));
  scene.AddObject(std::move(cube));

  env.LoadScene(scene);
  env.Run();

  return 0;
}
