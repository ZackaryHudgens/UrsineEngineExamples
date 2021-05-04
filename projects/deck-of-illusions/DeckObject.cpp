#include "DeckObject.hpp"

using DeckOfIllusions::DeckObject;

DeckObject::DeckObject()
  : GameObject()
{
}

void DeckObject::AddCard(std::unique_ptr<CardObject> aCard)
{
  glm::vec3 pos = GetPosition();

}
