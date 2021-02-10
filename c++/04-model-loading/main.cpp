#include <UrsineEngine/Environment.hpp>

#include "BackpackObject.hpp"

int main()
{
  env.CreateWindow("Example 04 - Model Loading", 800, 600);

  core::Scene scene;
  auto backpack = std::make_unique<example_four::BackpackObject>();
  backpack->Translate(glm::vec3(0.0f, 0.0f, -10.0f));

  scene.AddObject(std::move(backpack));

  env.LoadScene(scene);
  env.Run();

  return 0;
}
