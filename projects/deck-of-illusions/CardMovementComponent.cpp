#include "CardMovementComponent.hpp"

#include <glm/gtx/string_cast.hpp>

using DeckOfIllusions::CardMovementComponent;

CardMovementComponent::CardMovementComponent()
  : Component()
  , mState(CardState::eIDLE)
  , mTargetPosition(0.0, 0.0, 0.0)
  , mIdleReferencePosition(0.0, 0.0, 0.0)
  , mMoveSpeed(0.0)
  , mIdleBuffer(0)
  , mIdlePositionInitialized(false)
{
  // Initialize random seed.
  srand(time(nullptr));

}

void CardMovementComponent::Update()
{
  switch(mState)
  {
    case CardState::eIDLE:
    {
      if(!mIdlePositionInitialized)
      {
        mIdleReferencePosition = GetParent()->GetPosition();
        mIdlePositionInitialized = true;
      }

      if(mIdleBuffer == 0)
      {
        double x = (double(rand()) / RAND_MAX) * (-1 * (rand() % 2));
        double y = (double(rand()) / RAND_MAX) * (-1 * (rand() % 2));
        double z = 0.0;//(double(rand()) / RAND_MAX) * (-1 * (rand() % 2));

        x /= 3.0;
        y /= 3.0;
        z /= 3.0;

        mTargetPosition = glm::vec3(x, y, z);
        mTargetPosition += mIdleReferencePosition;
      }

      ++mIdleBuffer;
      if(mIdleBuffer == 300)
      {
        mIdleBuffer = 0;
      }

      auto vec = glm::mix(GetParent()->GetPosition(), mTargetPosition, 0.0005);
      GetParent()->Translate(vec);
      break;
    }
    case CardState::eMOVING_TO_POSITION:
    {
      double x = (double(rand()) / RAND_MAX) * (-1 * (rand() % 2));
      double y = (double(rand()) / RAND_MAX) * (-1 * (rand() % 2));
      double z = 0.0;//(double(rand()) / RAND_MAX) * (-1 * (rand() % 2));

      x /= 3.0;
      y /= 3.0;
      z /= 3.0;

      auto temp = glm::vec3(x, y, z);
      temp += mTargetPosition;

      auto vec = glm::mix(GetParent()->GetPosition(), temp, mMoveSpeed);
      GetParent()->Translate(vec);

      if(fabs(GetParent()->GetPosition().x - mTargetPosition.x) < 0.05 &&
         fabs(GetParent()->GetPosition().y - mTargetPosition.y) < 0.05 &&
         fabs(GetParent()->GetPosition().z - mTargetPosition.z) < 0.05)
      {
        mState = CardState::eIDLE;
        mIdlePositionInitialized = false;
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
      mIdlePositionInitialized = false;
      break;
    }
  }
}
