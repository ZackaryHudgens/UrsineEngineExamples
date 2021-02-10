#ifndef BACKPACKINPUTCOMPONENT_HPP
#define BACKPACKINPUTCOMPONENT_HPP

#include <UrsineEngine/CoreSignals.hpp>
#include <UrsineEngine/Component.hpp>

namespace example_four
{
  /**
   * The base InputComponent contains several virtual functions
   * that can be overridden to provide different behavior for
   * whatever GameObject it's attached to.
   *
   * This component class outputs a message whenever a key is pressed,
   * and if that key was the "q" key, it notifies the appropriate signal.
   */
  class BackpackInputComponent : public core::Component
  {
    public:
      BackpackInputComponent();

    private:
      void HandleKeyPress(const core::KeyCode& aCode,
                          int aMods);
  };
}

#endif
