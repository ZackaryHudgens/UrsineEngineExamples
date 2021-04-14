#include "CardObjectRotateComponent.hpp"

#include <UrsineEngine/GameObject.hpp>

#include <iostream>

using DeckOfIllusions::CardObjectRotateComponent;

CardObjectRotateComponent::CardObjectRotateComponent()
  : Component()
{
}

void CardObjectRotateComponent::Update()
{
  GetParent()->Rotate(0.1, glm::vec3(GetParent()->GetPosition().x, 1.0, 0.0));
}
