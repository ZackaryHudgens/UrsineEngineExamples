#include "PlayerObject.hpp"

#include "PlayerInputComponent.hpp"

using example_two::PlayerObject;
using example_two::PlayerInputComponent;

PlayerObject::PlayerObject(const std::string& aName)
  : GameObject(aName)
{
  AddComponent(std::make_unique<PlayerInputComponent>());
}
