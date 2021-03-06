#ifndef PLAYERINPUTCOMPONENT_HPP
#define PLAYERINPUTCOMPONENT_HPP

#include <UrsineEngine/CoreSignals.hpp>
#include <UrsineEngine/Component.hpp>

namespace example_three
{
  /**
   * The base InputComponent contains several virtual functions
   * that can be overridden to provide different behavior for
   * whatever GameObject it's attached to.
   *
   * This component class outputs a message whenever a key is pressed,
   * and if that key was the "q" key, it notifies the appropriate signal.
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
