#include <UrsineEngine/Environment.hpp>

#include "AchievementsTracker.hpp"
#include "PlayerObject.hpp"
#include "PlayerInputComponent.hpp"

int main()
{
  /**
   * Create an AchievementsTracker to receive signals.
   */
  example_three::AchievementsTracker tracker;

  /**
   * Create a Scene and a PlayerObject, then add the PlayerObject to the Scene.
   */
  UrsineCore::Scene testScene;
  auto player = std::make_unique<example_three::PlayerObject>("Player 1");
  testScene.AddObject(std::move(player));

  /**
   * Create a window, load the Scene, and run the game. The PlayerInputComponent
   * contained in the PlayerObject will respond to key presses by printing
   * which key you pressed, as well as notifying the global QPressed signal
   * when you press the Q key.
   */
  UrsineCore::GraphicsOptions gOptions;
  gOptions.mTitle = "Example 03 - Signals";
  gOptions.mWidth = 800;
  gOptions.mHeight = 600;

  env.Initialize(gOptions);
  env.LoadScene(testScene);
  env.Run();

  return 0;
}
