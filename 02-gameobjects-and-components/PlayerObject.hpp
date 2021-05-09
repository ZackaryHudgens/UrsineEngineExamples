#ifndef PLAYEROBJECT_HPP
#define PLAYEROBJECT_HPP

#include <UrsineEngine/GameObject.hpp>

using UrsineCore::GameObject;

namespace example_two
{
  /**
   * A basic player class. Creates and adds a PlayerInputComponent
   * upon construction.
   */
  class PlayerObject : public GameObject
  {
    public:
      PlayerObject(const std::string& aName = "Player");
  };
}

#endif
