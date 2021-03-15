#ifndef PLAYERINPUTCOMPONENT_HPP
#define PLAYERINPUTCOMPONENT_HPP

#include <UrsineEngine/CoreSignals.hpp>
#include <UrsineEngine/Component.hpp>

namespace example_four
{
  class TriangleInputComponent : public UrsineCore::Component
  {
    public:
      TriangleInputComponent();

    private:
      void HandleKeyPress(const UrsineCore::KeyCode& aCode,
                          int aMods);
  };
}

#endif
