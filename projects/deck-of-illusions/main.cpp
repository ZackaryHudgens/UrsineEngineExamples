#include <UrsineEngine/Environment.hpp>
#include <UrsineEngine/Scene.hpp>

#include "CardObject.hpp"

int main()
{
  env.CreateWindow("05-camera-and-3d-objects", 800, 600);
  UrsineCore::Scene scene;

  DeckOfIllusions::CardData data;
  data.mRank = DeckOfIllusions::Rank::eACE;
  data.mSuit = DeckOfIllusions::Suit::eCLUBS;
  auto card = std::make_unique<DeckOfIllusions::CardObject>(data);
  card->Translate(glm::vec3(0.0, 0.0, -15.0));
  scene.AddObject(std::move(card));

  env.LoadScene(scene);
  env.Run();

  return 0;
}
