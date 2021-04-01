#include "TriangleInputComponent.hpp"

#include <UrsineEngine/GameObject.hpp>
#include <UrsineEngine/MeshComponent.hpp>
#include <UrsineEngine/Shader.hpp>

#include <iostream>

using UrsineRenderer::MeshComponent;

using example_four::TriangleInputComponent;

TriangleInputComponent::TriangleInputComponent()
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

void TriangleInputComponent::HandleKeyPress(const UrsineCore::KeyCode& aCode,
                                            int aMods)
{
  switch(aCode)
  {
    case UrsineCore::KeyCode::eKEY_Q:
    {
      for(auto& triangleMesh : GetParent()->GetComponentsOfType<MeshComponent>())
      {
        triangleMesh->SetCurrentShader("solidColor");
      }
      break;
    }
    case UrsineCore::KeyCode::eKEY_W:
    {
      for(auto& triangleMesh : GetParent()->GetComponentsOfType<MeshComponent>())
      {
        triangleMesh->SetCurrentShader("perVertexColor");
      }
      break;
    }
    case UrsineCore::KeyCode::eKEY_E:
    {
      for(auto& triangleMesh : GetParent()->GetComponentsOfType<MeshComponent>())
      {
        triangleMesh->SetCurrentShader("texture");
      }
      break;
    }
    case UrsineCore::KeyCode::eKEY_LEFT:
    {
      GetParent()->Rotate(1, glm::vec3(0.0, 1.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_RIGHT:
    {
      GetParent()->Rotate(-1, glm::vec3(0.0, 1.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_UP:
    {
      GetParent()->Rotate(-1, glm::vec3(1.0, 0.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_DOWN:
    {
      GetParent()->Rotate(1, glm::vec3(1.0, 0.0, 0.0));
      break;
    }
    default:
    {
      break;
    }
  }
}

void TriangleInputComponent::HandleKeyRepeat(const UrsineCore::KeyCode& aCode,
                                             int aMods)
{
  switch(aCode)
  {
    case UrsineCore::KeyCode::eKEY_LEFT:
    {
      GetParent()->Rotate(1, glm::vec3(0.0, 1.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_RIGHT:
    {
      GetParent()->Rotate(-1, glm::vec3(0.0, 1.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_UP:
    {
      GetParent()->Rotate(-1, glm::vec3(1.0, 0.0, 0.0));
      break;
    }
    case UrsineCore::KeyCode::eKEY_DOWN:
    {
      GetParent()->Rotate(1, glm::vec3(1.0, 0.0, 0.0));
      break;
    }
    default:
    {
      break;
    }
  }
}
