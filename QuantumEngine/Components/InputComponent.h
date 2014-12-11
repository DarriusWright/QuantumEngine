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

};

