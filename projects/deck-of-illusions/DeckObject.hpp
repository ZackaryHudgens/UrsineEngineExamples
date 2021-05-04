#ifndef DECKOBJECT_HPP
#define DECKOBJECT_HPP

#include <UrsineEngine/GameObject.hpp>

#include "CardObject.hpp"

using UrsineCore::GameObject;

namespace DeckOfIllusions
{
  class DeckObject : public GameObject
  {
    public:
      DeckObject();

      void AddCard(std::unique_ptr<CardObject> aCard);
      void Draw();
      void Shuffle();

    private:
      std::vector<std::unique_ptr<CardObject>> mCards;
  };
}

#endif
