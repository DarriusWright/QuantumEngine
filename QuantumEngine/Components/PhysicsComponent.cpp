#include "PhysicsComponent.h"
#include "Component.h"
#include <Entities\GameObject.h>

RTTI_DEFINITIONS(PhysicsComponent)

PhysicsComponent::PhysicsComponent(GameObject * gameObject) : Component(gameObject)
{
}


PhysicsComponent::~PhysicsComponent()
{
}


void PhysicsComponent::initialize()
{
	Component::initialize();
}

void PhysicsComponent::registerClass()
{

}

void PhysicsComponent::update()
{

}