#include "PlayerInputComponent.hpp"

#include "PlayerSignals.hpp"

#include <iostream>

using example_three::PlayerInputComponent;

PlayerInputComponent::PlayerInputComponent()
  : Component()
{
  core::KeyPressed.Connect(*this, [this](const core::KeyCode& aCode,
                                         int aMods)
  {
    this->HandleKeyPress(aCode, aMods);
  });
}

void PlayerInputComponent::HandleKeyPress(const core::KeyCode& aCode,
                                          int aMods)
{
  switch(aCode)
  {
    case core::KeyCode::eKEY_UNKNOWN:
    {
      std::cout << "You pressed an unrecognized key!" << std::endl;
      break;
    }
    case core::KeyCode::eKEY_Q:
    {
      /**
       * The key was the Q key, so we notify the QPressed signal, passing this
       * component's parent as the argument. Now, any Observers connected to
       * the QPressed signal are made aware that this player just pressed Q.
       */
      auto player = dynamic_cast<PlayerObject*>(GetParent());
      if(player != nullptr)
      {
        QPressed.Notify(player);
      }

      // No break; still output the message.
    }
    default:
    {
      std::cout << "You pressed the "
                << core::GetKeyName(aCode)
                << " key!"
                << std::endl;
      break;
    }
  }
}
