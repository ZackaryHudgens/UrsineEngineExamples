#include <UrsineEngine/Environment.hpp>

int main()
{
  UrsineCore::Scene scene;

  /**
   * The Environment class can be accessed with the macro "env" as shown.
   * Here, we create a window and run the application. Nothing will happen
   * until you close the window.
   */
  UrsineCore::GraphicsOptions gOptions;
  gOptions.mTitle = "Hello World!";
  gOptions.mWidth = 800;
  gOptions.mHeight = 600;

  env.Initialize(gOptions);
  env.LoadScene(scene);
  env.Run();

  return 0;
}
