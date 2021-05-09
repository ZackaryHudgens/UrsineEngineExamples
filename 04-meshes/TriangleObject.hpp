#ifndef TRIANGLEOBJECT_HPP
#define TRIANGLEOBJECT_HPP

#include <UrsineEngine/GameObject.hpp>
#include <UrsineEngine/MeshComponent.hpp>

namespace example_four
{
  class TriangleObject : public UrsineCore::GameObject
  {
    public:
      TriangleObject(const std::string& aName = "Triangle");

    private:
      void SetupShaders(UrsineRenderer::MeshComponent& aMesh);
      void SetupVertexInfo(UrsineRenderer::MeshComponent& aMesh);
  };
}

#endif
