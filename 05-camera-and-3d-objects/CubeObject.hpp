#ifndef CUBEOBJECT_HPP
#define CUBEOBJECT_HPP

#include <UrsineEngine/GameObject.hpp>
#include <UrsineEngine/MeshComponent.hpp>

namespace example_five
{
  class CubeObject : public UrsineCore::GameObject
  {
    public:
      CubeObject(const std::string& aName = "Cube");

    private:
      void SetupShaders(UrsineRenderer::MeshComponent& aMesh);
      void SetupVertexInfo(UrsineRenderer::MeshComponent& aMesh);
  };
}

#endif
