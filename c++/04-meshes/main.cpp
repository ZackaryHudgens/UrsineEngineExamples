#include "UrsineEngine/Environment.hpp"
#include "UrsineEngine/Scene.hpp"

#include "TriangleObject.hpp"

int main()
{
  env.CreateWindow("04-meshes", 800, 600);

  UrsineCore::Scene scene;

  auto triangle = std::make_unique<example_four::TriangleObject>();
  scene.AddObject(std::move(triangle));

  env.LoadScene(scene);
  env.Run();

  return 0;
}
