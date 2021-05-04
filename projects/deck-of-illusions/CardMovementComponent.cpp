#include "CardMovementComponent.hpp"

using DeckOfIllusions::CardMovementComponent;

CardMovementComponent::CardMovementComponent()
  : Component()
  , mState(CardState::eIDLE)
  , mTargetPosition(0.0, 0.0, 0.0)
  , mMoveSpeed(0.0)
{
}

void CardMovementComponent::Update()
{
  switch(mState)
  {
    case CardState::eIDLE:
    {
      break;
    }
    case CardState::eMOVING_TO_POSITION:
    {
      auto vec = glm::mix(GetParent()->GetPosition(), mTargetPosition, mMoveSpeed);
      GetParent()->Translate(vec);

      if(fabs(GetParent()->GetPosition().x - mTargetPosition.x) < 0.05 &&
         fabs(GetParent()->GetPosition().y - mTargetPosition.y) < 0.05 &&
         fabs(GetParent()->GetPosition().z - mTargetPosition.z) < 0.05)
      {
        mState = CardState::eIDLE;
      }
      break;
    }
    case CardState::eBEING_DRAWN:
    {
      break;
    }
  }
}

void CardMovementComponent::MoveTo(const glm::vec3& aPosition, double aSpeed)
{
  mState = CardState::eMOVING_TO_POSITION;
  mTargetPosition = aPosition;
  mMoveSpeed = aSpeed;
}

void CardMovementComponent::SetState(const CardState& aState)
{
  switch(aState)
  {
    case CardState::eIDLE:
    {
      // Just set the state for this case; in Update(), we'll begin
      // assigning the object a random target position for a
      // "magically floating" effect.
      mState = aState;
      break;
    }
    case CardState::eMOVING_TO_POSITION:
    {
      // This state is only used in conjunction with the MoveTo
      // function; don't do anything in this case.
      break;
    }
    case CardState::eBEING_DRAWN:
    {
      // Don't know what to do here yet.
      break;
    }
  }
}
