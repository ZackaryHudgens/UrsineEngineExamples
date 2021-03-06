#ifndef PLAYEROBJECT_HPP
#define PLAYEROBJECT_HPP

#include <UrsineEngine/GameObject.hpp>
#include <UrsineEngine/Signal.hpp>

namespace example_three
{
  /**
   * A basic player class. Now it takes a name as an argument during
   * construction.
   */
  class PlayerObject : public UrsineCore::GameObject
  {
    public:
      PlayerObject(const std::string& aName);

      std::string GetPlayerName() const { return mName; }

    private:
      std::string mName;
  };
}

#endif
