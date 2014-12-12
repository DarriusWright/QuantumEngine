#pragma once

#include "Component.h"
class GameObject;
class InputComponent : public Component
{
	RTTI_DECLARATIONS(InputComponent, Component);

public:
	ENGINE_SHARED InputComponent(GameObject * gameObject);
	ENGINE_SHARED ~InputComponent();
	ENGINE_SHARED virtual void update()override;
	ENGINE_SHARED virtual void initialize()override;
protected:
	ENGINE_SHARED virtual void registerClass()override;

};

