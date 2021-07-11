#include <UrsineEngine/Environment.hpp>

#include "PlayerObject.hpp"
#include "PlayerInputComponent.hpp"

int main()
{
  /**
   * Create a Scene and a PlayerObject, then add the PlayerObject to the Scene.
   */
  UrsineCore::Scene testScene;
  auto player = std::make_unique<example_two::PlayerObject>();
  testScene.AddObject(std::move(player));

  /**
   * Create a window, load the Scene, and run the game. The PlayerInputComponent
   * contained in the PlayerObject will respond to key presses by printing
   * which key you pressed.
   */
  UrsineCore::GraphicsOptions gOptions;
  gOptions.mTitle = "Example 02 - GameObjects and Components";
  gOptions.mWidth = 800;
  gOptions.mHeight = 600;

  env.Initialize(gOptions);
  env.LoadScene(testScene);
  env.Run();

  return 0;
}
