#include "CubeInputComponent.hpp"

#include <UrsineEngine/GameObject.hpp>
#include <UrsineEngine/MeshComponent.hpp>
#include <UrsineEngine/Shader.hpp>

#include <iostream>

using UrsineRenderer::MeshComponent;

using example_five::CubeInputComponent;

CubeInputComponent::CubeInputComponent()
  : Component()
{
  UrsineCore::KeyPressed.Connect(*this, [this](const UrsineCore::KeyCode& aCode,
                                               int aMods)
  {
    this->HandleKeyPress(aCode, aMods);
  });

  UrsineCore::KeyRepeated.Connect(*this, [this](const UrsineCore::KeyCode& aCode,
                                                int aMods)
  {
    this->HandleKeyRepeat(aCode, aMods);
  });
}

void CubeInputComponent::HandleKeyPress(const UrsineCore::KeyCode& aCode,
                                        int aMods)
{
  switch(aCode)
  {
    case UrsineCore::KeyCode::eKEY_Q:
    {
      for(auto& cubeMesh : GetParent()->GetComponentsOfType<MeshComponent>())
      {
        cubeMesh->SetCurrentShader("solidColor");
      }
      break;
    }
    case UrsineCore::KeyCode::eKEY_W:
    {
      for(auto& cubeMesh : GetParent()->GetComponentsOfType<MeshComponent>())
      {
        cubeMesh->SetCurrentShader("perVertexColor");
      }
      break;
    }
    case UrsineCore::KeyCode::eKEY_E:
    {
      for(auto& cubeMesh : GetParent()->GetComponentsOfType<MeshComponent>())
      {
        cubeMesh->SetCurrentShader("texture");
      }
      break;
    }
    case UrsineCore::KeyCode::eKEY_LEFT:
    {
      GetParent()->Rotate(5, glm::vec3(0.0, 1.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_RIGHT:
    {
      GetParent()->Rotate(-5, glm::vec3(0.0, 1.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_UP:
    {
      GetParent()->Rotate(-5, glm::vec3(1.0, 0.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_DOWN:
    {
      GetParent()->Rotate(5, glm::vec3(1.0, 0.0, 0.0));
      break;
    }
    default:
    {
      break;
    }
  }
}

void CubeInputComponent::HandleKeyRepeat(const UrsineCore::KeyCode& aCode,
                                         int aMods)
{
  switch(aCode)
  {
    case UrsineCore::KeyCode::eKEY_LEFT:
    {
      GetParent()->Rotate(5, glm::vec3(0.0, 1.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_RIGHT:
    {
      GetParent()->Rotate(-5, glm::vec3(0.0, 1.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_UP:
    {
      GetParent()->Rotate(-5, glm::vec3(1.0, 0.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_DOWN:
    {
      GetParent()->Rotate(5, glm::vec3(1.0, 0.0, 0.0));
      break;
    }
    default:
    {
      break;
    }
  }
}
