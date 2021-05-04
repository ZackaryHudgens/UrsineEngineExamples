#ifndef CARDMOVEMENTCOMPONENT_HPP
#define CARDMOVEMENTCOMPONENT_HPP

#include <UrsineEngine/Component.hpp>
#include <UrsineEngine/GameObject.hpp>

using UrsineCore::Component;

namespace DeckOfIllusions
{
  enum class CardState
  {
    eIDLE,
    eMOVING_TO_POSITION,
    eBEING_DRAWN
  };

  class CardMovementComponent : public Component
  {
    public:
      CardMovementComponent();

      void Update() override;

      void MoveTo(const glm::vec3& aPosition, double aSpeed);

      void SetState(const CardState& aState);
      CardState GetState() const { return mState; }

    private:
      CardState mState;

      glm::vec3 mTargetPosition;

      double mMoveSpeed;
  };
}

#endif
