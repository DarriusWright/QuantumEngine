#include "TransformComponent.h"
#include "Component.h"

RTTI_DEFINITIONS(TransformComponent);


TransformComponent::TransformComponent(GameObject * gameObject) : Component(gameObject), scale(1,1,1)
{
}


TransformComponent::~TransformComponent()
{
}

void TransformComponent::update()
{

}

void TransformComponent::initialize()
{
	Component::initialize();
}

void TransformComponent::registerClass()
{
	
}


