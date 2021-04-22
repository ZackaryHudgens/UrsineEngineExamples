#include <UrsineEngine/Environment.hpp>
#include <UrsineEngine/Scene.hpp>

#include "CardObject.hpp"

using UrsineCore::Scene;

using DeckOfIllusions::CardObject;

void ShuffleCards(std::vector<CardObject*> aCards)
{
  for(int i = 0; i < aCards.size(); ++i)
  {
    // Move the card to the deck location.
    aCards[i]->Translate(glm::vec3(-3.0, 0.0, -7.0));

    // Place this card on top of the deck.
    aCards[i]->Translate(glm::vec3(0.0, 0.0, (0.01 * i)));

    // Rotate the card away from the viewer.
    aCards[i]->Rotate(180, glm::vec3(1.0, 0.0, 0.0));
  }
}

int main()
{
  env.CreateWindow("05-camera-and-3d-objects", 800, 600);
  UrsineCore::Scene scene;

  DeckOfIllusions::CardData data;
  data.mRank = DeckOfIllusions::Rank::eACE;
  data.mSuit = DeckOfIllusions::Suit::eCLUBS;

  for(int i = 0; i < 38; ++i)
  {
    auto card = std::make_unique<DeckOfIllusions::CardObject>(data);
    scene.AddObject(std::move(card));
  }

  ShuffleCards(scene.GetObjectsOfType<CardObject>());

  env.LoadScene(scene);
  env.Run();

  return 0;
}
