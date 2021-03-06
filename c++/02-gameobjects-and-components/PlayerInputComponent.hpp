#ifndef PLAYERINPUTCOMPONENT_HPP
#define PLAYERINPUTCOMPONENT_HPP

#include <UrsineEngine/CoreSignals.hpp>
#include <UrsineEngine/Component.hpp>

namespace example_two
{
  /**
   * The base InputComponent contains several virtual functions
   * that can be overridden to provide different behavior for
   * whatever GameObject it's attached to.
   *
   * This component class simply outputs a message whenever a key
   * is pressed. We'll expand on this later.
   */
  class PlayerInputComponent : public UrsineCore::Component
  {
    public:
      PlayerInputComponent();

    private:
      void HandleKeyPress(const UrsineCore::KeyCode& aCode,
                          int aMods);
  };
}

#endif
