#pragma once

#include "Component.h"
class GameObject;
class PhysicsComponent : public Component
{
	RTTI_DECLARATIONS(PhysicsComponent, Component);

public:
	ENGINE_SHARED PhysicsComponent(GameObject * gameObject);
	ENGINE_SHARED ~PhysicsComponent();
	ENGINE_SHARED virtual void update()override;
	ENGINE_SHARED virtual void initialize()override;
	
protected:

	ENGINE_SHARED virtual void registerClass()override;

};

