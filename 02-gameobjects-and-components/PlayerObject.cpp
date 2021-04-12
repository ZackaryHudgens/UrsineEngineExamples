#include "PlayerObject.hpp"

#include "PlayerInputComponent.hpp"

using example_two::PlayerObject;
using example_two::PlayerInputComponent;

PlayerObject::PlayerObject()
  : UrsineCore::GameObject()
{
  AddComponent(std::make_unique<PlayerInputComponent>());
}
