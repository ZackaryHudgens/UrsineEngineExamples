#include "TriangleInputComponent.hpp"

#include <UrsineEngine/GameObject.hpp>
#include <UrsineEngine/MeshComponent.hpp>
#include <UrsineEngine/Shader.hpp>

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
}

void TriangleInputComponent::HandleKeyPress(const UrsineCore::KeyCode& aCode,
                                            int aMods)
{
  switch(aCode)
  {
    case UrsineCore::KeyCode::eKEY_LEFT:
    {
      for(auto& triangleMesh : GetParent()->GetComponentsOfType<MeshComponent>())
      {
        triangleMesh->SetCurrentShader("solidColor");
      }
      break;
    }
    case UrsineCore::KeyCode::eKEY_RIGHT:
    {
      for(auto& triangleMesh : GetParent()->GetComponentsOfType<MeshComponent>())
      {
        triangleMesh->SetCurrentShader("perVertexColor");
      }
      break;
    }
    default:
    {
      break;
    }
  }
}
