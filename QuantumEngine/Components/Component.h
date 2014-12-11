#pragma once
#include <RTTI.h>

class GameObject;
class Component : public RTTI
{
	RTTI_DECLARATIONS(Component, RTTI);

public:
	ENGINE_SHARED Component(GameObject * gameObject);
	ENGINE_SHARED ~Component();
	ENGINE_SHARED virtual void update();

private:
	GameObject * parent;
};

