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
    case UrsineCore::KeyCode::eKEY_UP:
    {
      for(auto& triangleMesh : GetParent()->GetComponentsOfType<MeshComponent>())
      {
        triangleMesh->SetCurrentShader("texture");
        if(triangleMesh->GetCurrentShader() != nullptr)
        {
          std::cout << "shader loaded successfully" << std::endl;
        }
      }
      break;
    }
    default:
    {
      break;
    }
  }
}
