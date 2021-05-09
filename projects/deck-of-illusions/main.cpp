#include <UrsineEngine/Environment.hpp>
#include <UrsineEngine/Scene.hpp>

#include "CardObject.hpp"
#include "DeckObject.hpp"

using UrsineCore::Scene;

using DeckOfIllusions::CardObject;
using DeckOfIllusions::DeckObject;

int main()
{
  env.CreateWindow("Deck of Illusions", 800, 600);
  UrsineCore::Scene scene;

  // Create a DeckObject.
  auto deck = std::make_unique<DeckObject>();

  // TODO: set it up so that cards are added to the deck
  // from some callback (input maybe)

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
  }

  env.LoadScene(scene);
  env.Run();

  return 0;
}
