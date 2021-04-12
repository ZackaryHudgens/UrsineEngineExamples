#include "PlayerInputComponent.hpp"

#include <iostream>

using example_two::PlayerInputComponent;

PlayerInputComponent::PlayerInputComponent()
  : Component()
{
  UrsineCore::KeyPressed.Connect(*this, [this](const UrsineCore::KeyCode& aCode,
                                               int aMods)
  {
    this->HandleKeyPress(aCode, aMods);
  });
}

void PlayerInputComponent::HandleKeyPress(const UrsineCore::KeyCode& aCode,
                                          int aMods)
{
  switch(aCode)
  {
    case UrsineCore::KeyCode::eKEY_UNKNOWN:
    {
      std::cout << "You pressed an unrecognized key!" << std::endl;
      break;
    }
    default:
    {
      std::cout << "You pressed the "
                << UrsineCore::GetKeyName(aCode)
                << " key!"
                << std::endl;
      break;
    }
  }
}
