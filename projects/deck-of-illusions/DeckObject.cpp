#include "DeckObject.hpp"

#include <fstream>
#include <iostream>

#include <glm/gtx/string_cast.hpp>

#include "CardMovementComponent.hpp"

using DeckOfIllusions::CardData;
using DeckOfIllusions::DeckObject;
using DeckOfIllusions::Rank;
using DeckOfIllusions::Suit;

DeckObject::DeckObject(const std::string& aName)
  : GameObject(aName)
  , mCardsInitialized(false)
{
}

bool DeckObject::LoadDeckFromFile(const std::string& aFile)
{
  bool success = true;

  std::ifstream in;
  in.open(aFile);

  success = in.is_open();
  if(success)
  {
    std::string line;
    while(std::getline(in, line))
    {
      CardData data;
      success = ParseDataString(data, line);
      if(success)
      {
        AddCard(data);
      }
      else
      {
        std::cout << "Couldn't parse line: " << line << std::endl;
        break;
      }
    }
  }
  else
  {
    std::cout << "Couldn't open file: " << aFile << std::endl;
  }

  in.close();

  return success;
}

void DeckObject::AddCard(const CardData& aData)
{
  mCards.emplace_back(aData);
  CreateCardObject(aData);
}

void DeckObject::Draw()
{
}

void DeckObject::Shuffle()
{
}

bool DeckObject::ParseDataString(CardData& aData,
                                 const std::string& aLine)
{
  bool success = true;
  bool readingDescription = false;

  if(aLine.size() < 2)
  {
    success = false;
  }
  else
  {
    for(int i = 0; i < aLine.size(); ++i)
    {
      if(!success)
      {
        break;
      }

      if(i == 0)
      {
        success = GetSuitFromCharacter(aData, aLine[i]);
      }
      else if (i == 1)
      {
        success = GetRankFromCharacter(aData, aLine[i]);
      }
      else if(readingDescription)
      {
        if(aLine[i] == '\"')
        {
          readingDescription = false;
          break;
        }
        else
        {
          aData.mDescription += aLine[i];
        }
      }
      else if(aLine[i] == '\"')
      {
        readingDescription = true;
      }
    }
  }

  return success;
}

bool DeckObject::GetSuitFromCharacter(CardData& aData,
                                      const char& aChar)
{
  bool success = true;

  if(aChar == 'c')
  {
    aData.mSuit = Suit::eCLUBS;
  }
  else if(aChar == 'd')
  {
    aData.mSuit = Suit::eDIAMONDS;
  }
  else if(aChar == 's')
  {
    aData.mSuit = Suit::eSPADES;
  }
  else if(aChar == 'h')
  {
    aData.mSuit = Suit::eHEARTS;
  }
  else if(aChar == 'j')
  {
    aData.mSuit = Suit::eJOKER;
  }
  else
  {
    success = false;
  }

  return success;
}

bool DeckObject::GetRankFromCharacter(CardData& aData,
                                      const char& aChar)
{
  bool success = true;

  if(aData.mSuit == Suit::eJOKER)
  {
    aData.mRank = Rank::eJOKER;
  }
  else if(aChar == '2')
  {
    aData.mRank = Rank::eTWO;
  }
  else if(aChar == '8')
  {
    aData.mRank = Rank::eEIGHT;
  }
  else if(aChar == '9')
  {
    aData.mRank = Rank::eNINE;
  }
  else if(aChar == 't')
  {
    aData.mRank = Rank::eTEN;
  }
  else if(aChar == 'j')
  {
    aData.mRank = Rank::eJACK;
  }
  else if(aChar == 'k')
  {
    aData.mRank = Rank::eKING;
  }
  else if(aChar == 'q')
  {
    aData.mRank = Rank::eQUEEN;
  }
  else if(aChar == 'a')
  {
    aData.mRank = Rank::eACE;
  }
  else
  {
    success = false;
  }

  return success;
}

void DeckObject::CreateCardObject(const CardData& aData)
{
  // Create a new card object with this data.
  auto cardObj = std::make_unique<CardObject>(aData);

  // Rotate the card to face away from the viewer.
  cardObj->Rotate(180, glm::vec3(0.0, 1.0, 0.0));

  // Rotate the card to lie flat.
  cardObj->Rotate(55, glm::vec3(1.0, 0.0, 0.0));

  // Position the card high above the top of the deck.
  std::vector<GameObject*> cards;
  for(const auto& child : GetChildren())
  {
    if(dynamic_cast<CardObject*>(child) != nullptr)
    {
      cards.emplace_back(child);
    }
  }

  glm::vec3 topOfDeck = glm::vec3(GetPosition().x,
                                  (0.01 * cards.size()),
                                  GetPosition().z);
  cardObj->Translate(glm::vec3(topOfDeck.x,
                               topOfDeck.y + (2.0 * cards.size()),
                               topOfDeck.z));

  // Move the card to the top of the deck.
  for(auto& moveComponent : cardObj->GetComponentsOfType<CardMovementComponent>())
  {
    moveComponent->MoveTo(topOfDeck, 0.002);
  }

  // Finally, add the card as a child GameObject.
  AddChild(std::move(cardObj));
}
