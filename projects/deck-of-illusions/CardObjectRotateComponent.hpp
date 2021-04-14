#ifndef CARDOBJECTROTATECOMPONENT_HPP
#define CARDOBJECTROTATECOMPONENT_HPP

#include <UrsineEngine/CoreSignals.hpp>
#include <UrsineEngine/Component.hpp>

namespace DeckOfIllusions
{
  class CardObjectRotateComponent : public UrsineCore::Component
  {
    public:
      CardObjectRotateComponent();

      void Update() override;
  };
}

#endif
