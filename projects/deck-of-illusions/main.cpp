#include <UrsineEngine/Environment.hpp>
#include <UrsineEngine/Scene.hpp>

#include "CardMovementComponent.hpp"
#include "CardObject.hpp"

using UrsineCore::Scene;

using DeckOfIllusions::CardMovementComponent;
using DeckOfIllusions::CardObject;

void ShuffleCards(std::vector<CardObject*> aCards)
{
  for(int i = 0; i < aCards.size(); ++i)
  {
    // Rotate the card to face away from the viewer.
    aCards[i]->Rotate(180, glm::vec3(0.0, 1.0, 0.0));

    // Rotate the card to lie flat (well, flat-ish).
    aCards[i]->Rotate(55, glm::vec3(1.0, 0.0, 0.0));
    aCards[i]->Rotate(15, glm::vec3(0.0, 0.0, 1.0));

    // Position the card high above the camera.
    aCards[i]->Translate(glm::vec3(0.0, (2.0 * (i + 1)), -5.0));

    // Move this card to the top of the deck.
    for(auto& c : aCards[i]->GetComponentsOfType<CardMovementComponent>())
    {
      glm::vec3 topOfDeck = glm::vec3(0.0, (0.01 * i), -5.0);
      c->MoveTo(topOfDeck, 0.002);
    }
  }
}

int main()
{
  env.CreateWindow("Deck of Illusions", 800, 600);
  UrsineCore::Scene scene;

  DeckOfIllusions::CardData data;
  for(int i = 0; i < 34; ++i)
  {
    // Determine rank
    if(i == 32 || i == 33)
    {
      data.mRank = DeckOfIllusions::Rank::eJOKER;
    }
    else if(i % 8 == 0)
    {
      data.mRank = DeckOfIllusions::Rank::eACE;
    }
    else if(i % 7 == 0)
    {
      data.mRank = DeckOfIllusions::Rank::eKING;
    }
    else if(i % 6 == 0)
    {
      data.mRank = DeckOfIllusions::Rank::eQUEEN;
    }
    else if(i % 5 == 0)
    {
      data.mRank = DeckOfIllusions::Rank::eJACK;
    }
    else if(i % 4 == 0)
    {
      data.mRank = DeckOfIllusions::Rank::eTEN;
    }
    else if(i % 3 == 0)
    {
      data.mRank = DeckOfIllusions::Rank::eNINE;
    }
    else if(i % 2 == 0)
    {
      data.mRank = DeckOfIllusions::Rank::eEIGHT;
    }
    else
    {
      data.mRank = DeckOfIllusions::Rank::eTWO;
    }

    // Determine suit
    if(i < 8)
    {
      data.mSuit = DeckOfIllusions::Suit::eCLUBS;
    }
    else if(i < 16)
    {
      data.mSuit = DeckOfIllusions::Suit::eDIAMONDS;
    }
    else if(i < 24)
    {
      data.mSuit = DeckOfIllusions::Suit::eSPADES;
    }
    else if(i < 32)
    {
      data.mSuit = DeckOfIllusions::Suit::eHEARTS;
    }
    else
    {
      data.mSuit = DeckOfIllusions::Suit::eJOKER;
    }

    auto card = std::make_unique<DeckOfIllusions::CardObject>(data);
    scene.AddObject(std::move(card));
  }

  ShuffleCards(scene.GetObjectsOfType<CardObject>());

  scene.GetDefaultCamera()->Translate(glm::vec3(0.0, 1.0, 0.0));

  env.LoadScene(scene);
  env.Run();

  return 0;
}
