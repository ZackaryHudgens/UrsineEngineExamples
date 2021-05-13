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
      DeckObject(const std::string& aName = "Deck");

      bool LoadDeckFromFile(const std::string& aFile);

      void AddCard(const CardData& aData);
      void Draw();
      void Shuffle();

    private:
      bool ParseDataString(CardData& aData,
                           const std::string& aLine);
      bool GetSuitFromCharacter(CardData& aData,
                                const char& aChar);
      bool GetRankFromCharacter(CardData& aData,
                                const char& aChar);

      void CreateCardObject(const CardData& aData);

      std::vector<CardData> mCards;

      bool mCardsInitialized;
  };
}

#endif
