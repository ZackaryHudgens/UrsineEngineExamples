#include "CameraInputComponent.hpp"

#include <UrsineEngine/Camera.hpp>
#include <UrsineEngine/GameObject.hpp>
#include <UrsineEngine/MeshComponent.hpp>
#include <UrsineEngine/Shader.hpp>

#include <iostream>

using UrsineRenderer::Camera;

using example_five::CameraInputComponent;

CameraInputComponent::CameraInputComponent()
  : Component()
  , mYaw(0.0)
  , mPitch(0.0)
  , mMouseXPos(0.0)
  , mMouseYPos(0.0)
  , mMouseInitialized(false)
{
  UrsineCore::MouseMoved.Connect(*this, [this](double aXOffset,
                                               double aYOffset)
  {
    this->HandleMouseMoved(aXOffset, aYOffset);
  });

  UrsineCore::MouseEnteredOrLeft.Connect(*this, [this](bool aEntered)
  {
    this->HandleMouseEnteredOrLeft(aEntered);
  });
}

void CameraInputComponent::Update()
{
  // Use the yaw and pitch values to create a direction vector.
  glm::vec3 direction(cos(glm::radians(mYaw) * cos(glm::radians(mPitch))),
                      sin(glm::radians(mPitch)),
                      sin(glm::radians(mYaw)) * cos(glm::radians(mPitch)));

  Camera* cam = dynamic_cast<Camera*>(GetParent());
  if(cam != nullptr)
  {
    cam->LookAt(glm::normalize(direction));
  }
}

void CameraInputComponent::HandleMouseMoved(double aXOffset,
                                            double aYOffset)
{
  if(mMouseInitialized)
  {
    mMouseXPos = aXOffset;
    mMouseYPos = aYOffset;
    mMouseInitialized = false;
  }

  // Determine the offset relative to the previous position.
  float xOffset = aXOffset - mMouseXPos;
  float yOffset = mMouseYPos - aYOffset;

  // Apply camera sensitivity.
  xOffset *= 0.1;
  yOffset *= 0.1;

  // Set the new mouse coordinates.
  mMouseXPos = aXOffset;
  mMouseYPos = aYOffset;

  // Add the relative offset to the yaw and pitch.
  mYaw += xOffset;
  mPitch += yOffset;

  // Constrain the pitch value.
  mPitch = std::min(mPitch, 70.0);
  mPitch = std::max(mPitch, -70.0);
}

void CameraInputComponent::HandleMouseEnteredOrLeft(bool aEntered)
{
  mMouseInitialized = aEntered;
}
