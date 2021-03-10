#ifndef TRIANGLEOBJECT_HPP
#define TRIANGLEOBJECT_HPP

#include <UrsineEngine/GameObject.hpp>

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
  };
}

#endif
