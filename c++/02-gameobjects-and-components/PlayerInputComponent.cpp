#include "PlayerInputComponent.hpp"

#include <iostream>

// Included here to get the name of the key via glfwGetKeyName().
// TODO: Every InputComponent is going to need this. Find a better way?
#include <GLFW/glfw3.h>

using example_two::PlayerInputComponent;

PlayerInputComponent::PlayerInputComponent()
  : InputComponent()
{
}

void PlayerInputComponent::HandleKeyPress(int aKey,
                                          int aScancode,
                                          int aMods)
{
  const char* keyName = glfwGetKeyName(aKey, aScancode);
  if(keyName != nullptr)
  {
    std::cout << "You just pressed "
              << keyName
              << "!"
              << std::endl;
  }
  else
  {
    std::cout << "You just pressed a key GLFW didn't recognize!" << std::endl;
  }
}
