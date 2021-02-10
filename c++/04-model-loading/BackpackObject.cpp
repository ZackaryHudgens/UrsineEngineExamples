#include "BackpackObject.hpp"

#include <UrsineEngine/ModelComponent.hpp>

#include "BackpackInputComponent.hpp"

using example_four::BackpackObject;
using example_four::BackpackInputComponent;

BackpackObject::BackpackObject()
  : GameObject()
{
  auto model = std::make_unique<core::ModelComponent>();
  model->LoadModel("backpack.obj");

  AddComponent(std::move(model));

  auto input = std::make_unique<BackpackInputComponent>();
  AddComponent(std::move(input));
}
