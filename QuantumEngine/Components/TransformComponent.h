#pragma once

#include "Component.h"
class GameObject;
class TransformComponent : public Component
{
	RTTI_DECLARATIONS(TransformComponent , Component);

public:
	ENGINE_SHARED TransformComponent(GameObject * gameObject);
	ENGINE_SHARED ~TransformComponent();
	ENGINE_SHARED virtual void update() override;
};

