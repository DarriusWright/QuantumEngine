#include "TransformComponent.h"
#include "Component.h"

RTTI_DEFINITIONS(TransformComponent);


TransformComponent::TransformComponent(GameObject * gameObject) : Component(gameObject)
{
}


TransformComponent::~TransformComponent()
{
}

void TransformComponent::update()
{
}
