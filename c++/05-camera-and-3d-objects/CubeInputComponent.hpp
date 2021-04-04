#ifndef CUBEINPUTCOMPONENT_HPP
#define CUBEINPUTCOMPONENT_HPP

#include <UrsineEngine/CoreSignals.hpp>
#include <UrsineEngine/Component.hpp>

namespace example_five
{
  class CubeInputComponent : public UrsineCore::Component
  {
    public:
      CubeInputComponent();

    private:
      void HandleKeyPress(const UrsineCore::KeyCode& aCode,
                          int aMods);
      void HandleKeyRepeat(const UrsineCore::KeyCode& aCode,
                           int aMods);
  };
}

#endif
