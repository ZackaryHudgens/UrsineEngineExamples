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
    // Place this card on top of the deck.
    //aCards[i]->Translate(glm::vec3(0.0, (0.01 * i) - 1.0, -5.0));
    aCards[i]->Translate(glm::vec3(0.0, (1.0 * i), -5.0));

    for(auto& c : aCards[i]->GetComponentsOfType<CardMovementComponent>())
    {
      c->MoveTo(glm::vec3(0.0, (1.0 * i), (-3.5 + (1.0 * i) - (0.01 * i))), 0.002);
    }

    // Rotate the card so it's lying down.
    aCards[i]->Rotate(90, glm::vec3(1.0, 0.0, 0.0));
  }
}

int main()
{
  env.CreateWindow("05-camera-and-3d-objects", 800, 600);
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

  env.LoadScene(scene);
  env.Run();

  return 0;
}
