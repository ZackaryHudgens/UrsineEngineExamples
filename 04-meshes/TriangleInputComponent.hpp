#ifndef TRIANGLEINPUTCOMPONENT_HPP
#define TRIANGLEINPUTCOMPONENT_HPP

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
      void HandleKeyRepeat(const UrsineCore::KeyCode& aCode,
                           int aMods);
  };
}

#endif
