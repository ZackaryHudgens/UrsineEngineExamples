#include "CubeInputComponent.hpp"

#include <UrsineEngine/GameObject.hpp>
#include <UrsineEngine/MeshComponent.hpp>
#include <UrsineEngine/Shader.hpp>

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
    default:
    {
      break;
    }
  }
}
