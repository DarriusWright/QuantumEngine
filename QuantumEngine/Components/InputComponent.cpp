#include "InputComponent.h"


#include <Entities\GameObject.h>

RTTI_DEFINITIONS(InputComponent)

InputComponent::InputComponent(GameObject * gameObject) : Component(gameObject)
{
}


InputComponent::~InputComponent()
{
}

void InputComponent::update()
{
}