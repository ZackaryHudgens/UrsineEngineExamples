#ifndef PLAYEROBJECT_HPP
#define PLAYEROBJECT_HPP

#include <UrsineEngine/GameObject.hpp>

namespace example_two
{
  /**
   * A basic player class. Creates and adds a PlayerInputComponent
   * upon construction.
   */
  class PlayerObject : public UrsineCore::GameObject
  {
    public:
      PlayerObject();
  };
}

#endif
