#ifndef TRIANGLEOBJECT_HPP
#define TRIANGLEOBJECT_HPP

#include <UrsineEngine/GameObject.hpp>
#include <UrsineEngine/MeshComponent.hpp>

using UrsineRenderer::MeshComponent;

namespace example_four
{
  /**
   * A basic player class. Now it takes a name as an argument during
   * construction.
   */
  class TriangleObject : public UrsineCore::GameObject
  {
    public:
      TriangleObject();

    private:
      void SetupShaders(MeshComponent& aMesh);
      void SetupVertexInfo(MeshComponent& aMesh);
  };
}

#endif
