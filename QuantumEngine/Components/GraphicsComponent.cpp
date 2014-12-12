#include "GraphicsComponent.h"

RTTI_DEFINITIONS(GraphicsComponent)

GraphicsComponent::GraphicsComponent(GameObject * gameObject) : Component(gameObject)
{
}


GraphicsComponent::~GraphicsComponent()
{
}

void GraphicsComponent::update()
{

}

void GraphicsComponent::draw()
{

}

void GraphicsComponent::initialize()
{
	Component::initialize();
}

void GraphicsComponent::registerClass()
{

}