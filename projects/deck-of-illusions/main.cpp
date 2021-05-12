#include <UrsineEngine/Environment.hpp>
#include <UrsineEngine/Scene.hpp>

#include "CardObject.hpp"
#include "DeckObject.hpp"

using UrsineCore::Scene;

using DeckOfIllusions::DeckObject;

int main()
{
  env.CreateWindow("Deck of Illusions", 800, 600);
  UrsineCore::Scene scene;

  // Create a DeckObject.
  auto deck = std::make_unique<DeckObject>();
  deck->LoadDeckFromFile("resources/deck.txt");
  deck->Translate(glm::vec3(1.0, 0.0, -15.0));
  scene.AddObject(std::move(deck));

  scene.GetDefaultCamera()->Translate(glm::vec3(0.0, 0.0, 5.0));

  env.LoadScene(scene);
  env.Run();

  return 0;
}
