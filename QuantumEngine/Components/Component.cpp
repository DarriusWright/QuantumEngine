#include "Component.h"
#include <Entities\GameObject.h>

RTTI_DEFINITIONS(Component)

Component::Component(GameObject * gameObject) : parent(gameObject)
{
}


Component::~Component()
{
}

void Component::update()
{

}

void Component::initialize()
{
	bool classRegistered = false;
	if (!classRegistered)
	{
		registerClass();
	}
}


void Component::registerClass()
{

}