#include "BackpackInputComponent.hpp"

#include <UrsineEngine/GameObject.hpp>

using example_four::BackpackInputComponent;

BackpackInputComponent::BackpackInputComponent()
  : Component()
{
  core::KeyPressed.Connect(*this, [this](const core::KeyCode& aCode,
                                         int aMods)
  {
    this->HandleKeyPress(aCode, aMods);
  });

  core::KeyRepeated.Connect(*this, [this](const core::KeyCode& aCode,
                                          int aMods)
  {
    this->HandleKeyPress(aCode, aMods);
  });
}

void BackpackInputComponent::HandleKeyPress(const core::KeyCode& aCode,
                                            int aMods)
{
  switch(aCode)
  {
    case core::KeyCode::eKEY_LEFT:
    case core::KeyCode::eKEY_A:
    {
      GetParent()->Rotate(-1, glm::vec3(0.0f, 1.0f, 0.0f));
      break;
    }
    case core::KeyCode::eKEY_RIGHT:
    case core::KeyCode::eKEY_D:
    {
      GetParent()->Rotate(1, glm::vec3(0.0f, 1.0f, 0.0f));
      break;
    }
    case core::KeyCode::eKEY_UP:
    case core::KeyCode::eKEY_W:
    {
      GetParent()->Rotate(-1, glm::vec3(1.0f, 0.0f, 0.0f));
      break;
    }
    case core::KeyCode::eKEY_DOWN:
    case core::KeyCode::eKEY_S:
    {
      GetParent()->Rotate(1, glm::vec3(1.0f, 0.0f, 0.0f));
      break;
    }
    default:
    {
      break;
    }
  }
}
