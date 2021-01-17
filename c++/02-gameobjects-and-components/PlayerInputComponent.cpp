#include "PlayerInputComponent.hpp"

#include <iostream>

using example_two::PlayerInputComponent;

PlayerInputComponent::PlayerInputComponent()
  : InputComponent()
{
}

void PlayerInputComponent::HandleKeyPress(const core::KeyCode& aCode,
                                          int aMods)
{
  switch(aCode)
  {
    case core::KeyCode::eKEY_UNKNOWN:
    {
      std::cout << "You pressed an unrecognized key!" << std::endl;
      break;
    }
    default:
    {
      std::cout << "You pressed the "
                << core::GetKeyName(aCode)
                << " key!"
                << std::endl;
      break;
    }
  }
}
