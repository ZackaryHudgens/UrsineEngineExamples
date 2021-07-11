#include "UrsineEngine/Environment.hpp"
#include "UrsineEngine/Scene.hpp"

#include "TriangleObject.hpp"

int main()
{
  UrsineCore::GraphicsOptions gOptions;
  gOptions.mTitle = "Example 04 - Meshes";
  gOptions.mWidth = 800;
  gOptions.mHeight = 600;

  env.Initialize(gOptions);

  UrsineCore::Scene scene;

  auto triangle = std::make_unique<example_four::TriangleObject>();
  scene.AddObject(std::move(triangle));

  env.LoadScene(scene);
  env.Run();

  return 0;
}
