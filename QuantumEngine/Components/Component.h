#pragma once
#include <RTTI.h>
#include <Scripting\LuaStateManager.h>

class GameObject;
class Component : public RTTI
{
	RTTI_DECLARATIONS(Component, RTTI);

public:
	ENGINE_SHARED Component(GameObject * gameObject);
	ENGINE_SHARED ~Component();
	ENGINE_SHARED virtual void initialize();
	ENGINE_SHARED virtual void update();

protected:
	ENGINE_SHARED virtual void registerClass();

	GameObject * parent;

};

