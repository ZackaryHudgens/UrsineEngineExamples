#include <UrsineEngine/Environment.hpp>

int main()
{
  UrsineCore::Scene scene;

  /**
   * The Environment class can be accessed with the macro "env" as shown.
   * Here, we create a window and run the application. Nothing will happen
   * until you close the window.
   */
  env.CreateWindow("Hello World!", 800, 600);
  env.LoadScene(scene);
  env.Run();

  return 0;
}
