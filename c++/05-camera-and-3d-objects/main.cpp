#include "UrsineEngine/Environment.hpp"
#include "UrsineEngine/Scene.hpp"

#include "CubeObject.hpp"

int main()
{
  env.CreateWindow("05-camera-and-3d-objects", 800, 600);

  UrsineCore::Scene scene;

  scene.GetDefaultCamera()->Translate(glm::vec3(0.0, 0.0, 3.0));

  auto cube = std::make_unique<example_five::CubeObject>();
  scene.AddObject(std::move(cube));

  env.LoadScene(scene);
  env.Run();

  return 0;
}
