#ifndef CAMERAINPUTCOMPONENT_HPP
#define CAMERAINPUTCOMPONENT_HPP

#include <UrsineEngine/CoreSignals.hpp>
#include <UrsineEngine/Component.hpp>

namespace example_five
{
  class CameraInputComponent : public UrsineCore::Component
  {
    public:
      CameraInputComponent();

      void Update() override;

    private:
      void HandleMouseMoved(double aXOffset,
                            double aYOffset);
      void HandleMouseEnteredOrLeft(bool aEntered);

      double mYaw;
      double mPitch;
      double mMouseXPos;
      double mMouseYPos;

      bool mMouseInitialized;
  };
}

#endif
